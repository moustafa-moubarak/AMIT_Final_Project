/*
 * MCU.h
 *
 * Created: 3/13/2021 2:23:47 PM
 *  Author: Ali
 */ 


#ifndef MCU_H_
#define MCU_H_

#include  "STD.h"

/****************** DIO REG ******************/

typedef struct
{
	uint8	PIND;
	uint8	DDRD;
	uint8	PORTD;
	
	uint8	PINC;
	uint8	DDRC;
	uint8	PORTC;

	uint8	PINB;
	uint8	DDRB;
	uint8	PORTB;
	
	uint8	PINA;
	uint8	DDRA;
	uint8	PORTA;
	} DIO_REGS;

#define		DIO			((volatile DIO_REGS*)(0x30))

/****************** SPI REG ******************/
typedef struct
{
	uint8	SPCR;
	uint8	SPSR;
	uint8	SPDR;
}SPI_REGS;

#define SPI	((volatile SPI_REGS*)(0x2D))

/****************** UART REG ******************/

#define		UBRRH		(*(volatile uint8*)(0x40))
#define		UBRRL		(*(volatile uint8*)(0x29))
#define		UCSRA		(*(volatile uint8*)(0x2B))
#define		UCSRB		(*(volatile uint8*)(0x2A))
#define		UCSRC		(*(volatile uint8*)(0x40))
#define		UDR			(*(volatile uint8*)(0x2C))




#endif /* MCU_H_ */