/***********************************************************************************/
/*                          Name : Karim Seif                                      */
/*                          Date : 6/10/2021                                       */
/*                          SWC  : DIO                                             */
/*                       Version : 1.0V                                            */
/***********************************************************************************/
#ifndef DIO_INTERFACE_H
#define DIO_INTERFACE_H

/* Public Macros */
/* Port Id Macros */
#define DIO_u8_PORTA                      0
#define DIO_u8_PORTB                      1
#define DIO_u8_PORTC                      2
#define DIO_u8_PORTD                      3

/*typedef enum{
	DIO_u8_PORTA=0,
	DIO_u8_PORTB,
	DIO_u8_PORTC,
	DIO_u8_PORTD
}PortId_t;*/

/* Pin Id Macros */
#define DIO_u8_PIN0                       0
#define DIO_u8_PIN1                       1
#define DIO_u8_PIN2                       2
#define DIO_u8_PIN3                       3
#define DIO_u8_PIN4                       4
#define DIO_u8_PIN5                       5
#define DIO_u8_PIN6                       6
#define DIO_u8_PIN7                       7

/* Direction Macros */
#define DIO_u8_INPUT_FLOATING             0
#define DIO_u8_OUTPUT                     1
#define DIO_u8_INPUT_PULLED_UP            2

/* Value Macros */
#define DIO_u8_LOW                        0
#define DIO_u8_HIGH                       1

/* Prototypes of Public Functions */

void DIO_voidInit         (void);

u8 DIO_u8SetPinDirection  (u8 Copy_u8PortId,u8 Copy_u8PinId,u8 Copy_u8PinDirection);
						  
u8 DIO_u8SetPinValue      (u8 Copy_u8PortId,u8 Copy_u8PinId,u8 Copy_u8PinValue);
						  
u8 DIO_u8GetPinValue      (u8 Copy_u8PortId,u8 Copy_u8PinId,u8 * Copy_Pu8ReturnedValue);
						  
u8 DIO_u8TogPinValue      (u8 Copy_u8PortId,u8 Copy_u8PinId);

u8 DIO_u8SetPortDirection (u8 Copy_u8PortId,u8 Copy_u8PortDirection);

u8 DIO_u8SetPortValue     (u8 Copy_u8PortId,u8 Copy_u8PortValue);

u8 DIO_u8GetPortValue     (u8 Copy_u8PortId,u8 * Copy_Pu8ReturnedPortValue);

void DIO_void_Set4Bits_Value(u8 Copy_u8PortId, u8 Copy_u8PortValue);


#endif
