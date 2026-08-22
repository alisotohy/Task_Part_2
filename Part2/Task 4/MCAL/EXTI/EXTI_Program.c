#include "EXTI_Interface.h"

//global variable for call back fubnction
static void(*EXTI0_ISRHandler)(void)=Null;
static void(*EXTI1_ISRHandler)(void)=Null;
static void(*EXTI2_ISRHandler)(void)=Null;


//confing (GIE)
void EXTI_Init(uint8_t InterruptName,uint8_t SensConfig)
{

// config int 0 (GIE)
    if(InterruptName==Exti_Interrupt0)
    {
        if(SensConfig==Exti_LowLevel)
        {
            ClearBit(MCUCR_Reg,Exti_ISC00);
            ClearBit(MCUCR_Reg,Exti_ISC01);
        }

        else if(SensConfig==Exti_AnyChange)
        {
            SetBit(MCUCR_Reg,Exti_ISC00);
            ClearBit(MCUCR_Reg,Exti_ISC01);
        }
        else if(SensConfig==Exti_FallingEdge)
        {
            ClearBit(MCUCR_Reg,Exti_ISC00);
            SetBit(MCUCR_Reg,Exti_ISC01);
        }
        else if (SensConfig==Exti_RisingEdge)
        {
            SetBit(MCUCR_Reg,Exti_ISC00);
            SetBit(MCUCR_Reg,Exti_ISC01);
        }

    }


// config int 1 (GIE)
    else if (InterruptName==Exti_Interrupt1)
    {
        if(SensConfig==Exti_LowLevel)
        {
            ClearBit(MCUCR_Reg,Exti_ISC10);
            ClearBit(MCUCR_Reg,Exti_ISC11);
        }

        else if(SensConfig==Exti_AnyChange)
        {
            SetBit(MCUCR_Reg,Exti_ISC10);
            ClearBit(MCUCR_Reg,Exti_ISC11);
        }
        else if(SensConfig==Exti_FallingEdge)
        {
            ClearBit(MCUCR_Reg,Exti_ISC10);
            SetBit(MCUCR_Reg,Exti_ISC11);
        }
        else if (SensConfig==Exti_RisingEdge)
        {
            SetBit(MCUCR_Reg,Exti_ISC10);
            SetBit(MCUCR_Reg,Exti_ISC11);
        }
    }


// config int 2 (GIE)
    else if(InterruptName==Exti_Interrupt2)
    {
        if(SensConfig==Exti_FallingEdge)
        {
            ClearBit(MCUCSR_Reg,Exti_ISC2);
        }
        else if(SensConfig==Exti_RisingEdge)
        {
            SetBit(MCUCSR_Reg,Exti_ISC2);
        }
    }
    
}

//Enable PIE
void EXTI_Enable(uint8_t InterruptName)
{
    //PIE INT0
    if (InterruptName==Exti_Interrupt0)
    {
        SetBit(GICR_Reg,Exti_INT0);
    }

    //PIE INT1
    else if(InterruptName==Exti_Interrupt1)
    {
        SetBit(GICR_Reg,Exti_INT1);
    }

    //PIE INT2
    else if (InterruptName==Exti_Interrupt2)
    {
        SetBit(GICR_Reg,Exti_INT2);
    }

}

//Disable PIE
void EXTI_Disable(uint8_t InterruptName)
{
    //PIE INT0
    if (InterruptName==Exti_Interrupt0)
    {
        ClearBit(GICR_Reg,Exti_INT0);
    }

    //PIE INT1
    else if(InterruptName==Exti_Interrupt1)
    {
        ClearBit(GICR_Reg,Exti_INT1);
    }

    //PIE INT2
    else if (InterruptName==Exti_Interrupt2)
    {
        ClearBit(GICR_Reg,Exti_INT2);
    }
}


/*

//call back function


//int0
void EXTI0_CallBackFunction(void(*PF)(void))
{
    if (PF!=Null)
    {
    
        EXTI0_ISRHandler=PF;
    }
    else
    {
    
    }
}


//int1
void EXTI1_CallBackFunction(void(*PF)(void))
{
    if (PF!=Null)
    {
    
        EXTI1_ISRHandler=PF;
    }
    else
    {
    
    }
}


//int2
void EXTI2_CallBackFunction(void(*PF)(void))
{
if (PF!=Null)
    {
    
        EXTI2_ISRHandler=PF;
    }
    else
    {
    
    }
}
*/

/*

//ISR
//ISR

// INT0
void __vector_1(void)  __attribute__((signal));  
// INT1 
void __vector_2(void)  __attribute__((signal)); 
// INT2
void __vector_3(void)  __attribute__((signal));  

// INT0

void __vector_1(void) 
{
if (EXTI0_ISRHandler!=Null)
{
    EXTI0_ISRHandler();
}
else
{

}
}   


// INT1 
void __vector_2(void)
{
    if (EXTI1_ISRHandler!=Null)
{
    EXTI1_ISRHandler();
}
else
{

}
}   


// INT2
void __vector_3(void)   
{
    if (EXTI2_ISRHandler!=Null)
{
    EXTI2_ISRHandler();
}
else
{

}
}*/