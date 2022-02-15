/*
 * MTIMER0_private.h
 *
 *  Created on: Oct 17, 2021
 *      Author: aya_enan
 */

#ifndef MTIMER0_MTIMER0_PRIVATE_H_
#define MTIMER0_MTIMER0_PRIVATE_H_

#define MTIMER0_TCCR0_Register   (*((volatile u8*)0x53))
#define MTIMER0_TCNT0_Register   (*((volatile u8*)0x52))
#define MTIMER0_OCR0_Register    (*((volatile u8*)0x5C))
#define MTIMER0_TIMSK_Register   (*((volatile u8*)0x59))
#define MTIMER0_TIFR_Register    (*((volatile u8*)0x58))

/*TCCR0  bits */
#define WGM00   6
#define WGM01   3
/*TIMSK  bits */
#define TOIE0 0
#define OCIE0 1

/*PRESCALER OPTIONS*/
#define  MTIMER0_PRESCALER_NO_CLOCK         0
#define  MTIMER0_PRESCALER_NO_PRESCALER     1
#define  MTIMER0_PRESCALER_8                2
#define  MTIMER0_PRESCALER_64               3
#define  MTIMER0_PRESCALER_256              4
#define  MTIMER0_PRESCALER_1024             5
#define  MTIMER0_PRESCALER_EXTCLK_FALL      6
#define  MTIMER0_PRESCALER_EXTCLK_RISE      7

/*Mode OPTIONS*/
#define MTIMER0_MODE_NORMAL                 0
#define MTIMER0_MODE_CTC                    1
#define MTIMER0_MODE_FAST_PWM               2
#define MTIMER0_MODE_PHASE_CORRECT          3

/*OC0 Mode options*/
#define MTIMER0_OC0_DISCONNECTED            0
#define MTIMER0_OC0_TOG                     1
#define MTIMER0_OC0_CLEAR                   2
#define MTIMER0_OC0_SET                     3

#define MTIMER0_OC0_FASTPWM_NONINVERTED		2
#define MTIMER0_OC0_FASTPWM_INVERTED		3


#define MTIMER0_PRESCALER_MASK    0b11111000
#define MTIMER0_OC0MODE_MASK      0b11001111
#endif /* MTIMER0_MTIMER0_PRIVATE_H_ */
