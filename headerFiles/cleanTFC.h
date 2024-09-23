// CAN System

#ifndef CLEANTFC_H
#define CLEANTFC_H

#include <stdio.h>
#include <stdint.h>

// Signal: pedal_voltage
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

// PedalCAN Module
typedef struct pedal_message {
    char* name;
    uint8_t id;
    uint8_t prio;
    struct pedal_voltage pedal_voltage;
} pedal_message;


// Signal: input_voltage
typedef struct input_voltage {
    uint8_t start;
    uint8_t length;
    float scale;
    float offset;
    char* unit;
    char* comment;
    char* type;
    char* byte_order;
} input_voltage;

// Signal: current_motor
typedef struct current_motor {
    uint8_t start;
    uint8_t length;
    float scale;
    float offset;
    char* unit;
    char* comment;
    char* type;
    char* byte_order;
} current_motor;

// Signal: current_in
typedef struct current_in {
    uint8_t start;
    uint8_t length;
    float scale;
    float offset;
    char* unit;
    char* comment;
    char* type;
    char* byte_order;
} current_in;

// Signal: duty_cycle
typedef struct duty_cycle {
    uint8_t start;
    uint8_t length;
    float scale;
    float offset;
    char* unit;
    char* comment;
    char* type;
    char* byte_order;
} duty_cycle;

// Signal: watt_hours_used
typedef struct watt_hours_used {
    uint8_t start;
    uint8_t length;
    float scale;
    float offset;
    char* unit;
    char* comment;
    char* type;
    char* byte_order;
} watt_hours_used;

// Signal: ms_today_setup
typedef struct ms_today_setup {
    uint8_t start;
    uint8_t length;
    float scale;
    float offset;
    char* unit;
    char* comment;
    char* type;
    char* byte_order;
} ms_today_setup;

// Signal: speed_meters_per_sec
typedef struct speed_meters_per_sec {
    uint8_t start;
    uint8_t length;
    float scale;
    float offset;
    char* unit;
    char* comment;
    char* type;
    char* byte_order;
} speed_meters_per_sec;

// VescCAN Module
typedef struct vesc_data {
    char* name;
    uint8_t id;
    uint8_t prio;
    struct input_voltage input_voltage;
    struct current_motor current_motor;
    struct current_in current_in;
    struct duty_cycle duty_cycle;
    struct watt_hours_used watt_hours_used;
    struct ms_today_setup ms_today_setup;
    struct speed_meters_per_sec speed_meters_per_sec;
} vesc_data;


// Signal: unknown_signal
typedef struct unknown_signal {
    uint8_t start;
    uint8_t length;
    float scale;
    float offset;
    char* unit;
    char* comment;
    char* type;
    char* byte_order;
} unknown_signal;

// FlowMeterCAN Module
typedef struct flow_meter_data {
    char* name;
    uint8_t id;
    uint8_t prio;
    struct unknown_signal unknown_signal;
} flow_meter_data;


// Signal: ErrorFlag
typedef struct ErrorFlag {
    uint8_t start;
    uint8_t length;
    float scale;
    float offset;
    char* unit;
    char* comment;
    char* type;
    char* byte_order;
} ErrorFlag;

// Signal: Ambient_T
typedef struct Ambient_T {
    uint8_t start;
    uint8_t length;
    float scale;
    float offset;
    char* unit;
    char* comment;
    char* type;
    char* byte_order;
} Ambient_T;

// Signal: Fuelcell_out_V
typedef struct Fuelcell_out_V {
    uint8_t start;
    uint8_t length;
    float scale;
    float offset;
    char* unit;
    char* comment;
    char* type;
    char* byte_order;
} Fuelcell_out_V;

// Signal: H2_leak_V
typedef struct H2_leak_V {
    uint8_t start;
    uint8_t length;
    float scale;
    float offset;
    char* unit;
    char* comment;
    char* type;
    char* byte_order;
} H2_leak_V;

// Signal: Fuelcell_T
typedef struct Fuelcell_T {
    uint8_t start;
    uint8_t length;
    float scale;
    float offset;
    char* unit;
    char* comment;
    char* type;
    char* byte_order;
} Fuelcell_T;

// Signal: Fuelcell_I_high
typedef struct Fuelcell_I_high {
    uint8_t start;
    uint8_t length;
    float scale;
    float offset;
    char* unit;
    char* comment;
    char* type;
    char* byte_order;
} Fuelcell_I_high;

// Signal: Fuelcell_I_low
typedef struct Fuelcell_I_low {
    uint8_t start;
    uint8_t length;
    float scale;
    float offset;
    char* unit;
    char* comment;
    char* type;
    char* byte_order;
} Fuelcell_I_low;

// Signal: Battery_V_aux
typedef struct Battery_V_aux {
    uint8_t start;
    uint8_t length;
    float scale;
    float offset;
    char* unit;
    char* comment;
    char* type;
    char* byte_order;
} Battery_V_aux;

// FuelCellCAN Module
typedef struct fuel_cell_data {
    char* name;
    uint8_t id;
    uint8_t prio;
    struct ErrorFlag ErrorFlag;
    struct Ambient_T Ambient_T;
    struct Fuelcell_out_V Fuelcell_out_V;
    struct H2_leak_V H2_leak_V;
    struct Fuelcell_T Fuelcell_T;
    struct Fuelcell_I_high Fuelcell_I_high;
    struct Fuelcell_I_low Fuelcell_I_low;
    struct Battery_V_aux Battery_V_aux;
} fuel_cell_data;


// Signal: unknown_signal
typedef struct unknown_signal {
    uint8_t start;
    uint8_t length;
    float scale;
    float offset;
    char* unit;
    char* comment;
    char* type;
    char* byte_order;
} unknown_signal;

// GpsCAN Module
typedef struct gps_data {
    char* name;
    uint8_t id;
    uint8_t prio;
    struct unknown_signal unknown_signal;
} gps_data;



#endif // CLEANTFC_H
