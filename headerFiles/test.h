// CAN System

#ifndef TEST_H
#define TEST_H

#include <stdio.h>
#include <stdint.h>

// pedal_mod
typedef struct pedal_msg {
    char* name;
    uint8_t id;
    uint8_t prio;
    uint8_t dlc;
} pedal_msg;



// pedal_msg SIGNALS
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


#endif // TEST_H
