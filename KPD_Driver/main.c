/*
 * main.c
 *
 *  Created on: Sep 25, 2021
 *      Author: naser
 */


#include"STD_TYPES.h"
#include"MDIO_interface.h"
#include"HLCD_Interface.h"
#include"HKPD_Interface.h"
#include<avr/delay.h>

int main(void)
{

	MDIO_VoidSetPinDirection(DIO_PORTC,DIO_PIN6,1);

	while(1)
	{
		MDIO_VoidSetPinValue(DIO_PORTC,DIO_PIN6,1);
		_delay_ms(1000);
		MDIO_VoidSetPinValue(DIO_PORTC,DIO_PIN6,0);
		_delay_ms(1000);

	}
/*
	HLCD_enuInit();
	HKPD_enuInit();
	HLCD_GoToXY(0,0);

	u32 PRESSED;
	while(1)
	{

		PRESSED = HKPD_u8GetPressedKey();
		if(PRESSED != 50)
		{
			HLCD_SendNumber(PRESSED);
		}


	}
*/
	return 0;
}
