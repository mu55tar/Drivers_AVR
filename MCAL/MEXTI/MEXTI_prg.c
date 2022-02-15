/*
 * MEXTI_prg.c
 *
 *  Created on: Oct 13, 2021
 *      Author: aya_enan
 */

#include <avr/interrupt.h>
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "MEXTI_private.h"
#include "MEXTI_config.h"
#include "MEXTI_interface.h"

void (*global_ptrf_INT0)(void);
void (*global_ptrf_INT1)(void);
void (*global_ptrf_INT2)(void);
void MEXTI_voidEnable_Int(u8 copy_u8IntID,u8 copy_u8IntSrc)
{
	/*step 1 : enable GIE*/
	SET_BIT(MEXTI_SREG_Register,I_BIT);
   switch(copy_u8IntID)
   {
   case INT0_ID:
	   /*enable PIE for INT0*/
	   SET_BIT(MEXTI_GICR_Register,INT0);
	   /*config trigger for INT0*/
	   switch(copy_u8IntSrc)
	   {
	   case LOW_LEVEL:
		   CLR_BIT(MEXTI_MCUCR_Register,ISC00);
		   CLR_BIT(MEXTI_MCUCR_Register,ISC01);
		   break;
	   case ANY_CHANGE:
		   SET_BIT(MEXTI_MCUCR_Register,ISC00);
		   CLR_BIT(MEXTI_MCUCR_Register,ISC01);
	   	  break;
	   case FALL_EDGE:
		   CLR_BIT(MEXTI_MCUCR_Register,ISC00);
		   SET_BIT(MEXTI_MCUCR_Register,ISC01);
	   		   break;
	   case RISE_EDGE:
		   SET_BIT(MEXTI_MCUCR_Register,ISC00);
		   SET_BIT(MEXTI_MCUCR_Register,ISC01);
	   		   break;
	   }

	   break;
   case INT1_ID:
	   /*enable PIE for INT1*/
	   SET_BIT(MEXTI_GICR_Register,INT1);
	   /*config trigger for INT1*/
	   switch(copy_u8IntSrc)
	   {
	   case LOW_LEVEL:
		   CLR_BIT(MEXTI_MCUCR_Register,ISC10 );
		   CLR_BIT(MEXTI_MCUCR_Register,ISC11 );
		   break;
	   case ANY_CHANGE:
		   SET_BIT(MEXTI_MCUCR_Register,ISC10);
		   CLR_BIT(MEXTI_MCUCR_Register,ISC11);
		  break;
	   case FALL_EDGE:
		   CLR_BIT(MEXTI_MCUCR_Register,ISC10);
		   SET_BIT(MEXTI_MCUCR_Register,ISC11);
			   break;
	   case RISE_EDGE:
		   SET_BIT(MEXTI_MCUCR_Register,ISC10);
		   SET_BIT(MEXTI_MCUCR_Register,ISC11);
			   break;
	   }

   	   break;
   case INT2_ID:
	   /*enable PIE for INT2*/
	   SET_BIT(MEXTI_GICR_Register,INT2);
	   /*config trigger for INT2*/
	   switch(copy_u8IntSrc)
	   	   {

	   	   case FALL_EDGE:
	   		   CLR_BIT(MEXTI_MCUCSR_Register,ISC2);
	   			   break;
	   	   case RISE_EDGE:
	   		   SET_BIT(MEXTI_MCUCSR_Register,ISC2);
	   			   break;
	   	   }

   	   break;
   }
}
void MEXTI_voidDisable_Int(u8 copy_u8IntID)
{
  switch(copy_u8IntID)
  {
  case INT0_ID:
       CLR_BIT(MEXTI_GICR_Register,INT0);
       break;
  case INT1_ID:
       CLR_BIT(MEXTI_GICR_Register,INT1);
        break;
  case INT2_ID:
        CLR_BIT(MEXTI_GICR_Register,INT2);
        break;
  }
}
void MEXTI_setCallBack_INT0(void (*copy_ptr_function)(void))
{

	global_ptrf_INT0 = copy_ptr_function;
}
void MEXTI_setCallBack_INT1(void (*copy_ptr_function)(void))
{
	global_ptrf_INT1 = copy_ptr_function;
}
void MEXTI_setCallBack_INT2(void (*copy_ptr_function)(void))
{
	global_ptrf_INT2 = copy_ptr_function;
}
ISR(INT0_vect)
{
	global_ptrf_INT0();
}
ISR(INT1_vect)
{
	global_ptrf_INT1();
}
ISR(INT2_vect)
{
	global_ptrf_INT2();
}
