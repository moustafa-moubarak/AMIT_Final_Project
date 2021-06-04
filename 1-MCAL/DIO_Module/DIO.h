#ifndef DIO_h_
#define DIO_h_


#include "MCU.h"
#include "BIT_Math.h"
#include "STD.h"

#define		DIO_PORTA			0
#define		DIO_PORTB			1
#define		DIO_PORTC			2
#define		DIO_PORTD			3

#define		DIO_PIN0			0
#define		DIO_PIN1			1
#define		DIO_PIN2			2
#define		DIO_PIN3			3
#define		DIO_PIN4			4
#define		DIO_PIN5			5		
#define		DIO_PIN6			6
#define		DIO_PIN7			7

#define		DIO_PIN_OUTPUT		1
#define		DIO_PIN_INPUT		0

#define		DIO_PIN_HIGH		1
#define		DIO_PIN_LOW			0


/*
All Inputs should be from the Macros in "DIO.h"
For Example DIO_SetPINDir(DIO_PORTA, DIO_PIN0, DIO_PIN_OUTPUT);
*/
void DIO_SetPINDir(uint8 port, uint8 pin, uint8 direction);

void DIO_SetPinValue(uint8 port, uint8 pin, uint8 value);

void DIO_ReadPinValue(uint8 port, uint8 pin, uint8 *recall_value);

void DIO_TogglePin(uint8 port, uint8 pin);
#endif /* DIO_H_ */