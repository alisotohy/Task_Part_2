#ifndef _UART_PRIVATE_H
#define _UART_PRIVATE_H
#include <stdint.h>

#define UART_RXC 7
#define UART_TXC 6
#define UART_UDRE 5
#define UART_FE 4
#define UART_DOR 3
#define UART_PE 2 
#define UART_U2X 1
#define UART_MPCM 0

#define UART_RXCIE 7
#define UART_TXCIE 6
#define UART_UDRIE 5
#define UART_RXEN 4
#define UART_TXEN 3
#define UART_USCZ2 2
#define UART_RXB8 1
#define UART_TXB8 0

#define UART_NormalSpeed 0
#define UART_DoubleSpeed 1

#define UART_URSEL 7
#define UART_UMSEL 6
#define UART_UPM1 5
#define UART_UPM0 4
#define UART_USBS 3
#define UART_USCZ1 2
#define UART_USCZ0 1
#define UART_UCPOL 0

#define UART_SynchMode 1
#define UART_AsynchMode 0

#define UART_ParityDisabled 0
#define UART_ParityEven 2
#define UART_ParityOdd 3

#define CharacterSelectMask 0x06


#define UART_1StopBit 0
#define UART_2StopBits 1

#define UART_5BitSize 0
#define UART_6BitSize 1
#define UART_7BitSize 2
#define UART_8BitSize 3
#define UART_9BitSize 7

#define UART_EnableRxOnly   0
#define UART_EnableTxOnly   1 
#define UART_EnableRxTx  2

#define UART_InterrputDisabled 0
#define UART_InterruptRxOnly 1
#define UART_InterruptTxOnly 2
#define UART_InterruptREOnly 3
#define UART_InterruptRxTx 4
#define UART_InterruptRxRE 5
#define UART_InterruptTxRE 6
#define UART_InterruptAll 7


typedef struct 
{
    uint8_t ModeSelect; //
    uint8_t StopBitSelect; //
    uint8_t CharacterSizeSelect; 
    uint8_t SpeedMode; //
    uint8_t ParitySelect;//
    uint32_t BaudRate;
    uint8_t InterruptSelect;
    uint8_t EnableSelect ;

}UART_Config_t ;

//Rx
void __vector_13(void) __attribute__((signal));
//RE
void __vector_14(void) __attribute__((signal));
//Tx
void __vector_15(void) __attribute__((signal));


#endif