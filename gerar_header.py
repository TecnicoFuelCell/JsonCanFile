import json

# Function to map JSON data types to C types
def get_c_type(signal):
    length = signal['length']
    c_type = "uint8_t"  # Default to smallest type
    if length <= 8:
        c_type = "uint8_t" if signal['type'] == 'unsigned' else "int8_t"
    elif length <= 16:
        c_type = "uint16_t" if signal['type'] == 'unsigned' else "int16_t"
    elif length <= 32:
        c_type = "uint32_t" if signal['type'] == 'unsigned' else "int32_t"
    elif length <= 64:
        c_type = "uint64_t" if signal['type'] == 'unsigned' else "int64_t"
    return c_type

# Function to generate C structs
def generate_structs(data):
    output = []

    for module_name, module in data["modules"].items():
        output.append(f"// {module_name} Module\n")
        output.append(f"typedef struct {module_name}_t {{\n")
        for msg_name, msg in module["messages"].items():
            output.append(f"    // {msg_name} message\n")
            for sig_name, signal in msg["signals"].items():
                c_type = get_c_type(signal)
                comment = signal.get("comment", "")
                output.append(f"    {c_type} {sig_name}; // {comment}\n")
        output.append(f"}} {module_name}_t;\n\n")
    
    return "".join(output)

# Function to create the header file
def create_header_file(json_file, output_file):
    with open(json_file, 'r') as f:
        data = json.load(f)
    
    structs = generate_structs(data)
    
    header_guard = output_file.upper().replace('.', '_')
    
    header_content = f"#ifndef {header_guard}\n#define {header_guard}\n\n"
    header_content += "#include <stdint.h>\n\n"
    header_content += structs
    header_content += "#endif // " + header_guard + "\n"
    
    with open(output_file, 'w') as f:
        f.write(header_content)

# Example usage:
create_header_file('TFC.json', 'can_structs.h')
