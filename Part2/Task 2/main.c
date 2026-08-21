#define F_CPU 8000000UL
#include <util/delay.h>
#include <stdint.h>

#include "MCAL/Timer/Timer_Interface.h"

int main(void)
{
    uint8_t Duty = 0;
    uint8_t Direction = 1;   //1 = Increasing (Fade In) , 0 = Decreasing (Fade Out)

    //Init Timer0 PWM On OC0 Pin (DIO_GroupB , DIO_Pin3) -> Connect LED Here
    TIMER0_PWM_Init();

    while (1)
    {
        TIMER0_PWM_SetDutyCycle(Duty);
        _delay_ms(20);

        if (Direction == 1)
        {
            Duty++;
            if (Duty == 100)
            {
                Direction = 0;
            }
        }
        else
        {
            Duty--;
            if (Duty == 0)
            {
                Direction = 1;
            }
        }
    }
}
