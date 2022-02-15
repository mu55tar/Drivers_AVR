/*
 * MUART_private.h
 *
 *  Created on: Oct 21, 2021
 *      Author: Omar
 */

#ifndef MCAL_MUART_MUART_PRIVATE_H_
#define MCAL_MUART_MUART_PRIVATE_H_

#define MUART_UDR_REG				(*((volatile u8*)0x2C))
#define MUART_UCSRA_REG				(*((volatile u8*)0x2B))
#define MUART_UCSRB_REG				(*((volatile u8*)0x2A))
#define MUART_UCSRC_REG				(*((volatile u8*)0x40))
#define MUART_UBRRL_REG				(*((volatile u8*)0x29))
#define MUART_UBRRH_REG				(*((volatile u8*)0x40))


/*MUART_UCSRA_REG BITS */

#define UCSRA_REG_RXC							7
#define UCSRA_REG_TXC							6
#define UCSRA_REG_UDRE							5
#define UCSRA_REG_FE							4
#define UCSRA_REG_DDR							3
#define UCSRA_REG_PE							2
#define UCSRA_REG_U2X							1
#define UCSRA_REG_MPCM							0

/*MUART_UCSRB_REG BITS */

#define UCSRB_REG_RXCIE							7
#define UCSRB_REG_TXCIE							6
#define UCSRB_REG_UDRIE							5
#define UCSRB_REG_RXEN							4
#define UCSRB_REG_TXEN							3
#define UCSRB_REG_UCSZ2							2
#define UCSRB_REG_RXB8							1
#define UCSRB_REG_TXB8							0



/*MUART_UCSRC_REG BITS */

#define UCSRC_REG_URSEL							7
#define UCSRC_REG_UMSEL							6
#define UCSRC_REG_UMP1							5
#define UCSRC_REG_UMP0							4
#define UCSRC_REG_USBS							3
#define UCSRC_REG_UCSZ1							2
#define UCSRC_REG_UCSZ0							1
#define UCSRC_REG_UCPOL							0


/*Data Config Options*/
#define MUART_DATA_SIZE_5						0
#define MUART_DATA_SIZE_6						1
#define MUART_DATA_SIZE_7						2
#define MUART_DATA_SIZE_8						3
#define MUART_DATA_SIZE_9						7

/*Congif number of stop Bits*/
#define MUART_1_STOPBIT							0
#define MUART_2_STOPBITS						1

/*Config Parity Options*/
#define MUART_PARITY_DISABLE					0
#define MUART_PARITY_EVEN						2
#define MUART_PARITY_ODD						3

#define MUART_BR_4800_8MHZ	  					103
#define MUART_BR_9600_8MHZ	  					51
#define MUART_BR_115200_8MHZ					3


#define MUART_BR_4800_16MHZ	 				 	207
#define MUART_BR_9600_16MHZ	  					103
#define MUART_BR_115200_16MHZ 					8


#endif /* MCAL_MUART_MUART_PRIVATE_H_ */
