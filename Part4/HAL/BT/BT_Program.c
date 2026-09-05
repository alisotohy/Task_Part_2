#include "BT_Interface.h"
#include "../../MCAL/UART/UART_INTERFACE.h"
#include <string.h>
 

void BT_Init(BT_Config_t BT_Config)
{
    UART_Config_t Local_UARTConfig;
 
    Local_UARTConfig.ModeSelect          = UART_AsynchMode;
    Local_UARTConfig.StopBitSelect       = UART_1StopBit;
    Local_UARTConfig.CharacterSizeSelect = UART_8BitSize;
    Local_UARTConfig.SpeedMode           = UART_NormalSpeed;
    Local_UARTConfig.ParitySelect        = UART_ParityDisabled;
    Local_UARTConfig.BaudRate            = BT_Config.BaudRate;
    Local_UARTConfig.InterruptSelect     = UART_InterrputDisabled;
    Local_UARTConfig.EnableSelect        = UART_EnableRxTx;
 
    UART_Init(Local_UARTConfig);
}
 

void BT_SendByte(uint8_t Data)
{
    UART_SendBytePolling((uint16_t)Data);
}
 
void BT_SendString(uint8_t* Str)
{
    UART_SendStringPolling(Str);
}
 
void BT_SendBuffer(uint8_t* Buffer, uint16_t Length)
{
    UART_SendBufferPolling(Buffer, Length);
}
 
uint8_t BT_ReceiveByte(void)
{
    return (uint8_t)UART_ReceiveBytePolling();
}
 
void BT_ReceiveString(uint8_t* Buffer, uint8_t Terminator)
{
    UART_ReceiveStringPolling(Buffer, Terminator);
}
 
BT_Status_t BT_SendCommand(uint8_t* Command, uint8_t* ExpectedResponse, uint32_t TimeoutLoops)
{
    uint8_t Local_ResponseBuffer[32];
 
    (void)TimeoutLoops;
 
    BT_SendString(Command);
    BT_SendString((uint8_t*)"\r\n");
 
    BT_ReceiveString(Local_ResponseBuffer, '\n');
 
    if (strstr((char*)Local_ResponseBuffer, (char*)ExpectedResponse) != Null)
    {
        return BT_OK;
    }
 
    return BT_NOK;
}
 
 
void BT_SetRxCallBack(void (*PF)(uint16_t))
{
    UART_SetRxCallBack(PF);
    UART_RxInterruptEnable();
}
 