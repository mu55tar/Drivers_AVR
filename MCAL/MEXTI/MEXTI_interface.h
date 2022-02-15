/*
 * MEXTI_interface.h
 *
 *  Created on: Oct 13, 2021
 *      Author: aya_enan
 */

#ifndef MEXTI_MEXTI_INTERFACE_H_
#define MEXTI_MEXTI_INTERFACE_H_

/*
 * Interrupt src triggers
 */
#define LOW_LEVEL   0
#define ANY_CHANGE  1
#define FALL_EDGE   2
#define RISE_EDGE   3


/*
 * Interrupt  IDs
 */
#define  INT0_ID  0
#define  INT1_ID  1
#define  INT2_ID  2

void MEXTI_voidEnable_Int(u8 copy_u8IntID,u8 copy_u8IntSrc);
void MEXTI_voidDisable_Int(u8 copy_u8IntID);


void MEXTI_setCallBack_INT0(void (*ptr_function)(void));
void MEXTI_setCallBack_INT1(void (*ptr_function)(void));
void MEXTI_setCallBack_INT2(void (*ptr_function)(void));
#endif /* MEXTI_MEXTI_INTERFACE_H_ */
