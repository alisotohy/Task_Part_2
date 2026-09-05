#include "UART_Interface.h"

#ifndef F_CPU
#define F_CPU 8000000UL
#endif

static void (*PF_UartRx)(uint16_t)=Null; 
static void (*PF_UartTx)(void)=Null;
static void (*PF_UartRE)(void)=Null;

static UART_Config_t GlobalUARTConfig={0};

void UART_Init (UART_Config_t UART_Config)
{
    uint8_t Local_UCSRCValue=0;
    GlobalUARTConfig=UART_Config;

    SetBit(Local_UCSRCValue,UART_URSEL);

//Mode
if(UART_Config.ModeSelect==UART_AsynchMode)
{
ClearBit(Local_UCSRCValue,UART_UMSEL);
}
else if(UART_Config.ModeSelect==UART_SynchMode)
{
SetBit(Local_UCSRCValue,UART_UMSEL);
}

//StopBit
if(UART_Config.StopBitSelect==UART_1StopBit)
{
ClearBit(Local_UCSRCValue,UART_USBS);
}

else if(UART_Config.StopBitSelect==UART_2StopBits)
{
SetBit(Local_UCSRCValue,UART_USBS);
}

//Parity
if(UART_Config.ParitySelect==UART_ParityDisabled)
{
ClearBit(Local_UCSRCValue,UART_UPM0);
ClearBit(Local_UCSRCValue,UART_UPM1);
}
else if(UART_Config.ParitySelect==UART_ParityEven)
{
ClearBit(Local_UCSRCValue,UART_UPM0);
SetBit(Local_UCSRCValue,UART_UPM1);
}
else if(UART_Config.ParitySelect==UART_ParityOdd)
{
SetBit(Local_UCSRCValue,UART_UPM0);
SetBit(Local_UCSRCValue,UART_UPM1);
}

//Character Size Selection
if(UART_Config.CharacterSizeSelect<9)
{
ClearBit(Local_UCSRCValue,UART_USCZ2);
Local_UCSRCValue= (Local_UCSRCValue &~ CharacterSelectMask)| (UART_Config.CharacterSizeSelect<<1);
}
else if(UART_Config.CharacterSizeSelect==9)
{
SetBit(Local_UCSRCValue,UART_USCZ0);
SetBit(Local_UCSRCValue,UART_USCZ1);
SetBit(UCSRB_Reg,UART_USCZ2);
}
UCSRC_Reg= Local_UCSRCValue;

//-------------------------------------------------------

//Speed
if(UART_Config.SpeedMode==UART_DoubleSpeed)
{
SetBit(UCSRA_Reg,UART_U2X);
}
else if(UART_Config.SpeedMode==UART_NormalSpeed)
{
ClearBit(UCSRA_Reg,UART_U2X);
}

//BaudRate
uint16_t Local_UBBRValue=0;

if(UART_Config.SpeedMode==UART_DoubleSpeed)
{
    Local_UBBRValue= ( F_CPU/(8UL * UART_Config.BaudRate) )-1;
}
else if(UART_Config.SpeedMode==UART_NormalSpeed)
{
    Local_UBBRValue= ( F_CPU/(16UL * UART_Config.BaudRate) )-1;
}
UBRRL_Reg=Local_UBBRValue;
UBRRH_Reg=(Local_UBBRValue>>8);


//InterruptSelect

UART_RxInterruptDisable();
UART_TxInterruptDisable();
UART_REInterruptDisable();

if(UART_Config.InterruptSelect==UART_InterruptRxOnly)
{
    UART_RxInterruptEnable();
}
else if(UART_Config.InterruptSelect==UART_InterruptTxOnly)
{
    UART_TxInterruptEnable();

}
else if(UART_Config.InterruptSelect==UART_InterruptREOnly)
{
    UART_REInterruptEnable();

}
else if(UART_Config.InterruptSelect==UART_InterruptRxTx)
{
     UART_RxInterruptEnable();
     UART_TxInterruptEnable();
}
else if(UART_Config.InterruptSelect==UART_InterruptRxRE)
{
     UART_RxInterruptEnable();
     UART_REInterruptEnable();

}
else if(UART_Config.InterruptSelect==UART_InterruptTxRE)
{
     UART_TxInterruptEnable();
     UART_REInterruptEnable();
}
else if(UART_Config.InterruptSelect==UART_InterruptAll)
{
     UART_TxInterruptEnable();
     UART_REInterruptEnable();
     UART_RxInterruptEnable();
}

//Enable Select
if(UART_Config.EnableSelect==UART_EnableRxOnly)
{
    UART_RxEnable();
   UART_TxDisable();
}
else if(UART_Config.EnableSelect==UART_EnableTxOnly)
{
   UART_TxEnable();
    UART_RxDisable();

}
else if(UART_Config.EnableSelect==UART_EnableRxTx)
{
    UART_RxEnable(); 
    UART_TxEnable();
}


}

