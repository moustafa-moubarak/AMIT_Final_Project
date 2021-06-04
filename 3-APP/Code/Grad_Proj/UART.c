#include "UART.h"

void UART_Init(void)
{
	uint32 UBRR_Val = 0;
	
	//Tx Pin output
	SET_BIT(DIO->DDRD,1);
	//Rx Pin output
	CLR_BIT(DIO->DDRD,0);
	
	//Enable Tx
	SET_BIT(UCSRB, 4);
	
	//Enable Rx
	SET_BIT(UCSRB, 3);
	
	UCSRC |= 0x86;
	
	//Set Baud Rate
	UBRR_Val = (160000 / (16 * 96) ) - 1;
	UBRRL = UBRR_Val;
}

uint8 UART_Rx (void)
{
	uint8 data = 0;
	while (GET_BIT(UCSRA, 7) == 0);
	
	data = UDR;
	
	return data;
}

void UART_Tx (uint8 data)
{
	UDR = data;
	while(GET_BIT(UCSRA, 5) == 0);
}
