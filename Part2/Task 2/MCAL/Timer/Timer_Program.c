#include "Timer_Interface.h"


void TIMER0_PWM_Init(void)
{
    //OC0 Pin (PB3) As Output , This Is The Pin The LED Must Be Connected To
    SetBit(DDRB_Reg,3);

    //Fast PWM Mode  (WGM01=1 , WGM00=1)
    SetBit(TCCR0_Reg,WGM01);
    SetBit(TCCR0_Reg,WGM00);

    //Non-Inverting Mode  (COM01=1 , COM00=0) -> OC0 Set On BOTTOM , Cleared On Compare Match
    SetBit(TCCR0_Reg,COM01);
    ClearBit(TCCR0_Reg,COM00);

    //Select Clock Source / Prescaler , Also Starts The Timer
    switch (TIMER0_PRESCALER)
    {
    case TIMER0_NO_PRESCALER:
        SetBit(TCCR0_Reg,CS00);
        ClearBit(TCCR0_Reg,CS01);
        ClearBit(TCCR0_Reg,CS02);
        break;

    case TIMER0_PRESCALER_8:
        ClearBit(TCCR0_Reg,CS00);
        SetBit(TCCR0_Reg,CS01);
        ClearBit(TCCR0_Reg,CS02);
        break;

    case TIMER0_PRESCALER_64:
        SetBit(TCCR0_Reg,CS00);
        SetBit(TCCR0_Reg,CS01);
        ClearBit(TCCR0_Reg,CS02);
        break;

    case TIMER0_PRESCALER_256:
        ClearBit(TCCR0_Reg,CS00);
        ClearBit(TCCR0_Reg,CS01);
        SetBit(TCCR0_Reg,CS02);
        break;

    case TIMER0_PRESCALER_1024:
        SetBit(TCCR0_Reg,CS00);
        ClearBit(TCCR0_Reg,CS01);
        SetBit(TCCR0_Reg,CS02);
        break;

    default:
        break;
    }

    //Start With 0% Duty Cycle (LED Off)
    OCR0_Reg = 0;
}

void TIMER0_PWM_SetDutyCycle(uint8_t Duty)
{
    if (Duty > 100)
    {
        Duty = 100;
    }

    //Map 0 -> 100 (%) Into 0 -> 255 (OCR0 Range)
    OCR0_Reg = (uint8_t)(((uint16_t)Duty * 255) / 100);
}

void TIMER0_PWM_Stop(void)
{
    //Clear CS02:CS00 -> No Clock Source , Timer Stopped
    ClearBit(TCCR0_Reg,CS00);
    ClearBit(TCCR0_Reg,CS01);
    ClearBit(TCCR0_Reg,CS02);
}
