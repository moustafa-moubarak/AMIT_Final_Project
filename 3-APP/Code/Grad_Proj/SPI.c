
#include "SPI.h"

void SPI_Master_Init(uint8 port_ss, uint8 pin_ss)
{
	/*MOSI Pin*/
	DIO_SetPINDir(DIO_PORTB, DIO_PIN5, DIO_PIN_OUTPUT);
	/*MISO Pin*/
	DIO_SetPINDir(DIO_PORTB, DIO_PIN6, DIO_PIN_INPUT);
	/*CLK Pin*/
	DIO_SetPINDir(DIO_PORTB, DIO_PIN7, DIO_PIN_OUTPUT);
	/*SS Pin*/
	DIO_SetPINDir(port_ss, pin_ss, DIO_PIN_OUTPUT);
	
	/*SPI Enable*/
	SET_BIT(SPI->SPCR, 6);
	/*Select Master*/
	SET_BIT(SPI->SPCR, 4);
	/*PreScalar-64 Selection*/
	SET_BIT(SPI->SPCR, 0);
	SET_BIT(SPI->SPCR, 1);
	
}

void SPI_Slave_Init(void)
{
	/*MOSI Pin*/
	DIO_SetPINDir(DIO_PORTB, DIO_PIN5, DIO_PIN_INPUT);
	/*MISO Pin*/
	DIO_SetPINDir(DIO_PORTB, DIO_PIN6, DIO_PIN_OUTPUT);
	/*CLK Pin*/
	DIO_SetPINDir(DIO_PORTB, DIO_PIN7, DIO_PIN_INPUT);
	/*SS Pin*/
	DIO_SetPINDir(DIO_PORTB, DIO_PIN4, DIO_PIN_INPUT);
	
	/*SPI Enable*/
	SPI->SPCR |= 0x40;
}

void SPI_Master_InitTrans(uint8 port_ss, uint8 pin_ss)
{
	/*SS Pin Selection*/
	DIO_SetPinValue(port_ss, pin_ss, DIO_PIN_LOW);
}

void SPI_Master_TermTrans(uint8 port_ss, uint8 pin_ss)
{
	/*SS Terminate Signal*/
	DIO_SetPinValue(port_ss, pin_ss, DIO_PIN_HIGH);
}


uint8 SPI_TranSiver(uint8 data)
{
	uint8 rec_data = 0;
	
	SPI->SPDR = data;
	
	while(GET_BIT(SPI->SPSR, 7) == 0);
	
	rec_data = SPI->SPDR;
	
	return rec_data; 
}