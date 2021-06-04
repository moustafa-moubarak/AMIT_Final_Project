

#include "DIO.h"


/*
All Inputs needs To be from Macros in DIO.h
From Example: LED_Init(DIO_PORTA, DIO_PIN0);
*/

void LED_Init(uint8 port, uint8 pin);

void LED_ON(uint8 port, uint8 pin);

void LED_Toggle(uint8 port, uint8 pin);

void LED_OFF(uint8 port, uint8 pin);