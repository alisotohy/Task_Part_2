#ifndef _TIMER_INTERFACE_H
#define _TIMER_INTERFACE_H

#include <stdint.h>

#include "../Atmega32RegMap.h"
#include "../../Common/Defination.h"
#include "../../Common/Bitmath.h"
#include "Timer_Private.h"
#include "Timer_Config.h"

//Prescaler options (CS02:CS00 bits)
#define TIMER0_NO_PRESCALER      1
#define TIMER0_PRESCALER_8       2
#define TIMER0_PRESCALER_64      3
#define TIMER0_PRESCALER_256     4
#define TIMER0_PRESCALER_1024    5


//Init Timer0 as Fast-PWM , Non-Inverting on OC0 Pin (DIO_GroupB , DIO_Pin3)
void TIMER0_PWM_Init(void);

//Set LED Brightness , Duty From 0 -> 100 (%)
void TIMER0_PWM_SetDutyCycle(uint8_t Duty);

//Stop The Timer (PWM Generation)
void TIMER0_PWM_Stop(void);


#endif
