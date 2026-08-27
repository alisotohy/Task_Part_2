#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H

#include <stdint.h>
#include "../../COMMON/Bitmath.h"
#include "../../COMMON/Defination.h"
#include "../AtmegaReg16.h"
#include "EXTI_Private.h"
#include "EXTI_Config.h"

//
void EXTI_Init(uint8_t InterruptName,uint8_t SensConfig);
void EXTI_Enable(uint8_t InterruptName);
void EXTI_Disable(uint8_t InterruptName);


void EXTI0_CallBackFunction(void(*PF)(void));
void EXTI1_CallBackFunction(void(*PF)(void));
void EXTI2_CallBackFunction(void(*PF)(void));




#endif