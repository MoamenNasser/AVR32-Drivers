/*
 * HKPD_Program.c
 *
 *  Created on: Sep 25, 2021
 *      Author: naser
 */

#include"STD_TYPES.h"
#include<avr/delay.h>
#include "HLCD_CNF.h"
#include"MDIO_interface.h"
#include"HLCD_Interface.h"

/**********************************
 *
 * 		This function initialize the Keypad
 *
 ***********************************/
void HKPD_enuInit(void)
{

	MDIO_VoidSetPortDirection(DIO_PORTA,0b11110000);
	MDIO_VoidSetPortValue(DIO_PORTA,0xFF);

}

/***********************************
 *
 * 		This function get the pressed key
 *
 ***********************************/
u8 HKPD_u8GetPressedKey(void)
{
	u8 Copy_u8PressedKey = 50;
	for(u8 column = 0; column <= 3; column++)
	{
		MDIO_VoidSetPinValue(DIO_PORTA,4+column,0);
		for(u8 row = 0; row <= 3; row++)
		{
			u8 Copy_u8Result;

			Copy_u8Result = MDIO_u8GetPinValue(DIO_PORTA,row);
			if(Copy_u8Result == 0)
			{
				Copy_u8PressedKey = (4*row) + column + 1;

			}
			while(MDIO_u8GetPinValue(DIO_PORTA,row) == 0)
			{

			}
			_delay_ms(10);
		}
		MDIO_VoidSetPinValue(DIO_PORTA,4+column,1);
	}
	return Copy_u8PressedKey;
}



