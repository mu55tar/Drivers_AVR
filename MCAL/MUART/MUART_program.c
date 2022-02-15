/*
 * MUART_program.c
 *
 *  Created on: Oct 21, 2021
 *      Author: Omar
 */

#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include "MUART_config.h"
#include "MUART_interface.h"
#include "MUART_private.h"


void MUART_voidInit(void)
{
	/*Step 1: TX Enable*/
	SET_BIT(MUART_UCSRB_REG,UCSRB_REG_TXEN);

	/*Step 2: RX Enable*/
	SET_BIT(MUART_UCSRB_REG,UCSRB_REG_RXEN);

	/*Step 3: UART Mode Selection , Asynchroneos*/
	CLR_BIT(MUART_UCSRC_REG,UCSRC_REG_UMSEL);

	/*Step 4: Data Bits Config*/
#if(MUART_DATA_BITS == MUART_DATA_SIZE_9)
	/*Choose Register C*/
	SET_BIT(MUART_UCSRC_REG,UCSRC_REG_URSEL);
	/*Write in Register C*/
	SET_BIT(MUART_UCSRC_REG,UCSRC_REG_UCSZ0);
	SET_BIT(MUART_UCSRC_REG,UCSRC_REG_UCSZ1);

	SET_BIT(MUART_UCSRB_REG,UCSRC_REG_UCSZ2);

#else
	/*Choose Register C*/
	SET_BIT(MUART_UCSRC_REG,UCSRC_REG_URSEL);
	/*Write in Register C*/
	/*Here we used it as a mask*/
	MUART_UCSRC_REG |= MUART_DATA_BITS << 1;

#endif

	/*Step 5: Stop Bits Config*/
	MUART_UCSRC_REG |= MUART_STOP_BITS << 3;

	/*Step 6 : Parity Bits Config*/
	MUART_UCSRC_REG |= MUART_PARITY;

	/*Baud Rate Config*/

	/*Choose Register UBBRH*/
	CLR_BIT(MUART_UBRRH_REG,UCSRC_REG_URSEL);
	/*WRITE IN Register UBBRH*/
	MUART_UBRRH_REG = (MUART_BAUD_RATE >> 8);

	MUART_UBRRL_REG = MUART_BAUD_RATE;

}
void MUART_voidSendByte(u8 Copy_u8Data)
{
	while(GET_BIT(MUART_UCSRA_REG,UCSRA_REG_UDRE)==0);
	MUART_UDR_REG = Copy_u8Data;
}
u8 MUART_u8ReadByte(void)
{
	u8 data;
	//Wait until Data is received
	while(GET_BIT(MUART_UCSRA_REG,UCSRA_REG_RXC)==0);

	//Access UDR to read Data
	data = MUART_UDR_REG;
	return data;

}
void MUART_voidSendString(u8 * Copy_str)
{
	u32 iterator;
	while(Copy_str[iterator] != '\0')
	{
		MUART_voidSendByte(Copy_str[iterator]);
		iterator++;
	}
}
