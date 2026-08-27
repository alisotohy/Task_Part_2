#ifndef SEVEN_SEGMENT_INTERFACE_H
#define SEVEN_SEGMENT_INTERFACE_H

#include "SEVEN_Segment_Config.h"
#include "SEVEN_Segment_Private.h"
#include "../../MCAL/AtmegaReg16.h"
#include "../../Common/Defination.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include "../../Common/Bitmath.h"
#include "util/delay.h"

void SEVEN_SEGMENT_Init(uint8_t PortName);                                
void SEVEN_SEGMENT_DisplayNumber(uint8_t PortName,uint8_t Number);        
//void SEVEN_SEGMENT_DisplayChar(uint8_t PortName,uint8_t Char);            

#endif