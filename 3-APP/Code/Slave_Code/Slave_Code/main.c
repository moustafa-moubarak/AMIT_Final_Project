/*
 * Slave_Code.c
 *
 * Created: 6/4/2021 3:08:09 PM
 * Author : Moustafa Moubarak
 */ 

#include "SPI.h"
#include "LED.h"

#define F_CPU	16000000
#include <util/delay.h>

int main(void)
{
	uint8 rx_data = 0;
	
	SPI_Slave_Init();
	
	LED_Init(DIO_PORTC, DIO_PIN2);
	LED_Init(DIO_PORTD, DIO_PIN3);
	while (1)
	{
		rx_data = SPI_TranSiver(0);
		switch (rx_data)
		{
			//Press 0 for all off 
			case 0x30:
			LED_OFF(DIO_PORTC, DIO_PIN2);
			LED_OFF(DIO_PORTD, DIO_PIN3);
			rx_data = 0;
			break;
			
			//Press 1 to toggle Led1
			case 0x31:
			LED_Toggle(DIO_PORTC, DIO_PIN2);
			rx_data = 0;
			break;
			
			//Press 2 to toggle Led2
			case 0x32:
			LED_Toggle(DIO_PORTD, DIO_PIN3);
			rx_data = 0;
			break;
			
			//press 3 to make all on
			case 0x33:
			LED_ON(DIO_PORTC, DIO_PIN2);
			LED_ON(DIO_PORTD, DIO_PIN3);
			rx_data = 0;
			break;
			
			default:
			break;
		}
	}
}



