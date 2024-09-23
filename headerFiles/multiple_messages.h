// CAN System

#ifndef MULTIPLE_MESSAGES_H
#define MULTIPLE_MESSAGES_H

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
    struct pedal_voltage pedal_voltage;
} pedal_msg;


// Signal: signal1
typedef struct signal1 {
    char* name;
    uint8_t start;
    uint8_t length;
    float scale;
    char* unit;
    char* comment;
} signal1;

// pedal_mod Module
typedef struct blabla_msg {
    char* name;
    uint8_t id;
    uint8_t prio;
    uint8_t dlc;
    struct signal1 signal1;
} blabla_msg;



#endif // MULTIPLE_MESSAGES_H
