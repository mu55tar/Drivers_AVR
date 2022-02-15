/*
 * MEXTI_private.h
 *
 *  Created on: Oct 13, 2021
 *      Author: aya_enan
 */

#ifndef MEXTI_MEXTI_PRIVATE_H_
#define MEXTI_MEXTI_PRIVATE_H_

#define MEXTI_SREG_Register    (*((volatile u8*)0x5F))
#define I_BIT             7

#define MEXTI_MCUCR_Register   (*((volatile u8*)0x55))
#define MEXTI_MCUCSR_Register  (*((volatile u8*)0x54))
#define MEXTI_GICR_Register    (*((volatile u8*)0x5B))
#define MEXTI_GIFR_Register    (*((volatile u8*)0x5A))

/*MCUCR  register bits*/
#define ISC00   0
#define ISC01   1
#define ISC10   2
#define ISC11   3

/*MCUCSR  register bits*/
#define ISC2    6

/*GICR  register bits*/
#define INT1   7
#define INT0   6
#define INT2   5

/*GIFR register bits*/
#define INTF1   7
#define INTF0   6
#define INTF2   5
#endif /* MEXTI_MEXTI_PRIVATE_H_ */
