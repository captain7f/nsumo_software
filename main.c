#include "hw.h"
#include "state_machine.h"
#include "trace.h"
#include "test.h"

int main(void)
{
    hw_init();
    if (!trace_init()) {
        while (1);
    }
    TRACE_INFO("Booted");

    //test_state_machine_ir();
    //test_vl53l0x();
    //test_enemy_detection();
    //test_line_detection();
    //test_vl53l0x();
    //test_vl53l0x_multiple();
    //test_vl53l0x_multiple_time();
    //test_qre1113();
    //test_drive_and_line_detect();
    //test_rotate_and_enemy_detect();
    //test_gpio_input();
    //state_machine_run();
    //test_drives_remote();
    test_ir_receiver();
    //test_state_machine_ir();
    // TODO: Disable everything and endless loop in case of failure
    while (1);
}
