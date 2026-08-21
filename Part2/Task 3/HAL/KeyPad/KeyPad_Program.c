#include"KeyPad_Interface.h"



void KPD_Init(void)
{
    // Implementation for keypad initialization
    // Coloum Direction 
    DIO_InitPin(KPD_DDR,KPD_COL0_PIN,Input);
    DIO_InitPin(KPD_DDR,KPD_COL1_PIN,Input);
    DIO_InitPin(KPD_DDR,KPD_COL2_PIN,Input);
    DIO_InitPin(KPD_DDR,KPD_COL3_PIN,Input);
    //Init value for coloum 
    DIO_WritePin(KPD_PORT,KPD_COL0_PIN,High);
    DIO_WritePin(KPD_PORT,KPD_COL1_PIN,High);
    DIO_WritePin(KPD_PORT,KPD_COL2_PIN,High);
    DIO_WritePin(KPD_PORT,KPD_COL3_PIN,High);

    // ROW 
    DIO_InitPin(KPD_DDR,KPD_ROW0_PIN,Output);
    DIO_InitPin(KPD_DDR,KPD_ROW1_PIN,Output);
    DIO_InitPin(KPD_DDR,KPD_ROW2_PIN,Output);
    DIO_InitPin(KPD_DDR,KPD_ROW3_PIN,Output);
    //Enable Internal Pull UP
    DIO_WritePin(KPD_PORT,KPD_ROW0_PIN,High);
    DIO_WritePin(KPD_PORT,KPD_ROW1_PIN,High);
    DIO_WritePin(KPD_PORT,KPD_ROW2_PIN,High);
    DIO_WritePin(KPD_PORT,KPD_ROW3_PIN,High);

}

char KPD_GetButtonValue(void)
{
    uint8_t R, C;
    uint8_t pinState;
    for (R = 0; R < KPD_ROWS; R++)
    {
        // Set the current row to LOW
        DIO_WritePin(KPD_PORT, KPD_ROW0_PIN + R, Low);

        for (C = 0; C < KPD_COLS; C++)
        {
            // Check if the button is pressed
            DIO_ReadPin(KPD_PORT, KPD_COL0_PIN + C, &pinState);
    
            if (pinState == Low)
            {
                // Wait for the button to be released
                while (pinState == Low)
                {
                    DIO_ReadPin(KPD_PORT, KPD_COL0_PIN + C, &pinState);
                }
                // Return the corresponding button value
                return KPD_ARR[R][C];
            }
        }

        // Set the current row back to HIGH
        DIO_WritePin(KPD_PORT, KPD_ROW0_PIN + R, High);
    }
    return KPD_NOT_PRESSED;
}