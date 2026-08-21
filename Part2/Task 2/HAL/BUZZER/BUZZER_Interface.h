#ifndef BUZZER_INTERFACE_H
#define BUZZER_INTERFACE_H

#include "../../MCAL/DIO/DIO_Interface.h"
#include "BUZZER_Config.h"
#include"BUZZER_Private.h"


void BUZZER_Init(uint8_t BUZZER_Name);
void BUZZER_On(uint8_t BUZZER_Name);
void BUZZER_Off(uint8_t BUZZER_Name);


#endif
