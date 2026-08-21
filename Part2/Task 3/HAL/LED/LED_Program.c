#include"LED_Interface.h"




//LED DIRECTION Output
void LED_Init(uint8_t Group_Name,uint8_t Pin_No)
{
    switch (Group_Name)
    {
    case DIO_GroupA:DIO_InitPin(DIO_GroupA,Pin_No,High);     break;
    case DIO_GroupB:DIO_InitPin(DIO_GroupB,Pin_No,High);     break;
    case DIO_GroupC:DIO_InitPin(DIO_GroupC,Pin_No,High);     break;
    case DIO_GroupD:DIO_InitPin(DIO_GroupD,Pin_No,High);     break;
    }
}

//Led On
void LED_On(uint8_t Group_Name,uint8_t Pin_No)
{
    switch (Group_Name)
    {
    case DIO_GroupA:DIO_WritePin(DIO_GroupA,Pin_No,High);     break;
    case DIO_GroupB:DIO_WritePin(DIO_GroupB,Pin_No,High);     break;
    case DIO_GroupC:DIO_WritePin(DIO_GroupC,Pin_No,High);     break;
    case DIO_GroupD:DIO_WritePin(DIO_GroupD,Pin_No,High);     break;
    }
}


//LedOff
void LED_Off(uint8_t Group_Name,uint8_t Pin_No)
{
    switch (Group_Name)
    {
    case DIO_GroupA:DIO_WritePin(DIO_GroupA,Pin_No,Low);     break;
    case DIO_GroupB:DIO_WritePin(DIO_GroupB,Pin_No,Low);     break;
    case DIO_GroupC:DIO_WritePin(DIO_GroupC,Pin_No,Low);     break;
    case DIO_GroupD:DIO_WritePin(DIO_GroupD,Pin_No,Low);     break;
    }

}


//Led Toggle
void LED_Toggle(uint8_t Group_Name,uint8_t Pin_No)
{
    switch (Group_Name)
    {
    case DIO_GroupA:DIO_TogglePin(DIO_GroupA,Pin_No); break;
    case DIO_GroupB:DIO_TogglePin(DIO_GroupB,Pin_No); break;    
    case DIO_GroupC:DIO_TogglePin(DIO_GroupC,Pin_No); break;
    case DIO_GroupD:DIO_TogglePin(DIO_GroupD,Pin_No); break;
    }
}


