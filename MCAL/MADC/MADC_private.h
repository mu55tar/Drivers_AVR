/*
 * MADC_private.h
 *
 *  Created on: Oct 19, 2021
 *      Author: Omar
 */

#ifndef MCAL_MADC_MADC_PRIVATE_H_
#define MCAL_MADC_MADC_PRIVATE_H_



/*ADC REGISTERS*/
#define MADC_ADMUX_REG				(*((volatile u8* )0x27))
#define MADC_ADCSRA_REG             (*((volatile u8* )0x26))
#define MADC_ADCH_REG               (*((volatile u8* )0x25))
#define MADC_ADCL_REG               (*((volatile u8* )0x24))
#define MADC_SFIOR_REG              (*((volatile u8* )0x50))


/*ADMUX BITS*/
#define ADMUX_REFS1					7
#define ADMUX_REFS0					6
#define ADMUX_ADLAR					5

/*ADCSRA BITS*/
#define ADCSRA_ADEN					7 //ENABLE ADC BIT
#define ADCSRA_ADSC					6 //START CONVERSION BIT
#define ADCSRA_ADATE				5 //ADC AUTO TRIGGER ENABLE
#define ADCSRA_ADIF					4 //CONVERSION COMPLETE FLAG
#define ADCSRA_ADIE					3 //CONVERSION COMPLETE INTERRUPT ENABLE


/*PRESCALER OPTIONS*/
#define MADC_PRESCALER_2			1
#define MADC_PRESCALER_4			2
#define MADC_PRESCALER_8			3
#define MADC_PRESCALER_16			4
#define MADC_PRESCALER_32			5
#define MADC_PRESCALER_64			6
#define MADC_PRESCALER_128			7


/*VREF OPTIONS*/
#define MADC_VREF_INTERNAL			3
#define MADC_VREF_AVCC				1
#define MADC_VREF_AREF				0

#define MADC_VREF_MASK				0b00111111

#define MADC_PRESCALLLER_MASK		0b11111000

#define CHANNEL_MASK				0b11100000

#endif /* MCAL_MADC_MADC_PRIVATE_H_ */
