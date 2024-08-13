#ifndef CAN_STRUCTS_H
#define CAN_STRUCTS_H

#include <stdint.h>

// PedalCAN Module
typedef struct PedalCAN_t {
    // pedal_voltage message
    uint16_t pedal_voltage; // Voltage from the pedal sensor (0.00 to ? V)
} PedalCAN_t;

// VescCAN Module
typedef struct VescCAN_t {
    // vesc_data message
    uint16_t input_voltage; // Input voltage to the VESC
    int16_t current_motor; // Current drawn by the motor
    int16_t current_in; // Input current to the VESC
    uint16_t duty_cycle; // Motor duty cycle
    uint32_t watt_hours_used; // Total watt-hours used
    uint8_t fault_code; // Error code from the VESC
    uint32_t ms_today_setup; // Milliseconds since today's setup
    uint16_t speed_meters_per_sec; // Speed in meters per second
} VescCAN_t;

// FlowMeterCAN Module
typedef struct FlowMeterCAN_t {
    // flow_meter_data message
    uint32_t unknown_signal; // Unknown signal for flow meter
} FlowMeterCAN_t;

// FuelCellCAN Module
typedef struct FuelCellCAN_t {
    // fuel_cell_data message
    uint8_t ErrorFlag; // Fuel cell error flag
    uint16_t Ambient_T; // Ambient temperature
    uint16_t Fuelcell_out_V; // Fuel cell output voltage
    uint16_t H2_leak_V; // Hydrogen leak voltage
    uint16_t Fuelcell_T; // Fuel cell temperature
    uint8_t Fuelcell_I_high; // Fuel cell current high byte
    uint8_t Fuelcell_I_low; // Fuel cell current low byte
    uint16_t Battery_V_aux; // Auxiliary battery voltage
} FuelCellCAN_t;

// GpsCAN Module
typedef struct GpsCAN_t {
    // gps_data message
    uint32_t unknown_signal; // Placeholder for GPS CAN signal
} GpsCAN_t;

#endif // CAN_STRUCTS_H
