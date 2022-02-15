/*
 * MADC_config.h
 *
 *  Created on: Oct 19, 2021
 *      Author: Omar
 */

#ifndef MCAL_MADC_MADC_CONFIG_H_
#define MCAL_MADC_MADC_CONFIG_H_

/*PRESCALER OPTIONS
MADC_PRESCALER_2
MADC_PRESCALER_4
MADC_PRESCALER_8
MADC_PRESCALER_16
MADC_PRESCALER_32
MADC_PRESCALER_64
MADC_PRESCALER_128
*/


#define MADC_PRESCALER			MADC_PRESCALER_8

/* vref options*
MADC_VREF_INTERNAL
MADC_VREF_AVCC
MADC_VREF_AREF
*/

#define MADC_VREF				MADC_VREF_AVCC


#endif /* MCAL_MADC_MADC_CONFIG_H_ */