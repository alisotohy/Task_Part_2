#ifndef BLUETOOTH_INTERFACE_H_
#define BLUETOOTH_INTERFACE_H_

#include "../../MCAL/UART/UART_INTERFACE.h"
typedef enum
{
    BT_NormalMode = 0,
    BT_ATMode
}BT_ModeType_t;

typedef enum
{
    BT_OK = 0,
    BT_NOK,
    BT_TIMEOUT
}BT_Status_t;

typedef struct
{
    uint32_t      BaudRate;   
    BT_ModeType_t Mode;       
}BT_Config_t;


void BT_Init(BT_Config_t BT_Config);

void       BT_SendByte(uint8_t Data);
void       BT_SendString(uint8_t* Str);
void       BT_SendBuffer(uint8_t* Buffer, uint16_t Length);
uint8_t    BT_ReceiveByte(void);
void       BT_ReceiveString(uint8_t* Buffer, uint8_t Terminator);


BT_Status_t BT_SendCommand(uint8_t* Command, uint8_t* ExpectedResponse, uint32_t TimeoutLoops);


void BT_SetRxCallBack(void (*PF)(uint16_t));

#endif  

