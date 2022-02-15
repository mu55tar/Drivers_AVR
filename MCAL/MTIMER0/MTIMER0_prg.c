/*
 * MTIMER0_prg.c
 *
 *  Created on: Oct 17, 2021
 *      Author: aya_enan
 */

#include <avr/interrupt.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "MTIMER0_private.h"
#include "MTIMER0_config.h"
#include "MTIMER0_interface.h"

void (*pv_ptrOVFCALLBackptr)(void) = NULL;//declaation ptr to function
void (*pv_ptrCTCCALLBackptr)(void) = NULL;
void MTIMER0_void_Init(void)// prescaler , mode, OC0 mode
{
	/*step 1 : choose Timer mode*/
#if(MTIMER0_MODE  == MTIMER0_MODE_NORMAL)
	CLR_BIT(MTIMER0_TCCR0_Register ,WGM00);
	CLR_BIT(MTIMER0_TCCR0_Register ,WGM01);
#elif(MTIMER0_MODE  == MTIMER0_MODE_CTC)
	CLR_BIT(MTIMER0_TCCR0_Register ,WGM00);
	SET_BIT(MTIMER0_TCCR0_Register ,WGM01);
#elif(MTIMER0_MODE  ==MTIMER0_MODE_FAST_PWM)
	SET_BIT(MTIMER0_TCCR0_Register ,WGM00);
	SET_BIT(MTIMER0_TCCR0_Register ,WGM01);

#elif(MTIMER0_MODE  ==MTIMER0_MODE_PHASE_CORRECT)
	SET_BIT(MTIMER0_TCCR0_Register ,WGM00);
	CLR_BIT(MTIMER0_TCCR0_Register ,WGM01);
#endif
	/*step 2: choose prescaler*/
	MTIMER0_TCCR0_Register &= MTIMER0_PRESCALER_MASK;
	MTIMER0_TCCR0_Register |= MTIMER0_PRESCALER;
	/*step 3: choose OC0 mode*/
	MTIMER0_TCCR0_Register &= MTIMER0_OC0MODE_MASK ;
	MTIMER0_TCCR0_Register |= MTIMER0_OC0_MODE << 4;
}
void MTIMER0_void_TimerStart() // CLK or prescaller
{
	MTIMER0_TCCR0_Register &= MTIMER0_PRESCALER_MASK;
	MTIMER0_TCCR0_Register |= MTIMER0_PRESCALER ;
}
void MTIMER0_void_TimerStop()// NO clk
{
	MTIMER0_TCCR0_Register &= MTIMER0_PRESCALER_MASK;
	MTIMER0_TCCR0_Register |= MTIMER0_PRESCALER_NO_CLOCK ;

}

void MTIMER0_void_EnableOVFInt()
{
	 SET_BIT(MTIMER0_TIMSK_Register,TOIE0);
}
void MTIMER0_void_DisableOVFInt()
{
	 CLR_BIT(MTIMER0_TIMSK_Register,TOIE0);
}
void MTIMER0_void_OVFsetCallBack(void (*copy_ptrfun)(void))
{
	pv_ptrOVFCALLBackptr = copy_ptrfun;
}

void MTIMER0_void_setPreload(u8 copy_u8Preload)
{
	MTIMER0_TCNT0_Register =  copy_u8Preload;
}
void MTIMER0_void_EnableCTCInt()
{
	 SET_BIT(MTIMER0_TIMSK_Register,OCIE0);
}
void MTIMER0_void_DisableCTCInt()
{
	 CLR_BIT(MTIMER0_TIMSK_Register,OCIE0);
}
void MTIMER0_void_CTCsetCallBack(void (*copy_ptrfun)(void))
{
	pv_ptrCTCCALLBackptr = copy_ptrfun;
}
void MTIMER0_void_setCompareValue(u8 copy_u8CompareValue)
{
	MTIMER0_OCR0_Register = copy_u8CompareValue;
}

void MTIMER0_void_setFastPWM(u8 copy_dutyCylcle)
{
#if (MTIMER0_OC0_MODE == MTIMER0_OC0_FASTPWM_NONINVERTED)
	MTIMER0_OCR0_Register = (copy_dutyCylcle*256)/100;

#elif (MTIMER0_OC0_MODE == MTIMER0_OC0_FASTPWM_INVERTED)
	MTIMER0_OCR0_Register = 255 - (copy_dutyCylcle*256)/100;
#endif
}


ISR(TIMER0_OVF_vect)
{
	pv_ptrOVFCALLBackptr();
}
ISR(TIMER0_COMP_vect)
{
	pv_ptrCTCCALLBackptr();
}
