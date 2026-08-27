#ifndef _KEYPAD_INTERFACE_H_
#define _KEYPAD_INTERFACE_H_
#include "KeyPad_Config.h"
#include "KeyPad_Private.h"
#include "../../MCAL/DIO/DIO_Interface.h"
#include <stdint.h>
#include "../LCD/LCD_Interface.h"

// Function prototypes for Keypad interface
void KPD_Init(void);
char KPD_GetButtonValue(void);

#endif // _KEYPAD_INTERFACE_H_