#include "../development.h"
#include <stdio.h>

int main() {
    printf("Message Name: %s\n", pedal_msg_instance.name);
    printf("Message ID: %d\n", pedal_msg_instance.id);
    printf("Message Priority: %d\n", pedal_msg_instance.prio);
    printf("Message DLC: %d\n", pedal_msg_instance.dlc);

    printf("Signal Name: %s\n", pedal_msg_instance.pedal_voltage.name);
    printf("Signal Start: %d\n", pedal_msg_instance.pedal_voltage.start);
    printf("Signal Length: %d\n", pedal_msg_instance.pedal_voltage.length);
    printf("Signal Scale: %f\n", pedal_msg_instance.pedal_voltage.scale);
    printf("Signal Offset: %f\n", pedal_msg_instance.pedal_voltage.offset);
    printf("Signal Unit: %s\n", pedal_msg_instance.pedal_voltage.unit);
    printf("Signal Comment: %s\n", pedal_msg_instance.pedal_voltage.comment);
    printf("Signal Min Value: %f\n", pedal_msg_instance.pedal_voltage.min_value);
    printf("Signal Max Value: %f\n", pedal_msg_instance.pedal_voltage.max_value);
    printf("Signal Type: %s\n", pedal_msg_instance.pedal_voltage.type);
    printf("Signal Byte Order: %s\n", pedal_msg_instance.pedal_voltage.byte_order);

    return 0;
}
