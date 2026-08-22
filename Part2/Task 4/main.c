#define F_CPU 8000000UL
#include <util/delay.h>
#include <stdint.h>

#include "HAL/LED/LED_Interface.h"
#include "MCAL/DIO/DIO_Interface.h"


int main(void)
{
       
       DIO_InitPin(DIO_GroupB, DIO_Pin2, Output);
       DIO_InitPin(DIO_GroupA, DIO_Pin0, Input);

    while (1)
    {        
       uint8_t pin_state =PINA_Reg;
       //DIO_ReadPin(DIO_GroupA,DIO_Pin0,&pin_state);
        if (pin_state=0x01)
        {
            LED_On(DIO_GroupB, DIO_Pin2);
        }
        else
        {
            LED_Off(DIO_GroupB, DIO_Pin2);
        }
    }
}