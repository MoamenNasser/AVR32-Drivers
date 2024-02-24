/*
 * MDIO_Private.h
 *
 *  Created on: Sep 24, 2021
 *      Author: naser
*/

#ifndef MDIO_PRIVATE_H_
#define MDIO_PRIVATE_H_

/*				PORTA REGISTERS				*/
#define DDRA_REG  *((volatile u8*)0x3A)
#define PORTA_REG *((volatile u8*)0x3B)
#define PINA_REG  *((volatile u8*)0x39)

/*				PORTB REGISTERS				*/
#define DDRB_REG  *((volatile u8*)0x37)
#define PORTB_REG *((volatile u8*)0x38)
#define PINB_REG  *((volatile u8*)0x36)

/*				PORTC REGISTERS				*/
#define DDRC_REG  *((volatile u8*)0x34)
#define PORTC_REG *((volatile u8*)0x35)
#define PINC_REG  *((volatile u8*)0x33)

/*				PORTD REGISTERS				*/
#define DDRD_REG  *((volatile u8*)0x31)
#define PORTD_REG *((volatile u8*)0x32)
#define PIND_REG  *((volatile u8*)0x30)

#endif /* MDIO_PRIVATE_H_ */
