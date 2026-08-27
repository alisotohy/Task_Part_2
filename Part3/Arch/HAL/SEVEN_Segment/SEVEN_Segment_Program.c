#include "SEVEN_Segment_Interface.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include"SEVEN_Segment_Config.h"

void SEVEN_SEGMENT_Init(uint8_t PortName)     
{
    switch (PortName)
    {

    case DIO_GroupA: DIO_InitGroup(DIO_GroupA, Output);     break;
    case DIO_GroupB: DIO_InitGroup(DIO_GroupB, Output);     break;
    case DIO_GroupC: DIO_InitGroup(DIO_GroupC, Output);     break;
    case DIO_GroupD: DIO_InitGroup(DIO_GroupD, Output);     break;

    }
}             
void SEVEN_SEGMENT_DisplayNumber(uint8_t PortName,uint8_t Number)
{
    switch (PortName)
    {

    case DIO_GroupA: DIO_WriteGroup(DIO_GroupA,Number);   break;
    case DIO_GroupB: DIO_WriteGroup(DIO_GroupB,Number);   break;
    case DIO_GroupC: DIO_WriteGroup(DIO_GroupC,Number);   break;
    case DIO_GroupD: DIO_WriteGroup(DIO_GroupD,Number);   break;
    
    }
}
void SEVEN_SEGMENT_DisplayChar(uint8_t PortName,uint8_t Char)

{
    switch (PortName)
    {

    case DIO_GroupA: DIO_WriteGroup(DIO_GroupA,Char);   break;
    case DIO_GroupB: DIO_WriteGroup(DIO_GroupB,Char);   break;
    case DIO_GroupC: DIO_WriteGroup(DIO_GroupC,Char);   break;
    case DIO_GroupD: DIO_WriteGroup(DIO_GroupD,Char);   break;
    
    }
}