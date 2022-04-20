/*
 * MDIO_interface.h
 *
 *  Created on: Sep 24, 2021
 *      Author: naser
 */

#ifndef MDIO_INTERFACE_H_
#define MDIO_INTERFACE_H_

#include"STD_TYPES.h"
#include"BIT_MATH.h"
/*						Define all ports						*/
#define DIO_PORTA            0
#define DIO_PORTB            1
#define DIO_PORTC            2
#define DIO_PORTD            3
/*					Define Each Pin in port						*/
#define DIO_PIN0              0
#define DIO_PIN1              1
#define DIO_PIN2              2
#define DIO_PIN3              3
#define DIO_PIN4              4
#define DIO_PIN5              5
#define DIO_PIN6       	   	  6
#define DIO_PIN7        	  7
/*					Port input and output macros				*/
#define DIO_PORT_INPUT         0x00
#define DIO_PORT_OUTPUT        0xFF
/*					Pin input and output macros					*/
#define DIO_PIN_INPUT         0x00
#define DIO_PIN_OUTPUT        0x01
/*					DIO high and low  macros					*/
#define DIO_HIGH         	   0x01
#define DIO_LOW                0x00
/*					Port and pin high macros					*/
#define DIO_PORT_HIGH          0xFF
#define DIO_PIN_HIGH		   0x01
/*					Port and pin low macros						*/
#define DIO_PORT_LOW           0x00
#define DIO_PIN_LOW	 	       0x00

#define DIO_UNDEFINED_VAL      0xFF


void MDIO_VoidSetPinDirection(u8 Copy_u8Port ,u8 Copy_u8Pin, u8 Copy_u8Direc);
void MDIO_VoidSetPinValue(u8 Copy_u8Port ,u8 Copy_u8Pin, u8 Copy_u8Value);
u8 MDIO_u8GetPinValue(u8 Copy_u8Port ,u8 Copy_u8Pin);
void MDIO_VoidSetPortDirection(u8 Copy_u8Port, u8 Copy_u8Direc);
void MDIO_VoidSetPortValue(u8 Copy_u8Port ,u8 Copy_u8Value);
void MDIO_VoidTogglePin(u8 Copy_u8Port ,u8 Copy_u8Pin);
void MDIO_VoidEnablePullUpResistor(u8 Copy_u8Port,u8 Copy_u8Pin);




#endif /* MDIO_INTERFACE_H_ */