void UART_SendBytePolling (uint16_t Data)
{
    while(ReadFlag(UCSRA_Reg,UART_UDRE)==FlagDown);

    if(GlobalUARTConfig.CharacterSizeSelect==9)
    {
     ClearBit(UCSRB_Reg,UART_TXB8);
      if(ReadBit(Data,8)==1)
        {
            SetBit(UCSRB_Reg,UART_TXB8);
        }
    }
    UDR_Reg=(uint8_t)Data;
}

uint16_t UART_ReceiveBytePolling()
{
    uint16_t LocalData=0;
    while(ReadFlag(UCSRA_Reg,UART_RXC)==FlagDown);
    if(GlobalUARTConfig.CharacterSizeSelect==9)
    {
        if(ReadBit(UCSRB_Reg,UART_RXB8)==1)
        {
            SetBit(LocalData,UART_RXB8);
        }
    }
    LocalData|=UDR_Reg;
    return LocalData;
}
void UART_SendStringPolling(uint8_t* string)
{
    uint8_t LocalCount=0;
    if(string != Null)
    {
        while(string[LocalCount]!=NullChar)
        {
            UART_SendBytePolling(string[LocalCount]);
            LocalCount++;
        }
    }
}

void UART_ReceiveStringPolling(uint8_t* Buffer,uint8_t Terminator)
{
    uint16_t LocalCount=0;
    if(Buffer!=Null)
    {
        Buffer[LocalCount]=(uint8_t)UART_ReceiveBytePolling();
        while(Buffer[LocalCount]!=Terminator)
        {
         LocalCount++;
         Buffer[LocalCount]=(uint8_t)UART_ReceiveBytePolling();
        }
         Buffer[LocalCount] = '\0';
    }
}

void UART_SendBufferPolling(uint8_t* Buffer, uint16_t Length)
{
    uint16_t LocalCount=0;
     for(LocalCount = 0; LocalCount < Length; LocalCount++)
    {
        UART_SendBytePolling(Buffer[LocalCount]);
    }

}

void UART_SendByteInterrupt(uint16_t Data)
{
    if(GlobalUARTConfig.CharacterSizeSelect == 9)
    {
        ClearBit(UCSRB_Reg, UART_TXB8);
        if(ReadBit(Data, 8) == 1)
        {
            SetBit(UCSRB_Reg, UART_TXB8);
        }
    }
    
    
    UDR_Reg = (uint8_t)Data;
}


void UART_RxEnable()
{
  SetBit(UCSRB_Reg,UART_RXEN);
}
void UART_TxEnable()
{
  SetBit(UCSRB_Reg,UART_TXEN); 
}
void UART_RxDisable()
{
    ClearBit(UCSRB_Reg,UART_RXEN);
}
void UART_TxDisable()
{
    ClearBit(UCSRB_Reg,UART_TXEN);
}

void UART_RxInterruptEnable()
{
    SetBit(UCSRB_Reg,UART_RXCIE);
}
void UART_TxInterruptEnable()
{
    SetBit(UCSRB_Reg,UART_TXCIE);
}
void UART_REInterruptEnable()
{
    SetBit(UCSRB_Reg,UART_UDRIE);
}

void UART_RxInterruptDisable()
{
    ClearBit(UCSRB_Reg,UART_RXCIE);
}
void UART_TxInterruptDisable()
{
    ClearBit(UCSRB_Reg,UART_TXCIE);
}
void UART_REInterruptDisable()
{
    ClearBit(UCSRB_Reg,UART_UDRIE);
}

void UART_SetRxCallBack(void (*PF)(uint16_t))
{
      if(PF!=Null)
      {
       PF_UartRx=PF;
      }

}
void UART_SetTxCallBack(void (*PF)(void))
{
      if(PF!=Null)
      {
      PF_UartTx=PF;
      }
}
void UART_SetRECallBack(void (*PF)(void))
{
      if(PF!=Null)
      {
         PF_UartRE=PF;
      }
}


//Rx
void __vector_13(void)
{
   if(PF_UartRx!=Null)
   {
    uint16_t LocalData=0;
   if(GlobalUARTConfig.CharacterSizeSelect==9)
   {
      if(ReadBit(UCSRB_Reg, UART_RXB8) == 1)
        {
        SetBit(LocalData, 8); 
        }
   }
     LocalData|=UDR_Reg;
     PF_UartRx(LocalData);
   }
}
//RE
void __vector_14(void)
{
   if(PF_UartRE!=Null)
   {
    PF_UartRE();
   }
}

//Tx
void __vector_15(void)
{
   if(PF_UartTx!=Null)
   {
    PF_UartTx(); 
   }
}