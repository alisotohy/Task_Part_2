#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H

#include <stdint.h>
#include"../../Common/Bitmath.h"
#include"../../Common/Defination.h"
#include"../Atmega32RegMap.h"
#include"EXTI_Private.h"
#include "EXTI_Config.h"


void EXTI_Init(uint8_t InterruptName,uint8_t SensConfig);
void EXTI_Enable(uint8_t InterruptName);
void EXTI_Disable(uint8_t InterruptName);

void EXTI0_CallBackFunction(void(*PF)(void));
void EXTI1_CallBackFunction(void(*PF)(void));
void EXTI2_CallBackFunction(void(*PF)(void));





#endif