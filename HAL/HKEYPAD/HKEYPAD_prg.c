/*
 * HKEYPAD_prg.c


 *
 *  Created on: Oct 10, 2021
 *      Author: aya_enan
 */
#include <util/delay.h>
#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "HKEYPAD_private.h"
#include "HKEYPAD_config.h"
#include "HKEYPAD_interface.h"

void HKEYPAD_voidInit(void)
{
   /*step 1 : config Col pins as output*/
	DIO_u8SetPinDirection(COL_PORT,COL_PIN0,DIO_u8_OUTPUT);
	DIO_u8SetPinDirection(COL_PORT,COL_PIN1,DIO_u8_OUTPUT);
	DIO_u8SetPinDirection(COL_PORT,COL_PIN2,DIO_u8_OUTPUT);
	DIO_u8SetPinDirection(COL_PORT,COL_PIN3,DIO_u8_OUTPUT);
   /*step 2 : config Rows pins as inputs , pull ups*/
	DIO_u8SetPinDirection(ROW_PORT,ROW_PIN0,DIO_u8_INPUT_PULLED_UP);
	DIO_u8SetPinDirection(ROW_PORT,ROW_PIN1,DIO_u8_INPUT_PULLED_UP);
	DIO_u8SetPinDirection(ROW_PORT,ROW_PIN2,DIO_u8_INPUT_PULLED_UP);
	DIO_u8SetPinDirection(ROW_PORT,ROW_PIN3,DIO_u8_INPUT_PULLED_UP);
   /*step 3 : Initialize Col pins -> HIGH*/
	DIO_u8SetPinValue(COL_PORT,COL_PIN0,DIO_u8_HIGH);
	DIO_u8SetPinValue(COL_PORT,COL_PIN1,DIO_u8_HIGH);
	DIO_u8SetPinValue(COL_PORT,COL_PIN2,DIO_u8_HIGH);
	DIO_u8SetPinValue(COL_PORT,COL_PIN3,DIO_u8_HIGH);
}
u8 HKEYPAD_u8GetPressedKey(void)
{
	u8 LOC_u8ReturnVal = HKEYPAD_NO_PRESSED_KEY;
	u8 col_indx;
	u8 row_indx;
	u8 Pin_State;
	u8 LOC_u8HKEYPAD_Arr[HKEYPAD_ROWS][HKEYPAD_COL]=  HKEYPAD_VALUES;
   for(col_indx=COL_S;col_indx<COL_MAX;col_indx++ )
   {
	   /*select column and output low*/
	   DIO_u8SetPinValue(COL_PORT,col_indx,DIO_u8_LOW);
	   for(row_indx = ROW_S;row_indx<ROW_MAX;row_indx++)
	   {
           DIO_u8GetPinValue( ROW_PORT,row_indx,&Pin_State);
           if(Pin_State == 0) /*if true -> PB is pressed*/
           {
        	   LOC_u8ReturnVal =  LOC_u8HKEYPAD_Arr[row_indx-ROW_S][col_indx-COL_S];
        	   /*busy waiting loop*/
        	   while(Pin_State == 0)
        	   {
        		   DIO_u8GetPinValue( ROW_PORT,row_indx,&Pin_State);
        	   }
        	   /*debouncing button */
        	   _delay_ms(10);
           }
	   }
	   DIO_u8SetPinValue(COL_PORT,col_indx,DIO_u8_HIGH);
   }
   return LOC_u8ReturnVal;
}
