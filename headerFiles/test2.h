// CAN System

#ifndef TEST2_H
#define TEST2_H

#include <stdio.h>
#include <stdint.h>

// PedalCAN
typedef struct pedal_voltage {
    char* name;
    uint8_t id;
    uint8_t prio;
} pedal_voltage;



// pedal_voltage SIGNALS
typedef struct pedal_voltage {
    uint8_t start;
    uint8_t length;
    float offset;
    char* unit;
    char* comment;
    float min_value;
    uint8_t max_value;
    char* type;
    char* byte_order;
} pedal_voltage;


#endif // TEST2_H
