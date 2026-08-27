#ifndef LED_INTERFACE_H
#define LED_INTERFACE_H

#include "../../MCAL/DIO/DIO_Interface.h"
#include "LED_Config.h"
#include"LED_Private.h"


void LED_Init  (uint8_t Group_Name,uint8_t Pin_No);
void LED_On    (uint8_t Group_Name,uint8_t Pin_No);
void LED_Off   (uint8_t Group_Name,uint8_t Pin_No);
void LED_Toggle(uint8_t Group_Name,uint8_t Pin_No);


#endif
