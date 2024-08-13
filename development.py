import json

def convert_json_to_header(json_data):
    header_template = """//CAN System

#ifndef DEVELOPMENT_H
#define DEVELOPMENT_H

#include <stdio.h>
#include <stdint.h> // uint8_t, uint16_t, uint32_t, etc.

// pedal_mod Module
typedef struct pedal_msg {{
    uint8_t prio;
    uint8_t id;
    uint8_t dlc;

}} pedal_msg;

// pedal_msg SIGNALS
typedef struct pedal_voltage {{
    uint16_t start;
    uint16_t length;
    float scale;
    uint16_t offset;

}} pedal_voltage;

#endif // DEVELOPMENT_H
"""

    # Load the JSON data
    data = json.loads(json_data)

    # Extract module and signal information
    module = data.get('modules', {}).get('pedal_mod', {})
    pedal_msg = module.get('pedal_msg', {})
    signals = pedal_msg.get('signals', {})

    if signals.get('pedal_voltage'):
        signal = signals['pedal_voltage']
        start = signal.get('start', 0)
        length = signal.get('length', 0)
        scale = signal.get('scale', 0.0)
        offset = signal.get('offset', 0.0)

        # Format the header content
        header = header_template.format(
            start=start,
            length=length,
            scale=scale,
            offset=offset
        )

        return header
    else:
        return "No pedal_voltage signal found."

# Read JSON file
json_file_path = 'development.json'
with open(json_file_path, 'r') as json_file:
    json_data = json_file.read()

# Convert JSON data to header file content
header_content = convert_json_to_header(json_data)

# Write the header file
header_file_path = 'development.h'
with open(header_file_path, 'w') as header_file:
    header_file.write(header_content)

print(f"Header file '{header_file_path}' has been created.")
