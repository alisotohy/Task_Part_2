#define F_CPU 8000000UL 
#include"MCAL/DIO/DIO_Interface.h"
#include"HAL/LM35/LM35_Interface.h"
#include"HAL/LED/LED_Interface.h"
#include"HAL/LCD/LCD_Interface.h"
#include"MCAL/GIE/GIE_Interface.h"
#include"MCAL/EXTI/EXTI_Interface.h"



int main()
{
    void EXTI0_ISRHandler(void);
    uint16_t temp=0;

    DIO_InitPin(DIO_GroupA,DIO_Pin0,Output);
    ADC_Init(ADC_AVCC, ADC_RightAdjust, ADC_DivisionFactor64);
    LCD_Init(Lcd_8bitMode);
    DIO_WritePin(DIO_GroupA,DIO_Pin5,Input);
    DIO_InitPin(DIO_GroupD,DIO_Pin2,Input);
    LED_Init(DIO_GroupC,DIO_Pin1);
    LED_Init(DIO_GroupC,DIO_Pin6);
    GIE_Enable(Exti_Interrupt0);
    EXTI_Init(Exti_Interrupt0,Exti_RisingEdge);
    EXTI0_CallBackFunction(EXTI0_ISRHandler);
    EXTI_Enable(Exti_Interrupt0);

    
    while(1)
    {

        temp=LM35_GetTemperature();
        LCD_GotoXY(0,1);
        LCD_WriteString("TEMP: ",Lcd_8bitMode);
        LCD_WriteNumber(temp,Lcd_8bitMode);
        _delay_ms(50);
       
        if (temp>=40)
           {
               LED_On(DIO_GroupC,DIO_Pin1);
           }
        else if (temp<40) 
           {
               LED_Off(DIO_GroupC,DIO_Pin1);
           }


    }

}




    void EXTI0_ISRHandler(void)
    {
        uint8_t temp=0;
        static uint8_t LedState = Off;
         if((LedState==Off))
         {
             // LedON
             LED_On(DIO_GroupC,DIO_Pin6);
             LedState= On;

         }
         else if ((LedState==On))
         {
             //Led OFF 
             LED_Off(DIO_GroupC,DIO_Pin6);
             LedState=Off;

         }
    }




