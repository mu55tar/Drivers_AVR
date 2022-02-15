/*
 * MUART_interface.h
 *
 *  Created on: Oct 21, 2021
 *      Author: Omar
 */

#ifndef MCAL_MUART_MUART_INTERFACE_H_
#define MCAL_MUART_MUART_INTERFACE_H_

void MUART_voidInit(void);
void MUART_voidSendByte(u8 Copy_u8Data);
u8 MUART_u8ReadByte(void);
void MUART_voidSendString(u8 * Copy_str);

#endif /* MCAL_MUART_MUART_INTERFACE_H_ */
