#include "HAL/BT/BT_Interface.h"
#include "MCAL/DIO/DIO_Interface.h"
 

 
int main(void)
{
    BT_Config_t Local_BTConfig = {9600, BT_NormalMode};
    uint8_t Local_Status;
    uint8_t Local_ButtonState     = 0; 
    uint8_t Local_PrevButtonState = 1;
 
    DIO_InitPin(DIO_GroupA, DIO_Pin0, Output);
    DIO_WritePin(DIO_GroupA, DIO_Pin0, Low);
 
  
    DIO_InitPin(DIO_GroupA, DIO_Pin1, Input);
    DIO_WritePin(DIO_GroupA, DIO_Pin1, High);
 
    BT_Init(Local_BTConfig);
 
    BT_SendString((uint8_t*)"Bluetooth Module Ready!\r\n");
 
 
    while (1)
    {
        DIO_ReadPin(DIO_GroupA, DIO_Pin1, &Local_ButtonState);
 
    
        if (Local_ButtonState == Low && Local_PrevButtonState == High)
        {
            DIO_WritePin(DIO_GroupA, DIO_Pin0, High);
            BT_SendString((uint8_t*)"1\r\n");
        }
        else if (Local_ButtonState == High && Local_PrevButtonState == Low)
        {
            DIO_WritePin(DIO_GroupA, DIO_Pin0, Low);
            BT_SendString((uint8_t*)"0\r\n");
        }
 
        Local_PrevButtonState = Local_ButtonState;
    }
}
 