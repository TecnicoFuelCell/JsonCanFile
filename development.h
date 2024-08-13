//CAN System

#ifndef DEVELOPMENT_H
#define DEVELOPMENT_H

#include <stdio.h>
#include <stdint.h> // uint8_t, uint16_t, uint32_t, etc.

// pedal_mod Module
typedef struct pedal_msg {
    uint8_t prio;
    uint8_t id;
    uint8_t dlc;

} pedal_msg;

// pedal_msg SIGNALS
typedef struct pedal_voltage {
    uint16_t start;
    uint16_t length;
    float scale;
    uint16_t offset;

} pedal_voltage;

#endif // DEVELOPMENT_H
