/*
 * HSSD_interface.h
 *
 *  Created on: Oct 10, 2021
 *      Author: aya_enan
 */

#ifndef HSSD_HSSD_INTERFACE_H_
#define HSSD_HSSD_INTERFACE_H_



/*
 * SSD Types
 */
//common anode
#define HSSD_CA_TYPE  0
//common cathode
#define HSSD_CC_TYPE  1
/*
 * pre request : configure SSD port as output
 * function inputs:
 *                  copy_u8Number -> number to be displayed
 *                  copy_u8Port   -> Port connected to SSD
 *                  copy_u8Type   -> choose : HSSD_CA_TYPE
 *                                            HSSD_CC_TYPE
 * function output: void
 */
void HSSD_voidSetNumber(u8 copy_u8Number,u8 copy_u8Port,u8 copy_u8Type);
void HSSD_BCD_voidSetNumber(u8 copy_u8Number,u8 copy_u8Port);
#endif /* HSSD_HSSD_INTERFACE_H_ */
