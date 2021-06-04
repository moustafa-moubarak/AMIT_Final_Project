#include "DIO.h"

/*
We Will Use the Macros of the DIO to Select the
Master Selection Pin just to be more generic Function
For Example SPI_Master_Init(DIO_PORTA, DIO_PIN0);
*/
void SPI_Master_Init(uint8 port_ss, uint8 pin_ss);

void SPI_Slave_Init(void);


/*
We Will Use the Macros of the DIO to Select the
Master Selection Pin just to be more generic Function
For Example SPI_Master_InitTrans(DIO_PORTA, DIO_PIN0);
*/
void SPI_Master_InitTrans(uint8 port_ss, uint8 pin_ss);


/*
We Will Use the Macros of the DIO to Select the
Master Selection Pin just to be more generic Function
For Example SPI_Master_TermTrans(DIO_PORTA, DIO_PIN0);
*/
void SPI_Master_TermTrans(uint8 port_ss, uint8 pin_ss);

uint8 SPI_TranSiver(uint8 data);