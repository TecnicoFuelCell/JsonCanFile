// CAN System

#ifndef MULTIPLESIGNALS_H
#define MULTIPLESIGNALS_H

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

// Signal: pedal_position
typedef struct pedal_position {
    char* name;
    uint8_t start;
    uint8_t length;
    float scale;
    float offset;
    char* unit;
    char* comment;
    char* blablabla;
    float min_value;
    float max_value;
} pedal_position;

// pedal_mod Module
typedef struct pedal_msg {
    char* name;
    uint8_t id;
    uint8_t prio;
    uint8_t dlc;
    struct pedal_voltage pedal_voltage;
    struct pedal_position pedal_position;
} pedal_msg;



#endif // MULTIPLESIGNALS_H
