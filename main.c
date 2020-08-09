//#include <msp430.h>
#include <msp430.h>
#include <stdint.h>
#include "pwm.h"
#include "hw.h"

// Test program to dim the led up and down using pwm
void test_program_dimming_led()
{
    volatile unsigned int i;
    uint16_t dim_value = 0;
    uint8_t count_direction = 0;
    while(1)
    {
        if (dim_value >= 50 || dim_value <= 0) {
            count_direction ^= 1;
        }
        dim_value += 5*(count_direction ? 1 : -1);

        pwm_set_duty_cycle(PWM_OUT_0, dim_value);
        for(i=3000; i>0; i--); // busy loop delay
    }
}

void main(void)
{
    hw_init();
    pwm_init();

    // TODO: is this really needed? Try without
    _enable_interrupt();

    test_program_dimming_led();
}
