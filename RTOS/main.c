/*
 * main.c
 *
 *  Created on: Oct 23, 2021
 *      Author: naser
 */

#include"MTimer_Interface.h"
#include"MTimer_CNF.h"
#include"MDIO_interface.h"
# define F_CPU 8000000UL
#include"MEXINT_Interface.h"
#include"avr/delay.h"


void RLED(void)
{
	MDIO_VoidTogglePin(DIO_PORTA,DIO_PIN0);

}

void GLED(void)
{
	MDIO_VoidTogglePin(DIO_PORTA,DIO_PIN1);

}


void BLED(void)
{
	MDIO_VoidTogglePin(DIO_PORTA,DIO_PIN2);

}

int main(void)
{
	MDIO_VoidSetPinDirection(DIO_PORTA,DIO_PIN0,DIO_OUTPUT);
	MDIO_VoidSetPinDirection(DIO_PORTA,DIO_PIN1,DIO_OUTPUT);
	MDIO_VoidSetPinDirection(DIO_PORTA,DIO_PIN2,DIO_OUTPUT);
	CreateTask(&RLED,0,1);
	CreateTask(&GLED,1,2);
	CreateTask(&BLED,2,3);
	OS_start();
	ENABLE_GIE();

	//MDIO_VoidSetPinDirection(DIO_PORTB,DIO_PIN0,DIO_OUTPUT);

	//MDIO_VoidSetPinDirection(DIO_PORTB,DIO_PIN1,DIO_OUTPUT);

	//MDIO_VoidSetPinDirection(DIO_PORTB,DIO_PIN3,DIO_OUTPUT);

	//MTimer0_Init();
	//MTIMER_VoidSetDutyCycle(20);

	//MTimer1_Init();

	//MTimer2_Init();

	//ENABLE_GIE();
	/*					This code to test the watch dog timer							*/
	//MWatchDogTimer_Enable();
	//MDIO_VoidSetPinDirection(DIO_PORTC,DIO_PIN0,DIO_OUTPUT);
	/*					Set Pin to high for LED ON										*/
	/*
	MDIO_VoidSetPinValue(DIO_PORTA,DIO_PIN7,DIO_PIN_HIGH);
	_delay_ms(500);
	MDIO_VoidSetPinValue(DIO_PORTA,DIO_PIN7,DIO_PIN_LOW);
	_delay_ms(300);
	MWatchDogTimer_Disable();
	 */

	// this takes 1 second and force the code to reset
	while(1)
	{

	}


	return 0;

}

