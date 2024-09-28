import json, os, re
import argparse

## -------------------- AUXILIARY FUNCTIONS -------------------- ##

def check_empty_dict(dictionary, key_name, default={}):
    # checks if the key we're trying to get exists
    # prints to console if it doesn't and defaults to default arg if provided
    value = dictionary.get(key_name, default)
    if not value:
        print(f"[ERROR] Failed to retrieve data for '{key_name}'")
    return value


def map_json_type_to_c(json_value):
    # maps the variables in json to C data types
    if isinstance(json_value, int):
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
        return "void*"


def c_value_repr(value):
    # simplification to represent any value 
    # without worrying if it's a string
    if isinstance(value, str):
        return f'"{value}"'
    else:
        return str(value)


def add_header_struct(module_name, msg_name, msg_content, signals):
    struct_msg = f"// {module_name} Module\n"
    struct_msg += f"typedef struct {msg_name} {{\n"

    # generates every field for the message that isn't a signal
    for field_name, field_value in msg_content.items():
        if field_name != 'signals':
            c_type = map_json_type_to_c(field_value)
            struct_msg += f"    {c_type} {field_name};\n"

    # declares every signal structure inside the message structure (nested)
    for signal_name, signal_content in signals.items():
        struct_msg += f"    struct {{\n"
        for signal_field_name, signal_field_value in signal_content.items():
            c_type = map_json_type_to_c(signal_field_value)
            struct_msg += f"        {c_type} {signal_field_name};\n"
        struct_msg += f"    }} {signal_name};\n"

    struct_msg += f"}} {msg_name};\n\n\n"

    # generates a static initialization for the full message
    msg_init = f"static {msg_name} {msg_name}_instance = {{\n"
    for field_name, field_value in msg_content.items():
        if field_name != "signals":
            msg_init += f"    .{field_name} = {c_value_repr(field_value)},\n"
        else:
            # initializes signals
            for signal_name, signal_content in signals.items():
                msg_init += f"    .{signal_name} = {{\n"
                for signal_field_name, signal_field_value in signal_content.items():
                    msg_init += f"        .{signal_field_name} = {c_value_repr(signal_field_value)},\n"
                msg_init += "    },\n"
    msg_init += "};\n"

    return struct_msg + msg_init


def json_to_header(json_data):
    struct_definitions = []
    data = json.loads(json_data)
    modules = check_empty_dict(data, 'modules').items()
    
    for module_name, module_content in modules:
        # some json files (e.g. TFC.json) have an extra layer of "messages"
        # if it doesn't exist, we simplify default to the previous content
        messages = check_empty_dict(module_content, 'messages', module_content)
        for msg_name, msg_content in messages.items():
            # appends all signal structs first
            signals = check_empty_dict(msg_content, 'signals')
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

if __name__ == "__main__":
    arg_parser = argparse.ArgumentParser(description='Converts JSON files to C header files')
    arg_parser.add_argument('json_file', type=str, help='Path to the JSON file')
    arg_parser.add_argument('header_file', type=str, help='Path to the header file')
    args = arg_parser.parse_args()
    convert_json_to_header(args.json_file, args.header_file)
