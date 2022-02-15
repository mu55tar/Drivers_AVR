/*
 * HLCD_prg.c
 *
 *  Created on: Oct 11, 2021
 *      Author: aya_enan
 */
#include <util/delay.h>
#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "HLCD_private.h"
#include "HLCD_config.h"
#include "HLCD_interface.h"
void HLCD_voidInit(void)
{
   /*step 1 : config data port*/
#if(FUNCTION_SET == FUNCTION_SET_8BIT_MODE_2LINES || FUNCTION_SET == FUNCTION_SET_8BIT_MODE_1LINES)
	DIO_u8SetPortDirection(PORT_DATA,DIO_u8_OUTPUT);
#elif(FUNCTION_SET == FUNCTION_SET_4BIT_MODE_2LINES || FUNCTION_SET ==  FUNCTION_SET_4BIT_MODE_1LINES)
	DIO_u8SetPinDirection(PORT_DATA,HLCD_D4_PIN,DIO_u8_OUTPUT);
	DIO_u8SetPinDirection(PORT_DATA,HLCD_D5_PIN,DIO_u8_OUTPUT);
	DIO_u8SetPinDirection(PORT_DATA,HLCD_D6_PIN,DIO_u8_OUTPUT);
	DIO_u8SetPinDirection(PORT_DATA,HLCD_D7_PIN,DIO_u8_OUTPUT);
#endif
	/*step : config PORT CONTROL*/
	DIO_u8SetPinDirection(PORT_CONTROL,HLCD_RS_PIN,DIO_u8_OUTPUT);
//	DIO_u8SetPinDirection(PORT_CONTROL,HLCD_RW_PIN,DIO_u8_OUTPUT);
	DIO_u8SetPinDirection(PORT_CONTROL,HLCD_E_PIN,DIO_u8_OUTPUT);
#if(FUNCTION_SET == FUNCTION_SET_8BIT_MODE_2LINES || FUNCTION_SET == FUNCTION_SET_8BIT_MODE_1LINES)
	/*step 2: LCD initialization */
	_delay_ms(30);
	HLCD_voidSendCommand(FUNCTION_SET);
	_delay_ms(2);
	HLCD_voidSendCommand(DISPLAY_ON_OFF);
	_delay_ms(2);
	HLCD_voidSendCommand(CLEAR_DISPLAY);
	_delay_ms(2);
	HLCD_voidSendCommand(ENTRY_MODE_SET);
	_delay_ms(2);
#elif(FUNCTION_SET == FUNCTION_SET_4BIT_MODE_2LINES || FUNCTION_SET ==  FUNCTION_SET_4BIT_MODE_1LINES)
	_delay_ms(30);
	HLCD_voidSendCommand(FUNCTION_SET & 0xF0);
	HLCD_voidSendCommand(FUNCTION_SET & 0xF0);
	HLCD_voidSendCommand(FUNCTION_SET << 4);
	_delay_ms(2);
	HLCD_voidSendCommand(DISPLAY_ON_OFF &  0xF0);
	HLCD_voidSendCommand(DISPLAY_ON_OFF << 4);
	_delay_ms(2);
	HLCD_voidSendCommand(CLEAR_DISPLAY &  0xF0);
	HLCD_voidSendCommand(CLEAR_DISPLAY << 4);
	_delay_ms(2);
	HLCD_voidSendCommand(ENTRY_MODE_SET &  0xF0);
	HLCD_voidSendCommand(ENTRY_MODE_SET << 4);
	_delay_ms(2);
#endif
}
void HLCD_voidSendCommand(u8 copy_u8Instruction)
{
	/*step 1: select RS to be in command mode*/
	DIO_u8SetPinValue(PORT_CONTROL,HLCD_RS_PIN,DIO_u8_LOW);
	/*step 2: select R/w to be write*/
//	DIO_u8SetPinValue(PORT_CONTROL,HLCD_RW_PIN,DIO_u8_LOW);
    /*step 3 : send Instruction*/
#if(FUNCTION_SET == FUNCTION_SET_8BIT_MODE_2LINES || FUNCTION_SET == FUNCTION_SET_8BIT_MODE_1LINES)
    DIO_u8SetPortValue(PORT_DATA,copy_u8Instruction);
#elif(FUNCTION_SET == FUNCTION_SET_4BIT_MODE_2LINES || FUNCTION_SET ==  FUNCTION_SET_4BIT_MODE_1LINES)
    DIO_void_Set4Bits_Value(PORT_DATA, copy_u8Instruction);
#endif
    /*step 4: Enable E pin */
	DIO_u8SetPinValue(PORT_CONTROL,HLCD_E_PIN,DIO_u8_HIGH);
	_delay_ms(5);
	/*step 5 : Disable E pin */
	DIO_u8SetPinValue(PORT_CONTROL,HLCD_E_PIN,DIO_u8_LOW);

}
void HLCD_voidSendData(u8 copy_u8Data)
{
	/*step 1: select RS to be in data mode*/
	DIO_u8SetPinValue(PORT_CONTROL,HLCD_RS_PIN,DIO_u8_HIGH);
	/*step 2: select R/w to be write*/
//	DIO_u8SetPinValue(PORT_CONTROL,HLCD_RW_PIN,DIO_u8_LOW);
#if(FUNCTION_SET == FUNCTION_SET_8BIT_MODE_2LINES || FUNCTION_SET == FUNCTION_SET_8BIT_MODE_1LINES)
	/*step 3 : send data*/
	DIO_u8SetPortValue(PORT_DATA,copy_u8Data);

	/*step 4: Enable E pin */
	DIO_u8SetPinValue(PORT_CONTROL,HLCD_E_PIN,DIO_u8_HIGH);
	_delay_ms(5);
	/*step 5 : Disable E pin */
	DIO_u8SetPinValue(PORT_CONTROL,HLCD_E_PIN,DIO_u8_LOW);
#elif(FUNCTION_SET == FUNCTION_SET_4BIT_MODE_2LINES || FUNCTION_SET ==  FUNCTION_SET_4BIT_MODE_1LINES)
	/*send high nibble*/
    u8 temp = copy_u8Data;
    temp = temp & 0xF0;
	DIO_void_Set4Bits_Value(PORT_DATA,temp);//HIGH

	/*step 4: Enable E pin */
	DIO_u8SetPinValue(PORT_CONTROL,HLCD_E_PIN,DIO_u8_HIGH);
	_delay_ms(5);
	/*step 5 : Disable E pin */
	DIO_u8SetPinValue(PORT_CONTROL,HLCD_E_PIN,DIO_u8_LOW);

	/*send low nibble*/
	copy_u8Data = (copy_u8Data & 0x0F)<< 4;
	DIO_void_Set4Bits_Value(PORT_DATA,copy_u8Data);//Low

	/*step 4: Enable E pin */
	DIO_u8SetPinValue(PORT_CONTROL,HLCD_E_PIN,DIO_u8_HIGH);
	_delay_ms(5);
	/*step 5 : Disable E pin */
	DIO_u8SetPinValue(PORT_CONTROL,HLCD_E_PIN,DIO_u8_LOW);
#endif
}
void HLCD_voidSendString(u8 *PtrToString)
{
	u8 i = 0;
	while(PtrToString[i] != '\0')
	{
		HLCD_voidSendData(PtrToString[i]);
		i++;
	}

}
void HLCD_voidSendNumber(u32 copy_u8Number)
{
   u8 LOC_NumStr[10];
   u8 i=0,j;
   while(copy_u8Number != 0)
   {
	   LOC_NumStr[i] = copy_u8Number%10 ;
	   i++;
	   copy_u8Number /= 10;
   }
   for(j=i-1;j>=0;j--)
   {
	   HLCD_voidSendData(LOC_NumStr[j] + '0');
	   if(j == 0)break;
   }


}
void HLCD_voidClearDisplay()
{
#if(FUNCTION_SET == FUNCTION_SET_8BIT_MODE_2LINES || FUNCTION_SET == FUNCTION_SET_8BIT_MODE_1LINES)
	HLCD_voidSendCommand(CLEAR_DISPLAY);
#elif(FUNCTION_SET == FUNCTION_SET_4BIT_MODE_2LINES || FUNCTION_SET ==  FUNCTION_SET_4BIT_MODE_1LINES)
	HLCD_voidSendCommand(CLEAR_DISPLAY & 0xF0 );
	HLCD_voidSendCommand(CLEAR_DISPLAY << 4 );
#endif
}
void HLCD_voidSetPosition(u8 copy_rowIndx,u8 copy_colIndx)
{
#if(FUNCTION_SET == FUNCTION_SET_8BIT_MODE_2LINES || FUNCTION_SET == FUNCTION_SET_8BIT_MODE_1LINES)
		if(copy_colIndx >= 0 && copy_colIndx <= 15)
		{
          switch(copy_rowIndx)
          {
          case 0:
        	  HLCD_voidSendCommand(SET_DDRAM_ADDRESS + copy_colIndx);
        	  break;
          case 1:
        	  HLCD_voidSendCommand(SET_DDRAM_ADDRESS + HLCD_SECOND_ROW_ADDRESS_OFFSET+ copy_colIndx);
        	  break;

          }

	   }
#elif(FUNCTION_SET == FUNCTION_SET_4BIT_MODE_2LINES || FUNCTION_SET ==  FUNCTION_SET_4BIT_MODE_1LINES)
		if(copy_colIndx >= 0 && copy_colIndx <= 15)
			{
			  switch(copy_rowIndx)
			  {
			  case 0:
				  HLCD_voidSendCommand((SET_DDRAM_ADDRESS + copy_colIndx) & 0xF0);
				  HLCD_voidSendCommand((SET_DDRAM_ADDRESS + copy_colIndx) << 4);
				  break;
			  case 1:
				  HLCD_voidSendCommand((SET_DDRAM_ADDRESS + HLCD_SECOND_ROW_ADDRESS_OFFSET+ copy_colIndx) & 0xF0);
				  HLCD_voidSendCommand((SET_DDRAM_ADDRESS + HLCD_SECOND_ROW_ADDRESS_OFFSET+ copy_colIndx)<< 4);
				  break;

			  }

		   }
#endif
}
void HLCD_voidSendCustomized(u8 * PtrCustomChar,u8 copy_CharID)
{
#if(FUNCTION_SET == FUNCTION_SET_8BIT_MODE_2LINES || FUNCTION_SET == FUNCTION_SET_8BIT_MODE_1LINES)
	u8 i;

	/*set AC to point to CGRAM address*/
	 HLCD_voidSendCommand(SET_CGRAM_ADDRESS + copy_CharID * 8);

	 /*send character pattern to be written in CGRAM */
	 for(i=0;i<7;i++)
	 {
		 HLCD_voidSendData(PtrCustomChar[i]);
	 }
	 /*return AC to point to DDRAM address*/
	 HLCD_voidSendCommand(SET_DDRAM_ADDRESS);
#elif(FUNCTION_SET == FUNCTION_SET_4BIT_MODE_2LINES || FUNCTION_SET ==  FUNCTION_SET_4BIT_MODE_1LINES)

	 u8 i;

	 	/*set AC to point to CGRAM address*/
	 	 HLCD_voidSendCommand((SET_CGRAM_ADDRESS + copy_CharID * 8) & 0xF0);
	 	HLCD_voidSendCommand((SET_CGRAM_ADDRESS + copy_CharID * 8) << 4);
	 	 /*send character pattern to be written in CGRAM */
	 	 for(i=0;i<7;i++)
	 	 {
	 		 HLCD_voidSendData(PtrCustomChar[i]);
	 	 }
	 	 /*return AC to point to DDRAM address*/
	 	 HLCD_voidSendCommand(SET_DDRAM_ADDRESS & 0xF0);
	 	HLCD_voidSendCommand(SET_DDRAM_ADDRESS << 4);
#endif
}
void HLCD_voidprintCustomized(u8 copy_CharID)
{
	HLCD_voidSendData(copy_CharID);
}
