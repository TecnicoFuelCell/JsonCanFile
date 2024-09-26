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
    pedal_voltage pedal_voltage;
} pedal_message;


static pedal_message pedal_message_instance = {
    .name = "tensão do pedal",
    .id = 1,
    .prio = 1,
    .pedal_voltage = {
        .start = 0,
        .length = 12,
        .offset = 0.0,
        .unit = "V",
        .comment = "Voltage from the pedal sensor (0.00 to ? V)",
        .min_value = 0.0,
        .max_value = 20,
        .type = "unsigned",
        .byte_order = "little_endian",
    },
};

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
    input_voltage input_voltage;
    current_motor current_motor;
    current_in current_in;
    duty_cycle duty_cycle;
    watt_hours_used watt_hours_used;
    ms_today_setup ms_today_setup;
    speed_meters_per_sec speed_meters_per_sec;
} vesc_data;


static vesc_data vesc_data_instance = {
    .name = "vesc_data",
    .id = 2,
    .prio = 1,
    .input_voltage = {
        .start = 0,
        .length = 16,
        .scale = 1.0,
        .offset = 0.0,
        .unit = "V",
        .comment = "Input voltage to the VESC",
        .type = "unsigned",
        .byte_order = "little_endian",
    },
    .current_motor = {
        .start = 16,
        .length = 16,
        .scale = 0.1,
        .offset = 0.0,
        .unit = "A",
        .comment = "Current drawn by the motor",
        .type = "signed",
        .byte_order = "little_endian",
    },
    .current_in = {
        .start = 32,
        .length = 16,
        .scale = 0.1,
        .offset = 0.0,
        .unit = "A",
        .comment = "Input current to the VESC",
        .type = "signed",
        .byte_order = "little_endian",
    },
    .duty_cycle = {
        .start = 48,
        .length = 16,
        .scale = 0.001,
        .offset = 0.0,
        .unit = "%",
        .comment = "Motor duty cycle",
        .type = "unsigned",
        .byte_order = "little_endian",
    },
    .watt_hours_used = {
        .start = 64,
        .length = 32,
        .scale = 1.0,
        .offset = 0.0,
        .unit = "Wh",
        .comment = "Total watt-hours used",
        .type = "unsigned",
        .byte_order = "little_endian",
    },
    .ms_today_setup = {
        .start = 112,
        .length = 32,
        .scale = 1.0,
        .offset = 0.0,
        .unit = "ms",
        .comment = "Milliseconds since today's setup",
        .type = "unsigned",
        .byte_order = "little_endian",
    },
    .speed_meters_per_sec = {
        .start = 144,
        .length = 16,
        .scale = 0.1,
        .offset = 0.0,
        .unit = "m/s",
        .comment = "Speed in meters per second",
        .type = "unsigned",
        .byte_order = "little_endian",
    },
};

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
    unknown_signal unknown_signal;
} flow_meter_data;


static flow_meter_data flow_meter_data_instance = {
    .name = "flow_meter_data",
    .id = 3,
    .prio = 1,
    .unknown_signal = {
        .start = 0,
        .length = 32,
        .scale = 1.0,
        .offset = 0.0,
        .unit = "",
        .comment = "Unknown signal for flow meter",
        .type = "unsigned",
        .byte_order = "little_endian",
    },
};

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
    ErrorFlag ErrorFlag;
    Ambient_T Ambient_T;
    Fuelcell_out_V Fuelcell_out_V;
    H2_leak_V H2_leak_V;
    Fuelcell_T Fuelcell_T;
    Fuelcell_I_high Fuelcell_I_high;
    Fuelcell_I_low Fuelcell_I_low;
    Battery_V_aux Battery_V_aux;
} fuel_cell_data;


static fuel_cell_data fuel_cell_data_instance = {
    .name = "fuel_cell_data",
    .id = 4,
    .prio = 1,
    .ErrorFlag = {
        .start = 0,
        .length = 8,
        .scale = 1.0,
        .offset = 0.0,
        .unit = "",
        .comment = "Fuel cell error flag",
        .type = "unsigned",
        .byte_order = "little_endian",
    },
    .Ambient_T = {
        .start = 8,
        .length = 16,
        .scale = 0.1,
        .offset = 0.0,
        .unit = "°C",
        .comment = "Ambient temperature",
        .type = "unsigned",
        .byte_order = "little_endian",
    },
    .Fuelcell_out_V = {
        .start = 24,
        .length = 16,
        .scale = 0.1,
        .offset = 0.0,
        .unit = "V",
        .comment = "Fuel cell output voltage",
        .type = "unsigned",
        .byte_order = "little_endian",
    },
    .H2_leak_V = {
        .start = 40,
        .length = 16,
        .scale = 0.1,
        .offset = 0.0,
        .unit = "V",
        .comment = "Hydrogen leak voltage",
        .type = "unsigned",
        .byte_order = "little_endian",
    },
    .Fuelcell_T = {
        .start = 56,
        .length = 16,
        .scale = 0.1,
        .offset = 0.0,
        .unit = "°C",
        .comment = "Fuel cell temperature",
        .type = "unsigned",
        .byte_order = "little_endian",
    },
    .Fuelcell_I_high = {
        .start = 72,
        .length = 8,
        .scale = 1.0,
        .offset = 0.0,
        .unit = "A",
        .comment = "Fuel cell current high byte",
        .type = "unsigned",
        .byte_order = "little_endian",
    },
    .Fuelcell_I_low = {
        .start = 80,
        .length = 8,
        .scale = 1.0,
        .offset = 0.0,
        .unit = "A",
        .comment = "Fuel cell current low byte",
        .type = "unsigned",
        .byte_order = "little_endian",
    },
    .Battery_V_aux = {
        .start = 88,
        .length = 16,
        .scale = 0.1,
        .offset = 0.0,
        .unit = "V",
        .comment = "Auxiliary battery voltage",
        .type = "unsigned",
        .byte_order = "little_endian",
    },
};

// Signal: unknown_signal2
typedef struct unknown_signal2 {
    uint8_t start;
    uint8_t length;
    float scale;
    float offset;
    char* unit;
    char* comment;
    char* type;
    char* byte_order;
} unknown_signal2;


// GpsCAN Module
typedef struct gps_data {
    char* name;
    uint8_t id;
    uint8_t prio;
    unknown_signal2 unknown_signal2;
} gps_data;


static gps_data gps_data_instance = {
    .name = "gps_data",
    .id = 5,
    .prio = 1,
    .unknown_signal2 = {
        .start = 0,
        .length = 32,
        .scale = 1.0,
        .offset = 0.0,
        .unit = "",
        .comment = "Placeholder for GPS CAN signal",
        .type = "unsigned",
        .byte_order = "little_endian",
    },
};


#endif // CLEANTFC_H
