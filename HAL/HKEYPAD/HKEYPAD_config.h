/*
 * HKEYPAD_config.h
 *
 *  Created on: Oct 10, 2021
 *      Author: aya_enan
 */

#ifndef HKEYPAD_HKEYPAD_CONFIG_H_
#define HKEYPAD_HKEYPAD_CONFIG_H_

#define HKEYPAD_ROWS 4
#define HKEYPAD_COL  4


#define COL_S   2
#define COL_MAX 6

#define ROW_S   4
#define ROW_MAX 8

#define COL_PORT  DIO_u8_PORTD
#define ROW_PORT  DIO_u8_PORTB

#define COL_PIN0  DIO_u8_PIN2
#define COL_PIN1  DIO_u8_PIN3
#define COL_PIN2  DIO_u8_PIN4
#define COL_PIN3  DIO_u8_PIN5

#define ROW_PIN0  DIO_u8_PIN4
#define ROW_PIN1  DIO_u8_PIN5
#define ROW_PIN2  DIO_u8_PIN6
#define ROW_PIN3  DIO_u8_PIN7

#define HKEYPAD_VALUES {{'7','8','9','/'},{'4','5','6','x'},{'1','2','3','-'},{'O','0','=','+'}}
#endif /* HKEYPAD_HKEYPAD_CONFIG_H_ */
