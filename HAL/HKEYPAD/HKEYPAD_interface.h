/*
 * HKEYPAD_interface.h
 *
 *  Created on: Oct 10, 2021
 *      Author: aya_enan
 */

#ifndef HKEYPAD_HKEYPAD_INTERFACE_H_
#define HKEYPAD_HKEYPAD_INTERFACE_H_

#define HKEYPAD_NO_PRESSED_KEY  0xFF

void HKEYPAD_voidInit(void);
u8 HKEYPAD_u8GetPressedKey(void);
#endif /* HKEYPAD_HKEYPAD_INTERFACE_H_ */
