import json, os, re

def check_empty_dict(dictionary, key_name):
    value = dictionary.get(key_name, {})
    if not value:
        print(f"[ERROR] Failed to retrieve data for '{key_name}'")
    return value


def map_json_type_to_c(json_value):
    # maps Python data types to C equivalents
    if isinstance(json_value, int):
        # for integers, checks the range to determine the best 
        # # C data type (avoids using uint16 or uint32 if not needed)
        if 0 <= json_value <= 255:
            return "uint8_t"
        elif 0 <= json_value <= 65535:
            return "uint16_t"
        else:
            return "uint32_t"
    elif isinstance(json_value, float):
        return "float"
    elif isinstance(json_value, str):
        return "char*"
    elif isinstance(json_value, dict):
        return "struct"
    elif isinstance(json_value, list):
        if all(isinstance(item, int) for item in json_value):
            return "int[]"
        elif all(isinstance(item, float) for item in json_value):
            return "float[]"
        else:
            return "void*"
    else:
        return "void*"  # default for unknown -- bit problematic if it reaches here


def add_signal_struct(signal_name, signal_content):
    struct_signal = f"// Signal: {signal_name}\n"
    struct_signal += f"typedef struct {signal_name} {{\n"
    
    for signal_field_name, signal_field_value in signal_content.items():
        c_type = map_json_type_to_c(signal_field_value)
        struct_signal += f"    {c_type} {signal_field_name};\n"
    
    struct_signal += f"}} {signal_name};\n"
    return struct_signal


def add_header_struct(module_name, msg_name, msg_content, signals):
    struct_msg = f"// {module_name} Module\n"
    struct_msg += f"typedef struct {msg_name} {{\n"
    # adds every field that is not a struct
    for field_name, field_value in msg_content.items():
        if field_name != 'signals':
            c_type = map_json_type_to_c(field_value)
            struct_msg += f"    {c_type} {field_name};\n"
    # adds all signal structs to the message struct
    for signal_name in signals:
        struct_msg += f"    struct {signal_name} {signal_name};\n"
    
    struct_msg += f"}} {msg_name};\n\n"
    return struct_msg


def json_to_header(json_data):
    struct_definitions = []
    data = json.loads(json_data)
    modules = check_empty_dict(data, 'modules').items()
    # the first for will just have pedal_mod, but if there is
    # more than one module, this is useful
    for module_name, module_content in modules:
        # handles "messages" layer 
        # -> exists in TFC.json, defaults to module_content if it doesn't exist
        messages = module_content.get('messages', module_content)
        for msg_name, msg_content in messages.items():
            signals = check_empty_dict(msg_content, 'signals')
            for signal_name, signal_content in signals.items():
                # creates a new struct for every signal in "signals"
                struct_signal = add_signal_struct(signal_name, signal_content)
                struct_definitions.append(struct_signal)
            # creates the message struct (with all signal structs)
            struct_msg = add_header_struct(module_name, msg_name, msg_content, signals)
            struct_definitions.append(struct_msg)                       
    header_content = "\n".join(struct_definitions)
    return header_content
            

def convert_json_to_header(input_json_file, output_header_file):
    with open(input_json_file, 'r') as json_file:
        json_data = json_file.read()
    header_content = json_to_header(json_data)
    
    base_name = os.path.splitext(os.path.basename(output_header_file))[0]
    header_guard = re.sub(r'\W+', '_', base_name).upper() + "_H"
    
    header_content = f"""// CAN System

#ifndef {header_guard}
#define {header_guard}

#include <stdio.h>
#include <stdint.h>

{header_content}

#endif // {header_guard}
"""
    with open(output_header_file, 'w') as header_file:
        header_file.write(header_content)
    print(f"Header file '{output_header_file}' has been created.")


convert_json_to_header('jsonFiles/development.json', 'headerFiles/test.h')
convert_json_to_header('jsonFiles/cleanTFC.json', 'headerFiles/cleanTFC.h')
convert_json_to_header('jsonFiles/multipleSignals.json', 'headerFiles/multipleSignals.h')
convert_json_to_header('jsonFiles/multipleMessages.json', 'headerFiles/multiple_messages.h')

