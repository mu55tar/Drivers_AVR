/*
 * HTEMP_SENSOR_program.c
 *
 *  Created on: Oct 20, 2021
 *      Author: Omar
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "HTEMP_SENSOR_config.h"
#include "HTEMP_SENSOR_interface.h"
#include "HTEMP_SENSOR_private.h"
#include "MADC_interface.h"



u8 HTEMP_u8ReadTemp() // This will return the Temperature in Celsius
{
	u8 LOC_u8temp; //Celsius
	u16 LOC_u16adc_read = MADC_voidADCread(TEMP_CHANNEL);
	u32 LOC_u32analog_value = ((u32)LOC_u16adc_read * 5000)/1024; // we made casting to the adc read
	LOC_u8temp = LOC_u32analog_value/10;

	return LOC_u8temp;

}
