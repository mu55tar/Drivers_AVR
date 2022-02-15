/*
 * HLED_interface.h
 *
 *  Created on: Oct 18, 2021
 *      Author: aya_enan
 */

#ifndef HLED_HLED_INTERFACE_H_
#define HLED_HLED_INTERFACE_H_

#define LED0 0  // RED LED
#define LED1 1  // Green LED
#define LED2 2  // BLUE  LED

void HLED_voidLedInit(u8 led_num);
void HLED_voidTurnON(u8 led_num);
void HLED_voidTurnOFF(u8 led_num);
void HLED_voidTOG(u8 led_num);

#endif /* HLED_HLED_INTERFACE_H_ */
