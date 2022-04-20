/*
 * main.c
 *
 *  Created on: Oct 9, 2021
 *      Author: naser
 */

#include"INT_CNF.h"
#include"MEXINT_Interface.h"
#include"MDIO_interface.h"
#include"avr/delay.h"

int main(void)
{
	/***********************************************************************
	 * 					Setting pins directions to inputs
	 * 					in port d for the interrupt pins
	 ************************************************************************/
	MDIO_VoidSetPinDirection(DIO_PORTD,DIO_PIN2,DIO_INPUT);

	MDIO_VoidSetPinDirection(DIO_PORTD,DIO_PIN3,DIO_INPUT);

	MDIO_VoidSetPinDirection(DIO_PORTB,DIO_PIN2,DIO_INPUT);


	/***********************************************************************
	 *
	 * 					Enabling the pull up resistances
	 * 					in port d for the interrupt pins
	 *
	 ************************************************************************/
	MDIO_VoidEnablePullUpResistor(DIO_PORTD,DIO_PIN3);

	MDIO_VoidEnablePullUpResistor(DIO_PORTD,DIO_PIN2);

	MDIO_VoidEnablePullUpResistor(DIO_PORTB,DIO_PIN2);


	/***********************************************************************
	 *
	 * 					Setting pins directions to outputs
	 * 					in port A for the test pins
	 *
	 ************************************************************************/
	MDIO_VoidSetPinDirection(DIO_PORTA,DIO_PIN0,DIO_OUTPUT);

	MDIO_VoidSetPinDirection(DIO_PORTA,DIO_PIN1,DIO_OUTPUT);

	MDIO_VoidSetPinDirection(DIO_PORTA,DIO_PIN2,DIO_OUTPUT);

	MDIO_VoidSetPinDirection(DIO_PORTA,DIO_PIN3,DIO_OUTPUT);


	/***********************************************************************
	 *
	 * 					Initialize the interrupt pins
	 *
	 ************************************************************************/
	MEXINT0_VoidInit();
	MEXINT1_VoidInit();
	MEXINT2_VoidInit();



	/***********************************************************************
	 *
	 * 					Enabling the interrupt pins
	 *
	 ************************************************************************/
	ENABLE_INT0();
	ENABLE_INT1();
	ENABLE_INT2();


	/***********************************************************************
	 *
	 * 					Enabling the general interrupt pins
	 *
	 ************************************************************************/
	ENABLE_GIE();

	while(1)
	{
		_delay_ms(1000);
		MDIO_VoidSetPinValue(DIO_PORTA, DIO_PIN1,DIO_PIN_HIGH);
		_delay_ms(300);
		MDIO_VoidSetPinValue(DIO_PORTA, DIO_PIN1,DIO_PIN_LOW);
		_delay_ms(300);

		MDIO_VoidSetPinValue(DIO_PORTA, DIO_PIN2,DIO_PIN_HIGH);
		_delay_ms(300);

		MDIO_VoidSetPinValue(DIO_PORTA, DIO_PIN2,DIO_PIN_LOW);
		_delay_ms(300);
	}


	return 0;
}
