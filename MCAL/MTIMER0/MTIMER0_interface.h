/*
 * MTIMER0_interface.h
 *
 *  Created on: Oct 17, 2021
 *      Author: aya_enan
 */

#ifndef MTIMER0_MTIMER0_INTERFACE_H_
#define MTIMER0_MTIMER0_INTERFACE_H_


void MTIMER0_void_Init(void);// prescaler , mode, OC0 mode
void MTIMER0_void_TimerStart(); // CLK or prescaller
void MTIMER0_void_TimerStop();// NO clk

/*Normal Mode functions*/
void MTIMER0_void_EnableOVFInt();
void MTIMER0_void_DisableOVFInt();
void MTIMER0_void_OVFsetCallBack(void (*copy_ptrfun)(void));
void MTIMER0_void_setPreload(u8 copy_u8Preload);

/*CTC Mode functions*/
void MTIMER0_void_EnableCTCInt();
void MTIMER0_void_DisableCTCInt();
void MTIMER0_void_CTCsetCallBack(void (*copy_ptrfun)(void));
void MTIMER0_void_setCompareValue(u8 copy_u8CompareValue);


/*PWM FAST*/
void MTIMER0_void_setFastPWM(u8 copy_dutyCylcle);

#endif /* MTIMER0_MTIMER0_INTERFACE_H_ */
