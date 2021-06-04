#include "LED.h"


void LED_Init(uint8 port, uint8 pin)
{
	DIO_SetPINDir(port, pin, DIO_PIN_OUTPUT);
}

void LED_ON(uint8 port, uint8 pin)
{
	DIO_SetPinValue(port, pin, DIO_PIN_HIGH);
}

void LED_OFF(uint8 port, uint8 pin)
{
	DIO_SetPinValue(port, pin, DIO_PIN_LOW);
}

void LED_Toggle(uint8 port, uint8 pin)
{
	DIO_TogglePin(port, pin);
}