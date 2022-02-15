/***********************************************************************************/
/*                          Name : Karim Seif                                      */
/*                          Date : 6/10/2021                                       */
/*                          SWC  : DIO                                             */
/*                       Version : 1.0V                                            */
/***********************************************************************************/
#ifndef DIO_PRIVATE_H
#define DIO_PRIVATE_H

/* Registers Definations */
/* PORTA Registers */
#define DIO_u8_PORTA_REG                          *((volatile u8*)0x3B)
#define DIO_u8_DDRA_REG                           *((volatile u8*)0x3A)
#define DIO_u8_PINA_REG                           *((volatile u8*)0x39)
													  
/* PORTB Registers */                                 
#define DIO_u8_PORTB_REG                          *((volatile u8*)0x38)
#define DIO_u8_DDRB_REG                           *((volatile u8*)0x37)
#define DIO_u8_PINB_REG                           *((volatile u8*)0x36)
													  
/* PORTC Registers */                                 
#define DIO_u8_PORTC_REG                          *((volatile u8*)0x35)
#define DIO_u8_DDRC_REG                           *((volatile u8*)0x34)
#define DIO_u8_PINC_REG                           *((volatile u8*)0x33)
													  
/* PORTD Registers */                                 
#define DIO_u8_PORTD_REG                          *((volatile u8*)0x32)
#define DIO_u8_DDRD_REG                           *((volatile u8*)0x31)
#define DIO_u8_PIND_REG                           *((volatile u8*)0x30)


#define DIO_u8_INIT_INPUT                             0
#define DIO_u8_INIT_OUTPUT                            1

#define DIO_u8_INIT_OUTPUT_LOW                        0
#define DIO_u8_INIT_OUTPUT_HIGH                       1
#define DIO_u8_INIT_INPUT_FLOATING                    0
#define DIO_u8_INIT_INPUT_PULLED_UP                   1

/* Conc function */
#define PRIVATE_CONC(b7,b6,b5,b4,b3,b2,b1,b0)               PRIVATE_CONC_HELP(b7,b6,b5,b4,b3,b2,b1,b0)
#define PRIVATE_CONC_HELP(b7,b6,b5,b4,b3,b2,b1,b0)          0b##b7##b6##b5##b4##b3##b2##b1##b0


#endif
