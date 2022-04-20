/*
 * main.c
 *
 *  Created on: Nov 3, 2021
 *      Author: naser
 */
#include"STD_TYPES.h"
#include"UART_Interface.h"
#include"HLCD_Interface.h"
#include"MDIO_interface.h"
#include"MDIO_Private.h"
#include"avr/delay.h"

int main(void)
{
	HLCD_enuInit();
	HLCD_ClearDisplay();
	MDIO_VoidSetPinDirection(DIO_PORTA,DIO_PIN0,1);
	UART_VoidInit();

	while(1)
	{
		u8 Local_Variable = UART_VoidReceiver();
		if(Local_Variable == 'a')
		{

			MDIO_VoidSetPinValue(DIO_PORTA,DIO_PIN0,DIO_PIN_HIGH);
			/**/
			UART_VoidTransmitter(Local_Variable);
			_delay_ms(200);
			HLCD_GoToXY(1,1);
			HLCD_VoidWriteStr("LED IS ON");
			UART_VoidSendString("LEDON");
			_delay_ms(200);

		}
		else if (Local_Variable == 'b')
		{
			/**/
			MDIO_VoidSetPinValue(DIO_PORTA,DIO_PIN0,DIO_PIN_LOW);
			UART_VoidTransmitter(Local_Variable);
			_delay_ms(200);
			HLCD_ClearDisplay();
			HLCD_GoToXY(1,1);
			HLCD_VoidWriteStr("LED IS ON");
			UART_VoidSendString("LEDOFF");
			_delay_ms(200);

		}
	}
	/*
	u8 * str[100] = {0};
	UART_VoidSendString("Moamen Nasser");
	UART_VoidReceiveString(str);
	HLCD_VoidWriteStr(str);
	*/
	return 0;
}
