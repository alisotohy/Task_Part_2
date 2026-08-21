#define F_CPU 8000000UL
#include <util/delay.h>
#include <stdint.h>
 
#include "HAL/BUZZER/BUZZER_Interface.h"
#include "MCAL/DIO/DIO_Interface.h"

 
int main(void)
{

       BUZZER_Init();
       while (1)
       {
             BUZZER_On();
             _delay_ms(1000);
              BUZZER_Off();

       }
       
    
    }
