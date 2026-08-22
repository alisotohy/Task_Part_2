#ifndef _KEYPAD_PRIVATE_H_
#define _KEYPAD_PRIVATE_H_
#include "KeyPad_Interface.h"
#include <stdint.h>

#define KPD_ROWS 4
#define KPD_COLS 4

#define KPD_NOT_PRESSED   0xFF
#define KPD_PRESSED       0x00 
#define KEYPAD_CLEAR  0xFE

static uint8_t KPD_ARR[KPD_ROWS][KPD_COLS] =
{   {'7', '8', '9', '/'},
    {'4', '5', '6', '*'},
    {'1', '2', '3', '-'},
    {KEYPAD_CLEAR, '0', '=', '+'}
};

// Configuration parameters for the Keypad



#endif // _KEYPAD_PRIVATE_H_