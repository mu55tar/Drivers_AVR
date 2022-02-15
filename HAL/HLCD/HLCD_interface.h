/*
 * HLCD_interface.h
 *
 *  Created on: Oct 11, 2021
 *      Author: aya_enan
 */

#ifndef HLCD_HLCD_INTERFACE_H_
#define HLCD_HLCD_INTERFACE_H_

typedef struct Custom_Char
{
   u8 Char_Pattern[7];
   u8 CharID;
}CustomChar_t;
void HLCD_voidInit(void);
void HLCD_voidSendCommand(u8 copy_u8Instruction);
void HLCD_voidSendData(u8 copy_u8Data);// Ascii
void HLCD_voidSendString(u8 *PtrToString);
void HLCD_voidSendNumber(u32 copy_u8Number);//decimal
void HLCD_voidSetPosition(u8 copy_rowIndx,u8 copy_colIndx);
void HLCD_voidClearDisplay(void);

void HLCD_voidSendCustomized(u8 * PtrCustomChar,u8 copy_CharID);
void HLCD_voidprintCustomized(u8 copy_CharID);
#endif /* HLCD_HLCD_INTERFACE_H_ */
