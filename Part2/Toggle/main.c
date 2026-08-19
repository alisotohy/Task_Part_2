#include<stdint.h>
#include"MCAL/DIO/DIO_Interface.h"
#include"HAL/LED/LED_Interface.h"
#include"util/delay.h"

void main ()
{
    DIO_InitPin (DIO_GroupA,DIO_Pin0,Output);
    while (1)
    {
    DIO_TogglePin(DIO_GroupA,DIO_Pin0);
        _delay_ms(500);
    }
}