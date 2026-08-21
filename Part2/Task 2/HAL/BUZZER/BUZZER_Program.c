#include"BUZZER_Interface.h"




//BUZZER DIRECTION Output
void BUZZER_Init(uint8_t BUZZER_Name)
{
    DIO_InitPin(BUZZER_Group,BUZZER_Pin,Output);
}

//BUZZER On
void BUZZER_On(uint8_t BUZZER_Name)
{
    DIO_WritePin(BUZZER_Group,BUZZER_Pin,High);
}


//BUZZEROff
void BUZZER_Off(uint8_t BUZZER_Name)
{
    DIO_WritePin(BUZZER_Group,BUZZER_Pin,Low);
}




