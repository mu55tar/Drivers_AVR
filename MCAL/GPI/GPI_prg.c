/*
 * GPI_prg.c
 *
 *  Created on: Oct 18, 2021
 *      Author: aya_enan
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GPI_private.h"
#include "GPI_interface.h"
void GPI_voidEnable(void)
{
   SET_BIT(GPI_SREG,GPI_I_BIT);
}
void GPI_voidDisable(void)
{
  CLR_BIT(GPI_SREG,GPI_I_BIT);
}
