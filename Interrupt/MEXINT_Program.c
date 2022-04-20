/*
 * MEXINT_Program.c
 *
 *  Created on: Oct 9, 2021
 *      Author: naser
 */

#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"MEXINT_Interface.h"
#include"MEXINT_Private.h"
#include"MDIO_interface.h"
#include"avr/delay.h"


/*************************************************************************************
 *
 *
 *
 * ***********************************************************************************/
void __vector_0(void)
{



}


/*************************************************************************************
 *
 *						Code for vector number 2
 *
 * ***********************************************************************************/
void __vector_1(void)
{
	MDIO_VoidSetPinValue(DIO_PORTA, DIO_PIN0,DIO_PIN_HIGH);
}


/*************************************************************************************
 *
 *						Code for vector number 2
 *
 * ***********************************************************************************/
void __vector_2(void)
{
	//ENABLE_GIE();

	_delay_ms(300);
	MDIO_VoidSetPinValue(DIO_PORTA,DIO_PIN2,DIO_PIN_HIGH);
	_delay_ms(300);
	MDIO_VoidSetPinValue(DIO_PORTA, DIO_PIN0,DIO_PIN_LOW);
	_delay_ms(300);
	MDIO_VoidSetPinValue(DIO_PORTA,DIO_PIN2,DIO_PIN_LOW);
	_delay_ms(300);
}


/*************************************************************************************
 *
 *						Code for vector number 3
 *
 * ***********************************************************************************/
void __vector_3(void)
{
	//ENABLE_GIE();

	_delay_ms(300);
	MDIO_VoidSetPinValue(DIO_PORTA,DIO_PIN1,DIO_PIN_HIGH);
	_delay_ms(300);
	MDIO_VoidSetPinValue(DIO_PORTA, DIO_PIN0,DIO_PIN_LOW);
	_delay_ms(300);
	MDIO_VoidSetPinValue(DIO_PORTA,DIO_PIN1,DIO_PIN_LOW);
	_delay_ms(300);
}


/*************************************************************************************
 *
 *						Initialize interrupt 0
 *
 * ***********************************************************************************/
void MEXINT0_VoidInit(void)
{
	/*				ISC only 													*/
	SET_BIT(MCUCR,1);
	CLR_BIT(MCUCR,0);
}


/*************************************************************************************
 *
 *						Initialize interrupt 1
 *
 * ***********************************************************************************/
void MEXINT1_VoidInit(void)
{
	SET_BIT(MCUCR,3);
	CLR_BIT(MCUCR,2);
}


/*************************************************************************************
 *
 *						Initialize interrupt 2
 *
 * ***********************************************************************************/
void MEXINT2_VoidInit(void)
{
	SET_BIT(MCUCR,6);

}


/*************************************************************************************
 *
 * 						Enabling the interrupt number 0
 *
 *************************************************************************************/
void ENABLE_INT0(void)
{
	SET_BIT(GICR,6);
}


/*************************************************************************************
 *
 * 						Disabling the interrupt number 0
 *
 *************************************************************************************/
void DISABLE_INT0(void)
{

	CLR_BIT(GICR,6);
}


/*************************************************************************************
 *
 * 						Enabling The Global interrupt enable
 *
 *************************************************************************************/
void ENABLE_GIE(void)
{
	SET_BIT(SREG,7);
}


/*************************************************************************************
 *
 * 						DISABLING The Global interrupt enable
 *
 **************************************************************************************/
void DISABLE_GIE(void)
{
	CLR_BIT(SREG,7);
}


/*************************************************************************************
 *
 * 						Enabling the interrupt number 1
 *
 **************************************************************************************/
void ENABLE_INT1(void)
{
	SET_BIT(GICR,7);
}


/* **************************************************************************************
 *
 * 						Disabling the interrupt number 1
 *
 * ***************************************************************************************/
void DISABLE_INT1(void)
{
	CLR_BIT(GICR,7);
}


/***************************************************************************************
 *
 * 						Enabling the interrupt number 2
 *
 ****************************************************************************************/
void ENABLE_INT2(void)
{
	SET_BIT(GICR,5);
}


/***************************************************************************************
 *
 * 						Disabling the interrupt number 2
 *
 ****************************************************************************************/
void DISABLE_INT2(void)
{
	CLR_BIT(GICR,5);
}
