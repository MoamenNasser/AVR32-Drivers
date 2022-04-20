#include"STD_TYPES.h"
#include"MDIO_Interface.h"
#include <avr/delay.h>

int main(void)
{
	/*
	MDIO_VoidSetPinDirection(DIO_PORTA,DIO_PIN0,DIO_OUTPUT);
	MDIO_VoidSetPinValue(DIO_PORTA,DIO_PIN1,DIO_INPUT);
	*/
	MDIO_VoidSetPinDirection(DIO_PORTC,DIO_PIN0,1);

	MDIO_VoidSetPinDirection(DIO_PORTC,DIO_PIN1,1);

	while(1)
	{
		/*
		MDIO_VoidTogglePin(DIO_PORTA,DIO_PIN5);
		_delay_ms(1000);
		MDIO_VoidTogglePin(DIO_PORTA,DIO_PIN0);
		_delay_ms(1000);
		 */

		MDIO_VoidSetPinValue(DIO_PORTC,DIO_PIN0,1);
		MDIO_VoidSetPinValue(DIO_PORTC,DIO_PIN1,0);
		_delay_ms(1000);
		MDIO_VoidSetPinValue(DIO_PORTC,DIO_PIN0,0);
		MDIO_VoidSetPinValue(DIO_PORTC,DIO_PIN1,1);
		_delay_ms(1000);


	}

	return 0;
}
