// CAN System

#ifndef DEVELOPMENT_H
#define DEVELOPMENT_H

#include <stdio.h>
#include <stdint.h>

// Signal: pedal_voltage
typedef struct pedal_voltage {
    char* name;
    uint8_t start;
    uint8_t length;
    float scale;
    float offset;
    char* unit;
    char* comment;
    float min_value;
    float max_value;
    char* type;
    char* byte_order;
} pedal_voltage;


// pedal_mod Module
typedef struct pedal_msg {
    char* name;
    uint8_t id;
    uint8_t prio;
    uint8_t dlc;
    pedal_voltage pedal_voltage;
} pedal_msg;


static pedal_msg pedal_msg_instance = {
    .name = "mensagem do pedal",
    .id = 1,
    .prio = 1,
    .dlc = 8,
    .pedal_voltage = {
        .name = "tensão do pedal",
        .start = 0,
        .length = 9,
        .scale = 0.00644,
        .offset = 0.0,
        .unit = "V",
        .comment = "Voltage from the pedal sensor (0.00 to 3.3 V)",
        .min_value = 0.0,
        .max_value = 3.3,
        .type = "unsigned",
        .byte_order = "little_endian",
    },
};


#endif // DEVELOPMENT_H
