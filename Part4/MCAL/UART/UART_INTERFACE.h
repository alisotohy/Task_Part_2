#ifndef _UART_INTERFACE_H
#define _UART_INTERFACE_H

#include "../../Common/Defination.h"
#include "../../Common/Bitmath.h"
#include "../Atmega32regmap.h"

#include "UART_Private.h"
#include "UART_Config.h"

void UART_Init (UART_Config_t UART_Config);
void UART_SendBytePolling (uint16_t Data);
uint16_t UART_ReceiveBytePolling();
void UART_SendStringPolling(uint8_t* string);
void UART_ReceiveStringPolling(uint8_t* Buffer,uint8_t Terminator);
void UART_SendBufferPolling(uint8_t* Buffer, uint16_t Length);

void UART_SendByteInterrupt(uint16_t Data);


void UART_RxEnable();
void UART_TxEnable();
void UART_RxDisable();
void UART_TxDisable();

void UART_RxInterruptEnable();
void UART_TxInterruptEnable();
void UART_REInterruptEnable();

void UART_RxInterruptDisable();
void UART_TxInterruptDisable();
void UART_REInterruptDisable();

void UART_SetRxCallBack(void (*PF)(uint16_t ));
void UART_SetTxCallBack(void (*PF)(void));
void UART_SetRECallBack(void (*PF)(void));













#endif