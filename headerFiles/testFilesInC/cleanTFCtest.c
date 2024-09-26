#include "cleanTFC.h"
#include <stdio.h>

int main() {
    // Access and print variables from pedal_message_instance
    printf("Pedal Message Name: %s\n", pedal_message_instance.name);
    printf("Pedal Message ID: %d\n", pedal_message_instance.id);
    printf("Pedal Message Priority: %d\n", pedal_message_instance.prio);

    // Access and print variables from pedal_voltage within pedal_message_instance
    printf("Pedal Voltage Start: %d\n", pedal_message_instance.pedal_voltage.start);
    printf("Pedal Voltage Length: %d\n", pedal_message_instance.pedal_voltage.length);
    printf("Pedal Voltage Offset: %f\n", pedal_message_instance.pedal_voltage.offset);
    printf("Pedal Voltage Unit: %s\n", pedal_message_instance.pedal_voltage.unit);
    printf("Pedal Voltage Comment: %s\n", pedal_message_instance.pedal_voltage.comment);
    printf("Pedal Voltage Min Value: %f\n", pedal_message_instance.pedal_voltage.min_value);
    printf("Pedal Voltage Max Value: %d\n", pedal_message_instance.pedal_voltage.max_value);
    printf("Pedal Voltage Type: %s\n", pedal_message_instance.pedal_voltage.type);
    printf("Pedal Voltage Byte Order: %s\n", pedal_message_instance.pedal_voltage.byte_order);

    // Access and print variables from vesc_data_instance
    printf("VESC Data Name: %s\n", vesc_data_instance.name);
    printf("VESC Data ID: %d\n", vesc_data_instance.id);
    printf("VESC Data Priority: %d\n", vesc_data_instance.prio);

    // Access and print variables from signals within vesc_data_instance
    // input_voltage
    printf("Input Voltage Start: %d\n", vesc_data_instance.input_voltage.start);
    printf("Input Voltage Length: %d\n", vesc_data_instance.input_voltage.length);
    printf("Input Voltage Scale: %f\n", vesc_data_instance.input_voltage.scale);
    printf("Input Voltage Offset: %f\n", vesc_data_instance.input_voltage.offset);
    printf("Input Voltage Unit: %s\n", vesc_data_instance.input_voltage.unit);
    printf("Input Voltage Comment: %s\n", vesc_data_instance.input_voltage.comment);
    printf("Input Voltage Type: %s\n", vesc_data_instance.input_voltage.type);
    printf("Input Voltage Byte Order: %s\n", vesc_data_instance.input_voltage.byte_order);

    // current_motor
    printf("Current Motor Start: %d\n", vesc_data_instance.current_motor.start);
    printf("Current Motor Length: %d\n", vesc_data_instance.current_motor.length);
    printf("Current Motor Scale: %f\n", vesc_data_instance.current_motor.scale);
    printf("Current Motor Offset: %f\n", vesc_data_instance.current_motor.offset);
    printf("Current Motor Unit: %s\n", vesc_data_instance.current_motor.unit);
    printf("Current Motor Comment: %s\n", vesc_data_instance.current_motor.comment);
    printf("Current Motor Type: %s\n", vesc_data_instance.current_motor.type);
    printf("Current Motor Byte Order: %s\n", vesc_data_instance.current_motor.byte_order);

    // current_in
    printf("Current In Start: %d\n", vesc_data_instance.current_in.start);
    printf("Current In Length: %d\n", vesc_data_instance.current_in.length);
    printf("Current In Scale: %f\n", vesc_data_instance.current_in.scale);
    printf("Current In Offset: %f\n", vesc_data_instance.current_in.offset);
    printf("Current In Unit: %s\n", vesc_data_instance.current_in.unit);
    printf("Current In Comment: %s\n", vesc_data_instance.current_in.comment);
    printf("Current In Type: %s\n", vesc_data_instance.current_in.type);
    printf("Current In Byte Order: %s\n", vesc_data_instance.current_in.byte_order);

    // duty_cycle
    printf("Duty Cycle Start: %d\n", vesc_data_instance.duty_cycle.start);
    printf("Duty Cycle Length: %d\n", vesc_data_instance.duty_cycle.length);
    printf("Duty Cycle Scale: %f\n", vesc_data_instance.duty_cycle.scale);
    printf("Duty Cycle Offset: %f\n", vesc_data_instance.duty_cycle.offset);
    printf("Duty Cycle Unit: %s\n", vesc_data_instance.duty_cycle.unit);
    printf("Duty Cycle Comment: %s\n", vesc_data_instance.duty_cycle.comment);
    printf("Duty Cycle Type: %s\n", vesc_data_instance.duty_cycle.type);
    printf("Duty Cycle Byte Order: %s\n", vesc_data_instance.duty_cycle.byte_order);

    // watt_hours_used
    printf("Watt Hours Used Start: %d\n", vesc_data_instance.watt_hours_used.start);
    printf("Watt Hours Used Length: %d\n", vesc_data_instance.watt_hours_used.length);
    printf("Watt Hours Used Scale: %f\n", vesc_data_instance.watt_hours_used.scale);
    printf("Watt Hours Used Offset: %f\n", vesc_data_instance.watt_hours_used.offset);
    printf("Watt Hours Used Unit: %s\n", vesc_data_instance.watt_hours_used.unit);
    printf("Watt Hours Used Comment: %s\n", vesc_data_instance.watt_hours_used.comment);
    printf("Watt Hours Used Type: %s\n", vesc_data_instance.watt_hours_used.type);
    printf("Watt Hours Used Byte Order: %s\n", vesc_data_instance.watt_hours_used.byte_order);

    // ms_today_setup
    printf("Milliseconds Today Setup Start: %d\n", vesc_data_instance.ms_today_setup.start);
    printf("Milliseconds Today Setup Length: %d\n", vesc_data_instance.ms_today_setup.length);
    printf("Milliseconds Today Setup Scale: %f\n", vesc_data_instance.ms_today_setup.scale);
    printf("Milliseconds Today Setup Offset: %f\n", vesc_data_instance.ms_today_setup.offset);
    printf("Milliseconds Today Setup Unit: %s\n", vesc_data_instance.ms_today_setup.unit);
    printf("Milliseconds Today Setup Comment: %s\n", vesc_data_instance.ms_today_setup.comment);
    printf("Milliseconds Today Setup Type: %s\n", vesc_data_instance.ms_today_setup.type);
    printf("Milliseconds Today Setup Byte Order: %s\n", vesc_data_instance.ms_today_setup.byte_order);

    // speed_meters_per_sec
    printf("Speed Meters Per Sec Start: %d\n", vesc_data_instance.speed_meters_per_sec.start);
    printf("Speed Meters Per Sec Length: %d\n", vesc_data_instance.speed_meters_per_sec.length);
    printf("Speed Meters Per Sec Scale: %f\n", vesc_data_instance.speed_meters_per_sec.scale);
    printf("Speed Meters Per Sec Offset: %f\n", vesc_data_instance.speed_meters_per_sec.offset);
    printf("Speed Meters Per Sec Unit: %s\n", vesc_data_instance.speed_meters_per_sec.unit);
    printf("Speed Meters Per Sec Comment: %s\n", vesc_data_instance.speed_meters_per_sec.comment);
    printf("Speed Meters Per Sec Type: %s\n", vesc_data_instance.speed_meters_per_sec.type);
    printf("Speed Meters Per Sec Byte Order: %s\n", vesc_data_instance.speed_meters_per_sec.byte_order);

    // Access and print variables from flow_meter_data_instance
    printf("Flow Meter Data Name: %s\n", flow_meter_data_instance.name);
    printf("Flow Meter Data ID: %d\n", flow_meter_data_instance.id);
    printf("Flow Meter Data Priority: %d\n", flow_meter_data_instance.prio);

    // unknown_signal within flow_meter_data_instance
    printf("Flow Meter Unknown Signal Start: %d\n", flow_meter_data_instance.unknown_signal.start);
    printf("Flow Meter Unknown Signal Length: %d\n", flow_meter_data_instance.unknown_signal.length);
    printf("Flow Meter Unknown Signal Scale: %f\n", flow_meter_data_instance.unknown_signal.scale);
    printf("Flow Meter Unknown Signal Offset: %f\n", flow_meter_data_instance.unknown_signal.offset);
    printf("Flow Meter Unknown Signal Unit: %s\n", flow_meter_data_instance.unknown_signal.unit);
    printf("Flow Meter Unknown Signal Comment: %s\n", flow_meter_data_instance.unknown_signal.comment);
    printf("Flow Meter Unknown Signal Type: %s\n", flow_meter_data_instance.unknown_signal.type);
    printf("Flow Meter Unknown Signal Byte Order: %s\n", flow_meter_data_instance.unknown_signal.byte_order);

    // Access and print variables from fuel_cell_data_instance
    printf("Fuel Cell Data Name: %s\n", fuel_cell_data_instance.name);
    printf("Fuel Cell Data ID: %d\n", fuel_cell_data_instance.id);
    printf("Fuel Cell Data Priority: %d\n", fuel_cell_data_instance.prio);

    // ErrorFlag
    printf("ErrorFlag Start: %d\n", fuel_cell_data_instance.ErrorFlag.start);
    printf("ErrorFlag Length: %d\n", fuel_cell_data_instance.ErrorFlag.length);
    printf("ErrorFlag Scale: %f\n", fuel_cell_data_instance.ErrorFlag.scale);
    printf("ErrorFlag Offset: %f\n", fuel_cell_data_instance.ErrorFlag.offset);
    printf("ErrorFlag Unit: %s\n", fuel_cell_data_instance.ErrorFlag.unit);
    printf("ErrorFlag Comment: %s\n", fuel_cell_data_instance.ErrorFlag.comment);
    printf("ErrorFlag Type: %s\n", fuel_cell_data_instance.ErrorFlag.type);
    printf("ErrorFlag Byte Order: %s\n", fuel_cell_data_instance.ErrorFlag.byte_order);

    // Ambient_T
    printf("Ambient_T Start: %d\n", fuel_cell_data_instance.Ambient_T.start);
    printf("Ambient_T Length: %d\n", fuel_cell_data_instance.Ambient_T.length);
    printf("Ambient_T Scale: %f\n", fuel_cell_data_instance.Ambient_T.scale);
    printf("Ambient_T Offset: %f\n", fuel_cell_data_instance.Ambient_T.offset);
    printf("Ambient_T Unit: %s\n", fuel_cell_data_instance.Ambient_T.unit);
    printf("Ambient_T Comment: %s\n", fuel_cell_data_instance.Ambient_T.comment);
    printf("Ambient_T Type: %s\n", fuel_cell_data_instance.Ambient_T.type);
    printf("Ambient_T Byte Order: %s\n", fuel_cell_data_instance.Ambient_T.byte_order);

    // Fuelcell_out_V
    printf("Fuelcell_out_V Start: %d\n", fuel_cell_data_instance.Fuelcell_out_V.start);
    printf("Fuelcell_out_V Length: %d\n", fuel_cell_data_instance.Fuelcell_out_V.length);
    printf("Fuelcell_out_V Scale: %f\n", fuel_cell_data_instance.Fuelcell_out_V.scale);
    printf("Fuelcell_out_V Offset: %f\n", fuel_cell_data_instance.Fuelcell_out_V.offset);
    printf("Fuelcell_out_V Unit: %s\n", fuel_cell_data_instance.Fuelcell_out_V.unit);
    printf("Fuelcell_out_V Comment: %s\n", fuel_cell_data_instance.Fuelcell_out_V.comment);
    printf("Fuelcell_out_V Type: %s\n", fuel_cell_data_instance.Fuelcell_out_V.type);
    printf("Fuelcell_out_V Byte Order: %s\n", fuel_cell_data_instance.Fuelcell_out_V.byte_order);

    // H2_leak_V
    printf("H2_leak_V Start: %d\n", fuel_cell_data_instance.H2_leak_V.start);
    printf("H2_leak_V Length: %d\n", fuel_cell_data_instance.H2_leak_V.length);
    printf("H2_leak_V Scale: %f\n", fuel_cell_data_instance.H2_leak_V.scale);
    printf("H2_leak_V Offset: %f\n", fuel_cell_data_instance.H2_leak_V.offset);
    printf("H2_leak_V Unit: %s\n", fuel_cell_data_instance.H2_leak_V.unit);
    printf("H2_leak_V Comment: %s\n", fuel_cell_data_instance.H2_leak_V.comment);
    printf("H2_leak_V Type: %s\n", fuel_cell_data_instance.H2_leak_V.type);
    printf("H2_leak_V Byte Order: %s\n", fuel_cell_data_instance.H2_leak_V.byte_order);

    // Fuelcell_T
    printf("Fuelcell_T Start: %d\n", fuel_cell_data_instance.Fuelcell_T.start);
    printf("Fuelcell_T Length: %d\n", fuel_cell_data_instance.Fuelcell_T.length);
    printf("Fuelcell_T Scale: %f\n", fuel_cell_data_instance.Fuelcell_T.scale);
    printf("Fuelcell_T Offset: %f\n", fuel_cell_data_instance.Fuelcell_T.offset);
    printf("Fuelcell_T Unit: %s\n", fuel_cell_data_instance.Fuelcell_T.unit);
    printf("Fuelcell_T Comment: %s\n", fuel_cell_data_instance.Fuelcell_T.comment);
    printf("Fuelcell_T Type: %s\n", fuel_cell_data_instance.Fuelcell_T.type);
    printf("Fuelcell_T Byte Order: %s\n", fuel_cell_data_instance.Fuelcell_T.byte_order);

    // Fuelcell_I_high
    printf("Fuelcell_I_high Start: %d\n", fuel_cell_data_instance.Fuelcell_I_high.start);
    printf("Fuelcell_I_high Length: %d\n", fuel_cell_data_instance.Fuelcell_I_high.length);
    printf("Fuelcell_I_high Scale: %f\n", fuel_cell_data_instance.Fuelcell_I_high.scale);
    printf("Fuelcell_I_high Offset: %f\n", fuel_cell_data_instance.Fuelcell_I_high.offset);
    printf("Fuelcell_I_high Unit: %s\n", fuel_cell_data_instance.Fuelcell_I_high.unit);
    printf("Fuelcell_I_high Comment: %s\n", fuel_cell_data_instance.Fuelcell_I_high.comment);
    printf("Fuelcell_I_high Type: %s\n", fuel_cell_data_instance.Fuelcell_I_high.type);
    printf("Fuelcell_I_high Byte Order: %s\n", fuel_cell_data_instance.Fuelcell_I_high.byte_order);

    // Fuelcell_I_low
    printf("Fuelcell_I_low Start: %d\n", fuel_cell_data_instance.Fuelcell_I_low.start);
    printf("Fuelcell_I_low Length: %d\n", fuel_cell_data_instance.Fuelcell_I_low.length);
    printf("Fuelcell_I_low Scale: %f\n", fuel_cell_data_instance.Fuelcell_I_low.scale);
    printf("Fuelcell_I_low Offset: %f\n", fuel_cell_data_instance.Fuelcell_I_low.offset);
    printf("Fuelcell_I_low Unit: %s\n", fuel_cell_data_instance.Fuelcell_I_low.unit);
    printf("Fuelcell_I_low Comment: %s\n", fuel_cell_data_instance.Fuelcell_I_low.comment);
    printf("Fuelcell_I_low Type: %s\n", fuel_cell_data_instance.Fuelcell_I_low.type);
    printf("Fuelcell_I_low Byte Order: %s\n", fuel_cell_data_instance.Fuelcell_I_low.byte_order);

    // Battery_V_aux
    printf("Battery_V_aux Start: %d\n", fuel_cell_data_instance.Battery_V_aux.start);
    printf("Battery_V_aux Length: %d\n", fuel_cell_data_instance.Battery_V_aux.length);
    printf("Battery_V_aux Scale: %f\n", fuel_cell_data_instance.Battery_V_aux.scale);
    printf("Battery_V_aux Offset: %f\n", fuel_cell_data_instance.Battery_V_aux.offset);
    printf("Battery_V_aux Unit: %s\n", fuel_cell_data_instance.Battery_V_aux.unit);
    printf("Battery_V_aux Comment: %s\n", fuel_cell_data_instance.Battery_V_aux.comment);
    printf("Battery_V_aux Type: %s\n", fuel_cell_data_instance.Battery_V_aux.type);
    printf("Battery_V_aux Byte Order: %s\n", fuel_cell_data_instance.Battery_V_aux.byte_order);

    // Access and print variables from gps_data_instance
    printf("GPS Data Name: %s\n", gps_data_instance.name);
    printf("GPS Data ID: %d\n", gps_data_instance.id);
    printf("GPS Data Priority: %d\n", gps_data_instance.prio);

    // unknown_signal within gps_data_instance
    printf("GPS Unknown Signal Start: %d\n", gps_data_instance.unknown_signal2.start);
    printf("GPS Unknown Signal Length: %d\n", gps_data_instance.unknown_signal2.length);
    printf("GPS Unknown Signal Scale: %f\n", gps_data_instance.unknown_signal2.scale);
    printf("GPS Unknown Signal Offset: %f\n", gps_data_instance.unknown_signal2.offset);
    printf("GPS Unknown Signal Unit: %s\n", gps_data_instance.unknown_signal2.unit);
    printf("GPS Unknown Signal Comment: %s\n", gps_data_instance.unknown_signal2.comment);
    printf("GPS Unknown Signal Type: %s\n", gps_data_instance.unknown_signal2.type);
    printf("GPS Unknown Signal Byte Order: %s\n", gps_data_instance.unknown_signal2.byte_order);

    return 0;
}
