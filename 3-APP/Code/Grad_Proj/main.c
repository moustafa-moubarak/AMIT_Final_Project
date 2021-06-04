/*
 * Master_Code.c
 *
 * Created: 6/4/2021 12:16:59 AM
 * Author : Moustafa Moubarak
 */ 

#include "SPI.h"
#include "UART.h"

#define F_CPU	16000000
#include <util/delay.h>

int main(void)
{  
	
	uint8 UART_data = 0;
	
   SPI_Master_Init(DIO_PORTA, DIO_PIN0);
   SPI_Master_InitTrans(DIO_PORTA, DIO_PIN0);
   UART_Init();
   
   /*This is Just needed for the Master to Startup*/
   _delay_ms(1000);
   
    while (1) 
    {
		UART_data = UART_Rx();
		
		if (UART_data)
		{
			SPI_TranSiver(UART_data);
			
			UART_data = 0;
		}			
    }
}

