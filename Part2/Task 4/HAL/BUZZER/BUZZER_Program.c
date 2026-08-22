#include"BUZZER_Interface.h"




//BUZZER DIRECTION Output
void BUZZER_Init()
{
    DIO_InitPin(BUZZER_Group,BUZZER_Pin,Output);
}

//BUZZER On
void BUZZER_On()
{
    DIO_WritePin(BUZZER_Group,BUZZER_Pin,High);
}


//BUZZEROff
void BUZZER_Off()
{
    DIO_WritePin(BUZZER_Group,BUZZER_Pin,Low);
}




