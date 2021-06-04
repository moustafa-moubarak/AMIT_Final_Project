
#include "DIO.h"



void DIO_SetPINDir(uint8 port, uint8 pin, uint8 direction)
{
	switch (direction)
	{
		case DIO_PIN_OUTPUT:
		switch(port)
		{
			case(DIO_PORTA):
				SET_BIT(DIO->DDRA,pin);
				break;
				
			case(DIO_PORTB):
				SET_BIT(DIO->DDRB,pin);
				break;
				
			case(DIO_PORTC):
				SET_BIT(DIO->DDRC,pin);
				break;
				
			case(DIO_PORTD):
				SET_BIT(DIO->DDRD,pin);
				break;
				
			default:
			break;
		}
		break;
		case (DIO_PIN_INPUT):
		switch(port)
		{
			case(DIO_PORTA):
				CLR_BIT(DIO->DDRA,pin);
				break;
			case(DIO_PORTB):
				CLR_BIT(DIO->DDRB,pin);
				break;
			case(DIO_PORTC):
				CLR_BIT(DIO->DDRC,pin);
				break;
			case(DIO_PORTD):
				CLR_BIT(DIO->DDRD,pin);
				break;
			default:
			break;
		}
		break;
			
		default:
		break;
	}
}

void DIO_SetPinValue(uint8 port, uint8 pin, uint8 value)
{
	switch(value)
	{
		case (DIO_PIN_HIGH):
		switch(port)
		{
			case DIO_PORTA:
				SET_BIT(DIO->PORTA, pin);
				break;
				
			case DIO_PORTB:
				SET_BIT(DIO->PORTB, pin);
				break;
			
			case DIO_PORTC:
				SET_BIT(DIO->PORTC, pin);
				break;
			
			case DIO_PORTD:
				SET_BIT(DIO->PORTD, pin);
				break;
			
			default:
			break;
		}
		break;
		
		case (DIO_PIN_LOW):
		switch(port)
		{
			case DIO_PORTA:
				CLR_BIT(DIO->PORTA, pin);
				break;
			
			case DIO_PORTB:
				CLR_BIT(DIO->PORTB, pin);
				break;
			
			case DIO_PORTC:
				CLR_BIT(DIO->PORTC, pin);
				break;
			
			case DIO_PORTD:
				CLR_BIT(DIO->PORTD, pin);
				break;
			
			default:
			break;
	}
	break;
	
	default:
	break;
	}
}

void DIO_ReadPinValue(uint8 port, uint8 pin, uint8 *recall_value)
{
	switch(port)
	{
		case (DIO_PORTA):
		*recall_value = GET_BIT(DIO->PINA, pin);
		break;
		
		case (DIO_PORTB):
		*recall_value = GET_BIT(DIO->PINB, pin);
		break;
		
		case (DIO_PORTC):
		*recall_value = GET_BIT(DIO->PINC, pin);
		break;
		
		case (DIO_PORTD):
		*recall_value = GET_BIT(DIO->PIND, pin);
		break;
		
		default:
		break;
	}
}

void DIO_TogglePin(uint8 port, uint8 pin)
{
	switch(port)
	{
		case DIO_PORTA:
		Toggle_BIT(DIO->PORTA,pin);
		break;
		
		case DIO_PORTB:
		Toggle_BIT(DIO->PORTB,pin);
		break;
		
		case DIO_PORTC:
		Toggle_BIT(DIO->PORTC,pin);
		break;
		
		case DIO_PORTD:
		Toggle_BIT(DIO->PORTD,pin);
		break;
		
		default:
		break;
	}
}
