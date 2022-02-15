/*
 * MADC_program.c
 *
 *  Created on: Oct 19, 2021
 *      Author: Omar
 */

#include <avr/interrupt.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "MADC_config.h"
#include "MADC_interface.h"
#include "MADC_private.h"

void MADC_voidInit(void)
{
	// Configure Prescaler
	MADC_ADCSRA_REG &= MADC_PRESCALLLER_MASK;
	MADC_ADCSRA_REG |= MADC_PRESCALER;

	// Vref Select
	MADC_ADMUX_REG &= MADC_VREF_MASK;
	MADC_ADMUX_REG |= MADC_VREF <<6 ;

	// Disable interrupt
	CLR_BIT(MADC_ADCSRA_REG,ADCSRA_ADIE);

	// Configure Adjustment to be right
	CLR_BIT(MADC_ADMUX_REG,ADMUX_ADLAR);

	// Enable ADC
	SET_BIT(MADC_ADCSRA_REG,ADCSRA_ADEN);

}
u16 MADC_voidADCread(u8 Copy_ADCchannel)
{
	u16 ADC_Digital_Value;

	// Choose Channel
	MADC_ADMUX_REG &= CHANNEL_MASK;
	MADC_ADMUX_REG |= Copy_ADCchannel;//Don't need to be shifted

	// Start Conversion
	SET_BIT(MADC_ADCSRA_REG,ADCSRA_ADSC);

	// wait until conversion is complete
	while(GET_BIT(MADC_ADCSRA_REG,ADCSRA_ADIF) == 0); //Polling

	// read value
	ADC_Digital_Value = MADC_ADCL_REG + (MADC_ADCH_REG << 8);

	// return value
	return ADC_Digital_Value;

}
