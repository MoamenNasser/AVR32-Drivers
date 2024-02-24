/*
 * main.c
 *
 *  Created on: Feb 19, 2024
 *      Author: Moamen
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "MDIO_interface.h"
#include "HLCD_Interface.h"
/*		This must be called in any free RTOS application			*/
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"



void LED1(void * pv);
void LED2(void * pv);
void LED3(void * pv);

void LCD1(void * pv);
void LCD2(void * pv);



u8 LCD_FLAG = 0;


xSemaphoreHandle LCDsem;



void main(void)
{


	MDIO_VoidSetPinDirection(DIO_PORTA,DIO_PIN0,DIO_OUTPUT);

	MDIO_VoidSetPinDirection(DIO_PORTA,DIO_PIN1,DIO_OUTPUT);
	MDIO_VoidSetPinDirection(DIO_PORTA,DIO_PIN2,DIO_OUTPUT);


	/*			In this function i handled the port direction for the LCD			*/
	HLCD_enuInit();

	/******************************************************************************************************************
	 *
	 * #define xTaskCreate( pvTaskCode, pcName, usStackDepth, pvParameters, uxPriority, pxCreatedTask ) xTaskGenericCreate( ( pvTaskCode ), ( pcName ), ( usStackDepth ), ( pvParameters ), ( uxPriority ), ( pxCreatedTask ), ( NULL ), ( NULL ) )
	 *
	 *
	 ***********************************************************************************************************************/
	xTaskCreate(&LED1, NULL, 100, NULL, 0, NULL);
	xTaskCreate(&LED2, NULL, 100, NULL, 1, NULL);
	xTaskCreate(&LED3, NULL, 100, NULL, 2, NULL);


	xTaskCreate(&LCD1, NULL, 250, NULL, 0, NULL);
	xTaskCreate(&LCD2, NULL, 250, NULL, 0, NULL);

	LCDsem = xSemaphoreCreateCounting(1,1);



	/*						This is the function to initialize the scheduler of the tasks					*/
	vTaskStartScheduler();

	while(1)
	{

	}
}



void LED1(void * pv)
{
	static u8 Local_u8LedState = 0;
	while(1)
	{

		TOGGLE_BIT(Local_u8LedState,0);
		MDIO_VoidSetPinValue(DIO_PORTA,DIO_PIN0,Local_u8LedState);

		vTaskDelay(1000);




	}

}



void LED2(void * pv)
{

	static u8 Local_u8LedState = 0;
	while(1)
	{

		TOGGLE_BIT(Local_u8LedState,0);
		MDIO_VoidSetPinValue(DIO_PORTA,DIO_PIN1,Local_u8LedState);

		vTaskDelay(2000);


	}
}



void LED3(void * pv)
{

	static u8 Local_u8LedState = 0;
	while(1)
	{

		TOGGLE_BIT(Local_u8LedState,0);
		MDIO_VoidSetPinValue(DIO_PORTA,DIO_PIN2,Local_u8LedState);

		vTaskDelay(3000);


	}

}



void LCD1(void * pv)
{

	u8 Local_u8SemaphoreState;

	while(1)
	{
		Local_u8SemaphoreState = xSemaphoreTake(LCDsem,0);


		if(Local_u8SemaphoreState == pdPASS)
		{
			/*			Semaphore is taken, Acces the LCD for the task			*/
			HLCD_VoidWriteStr("I AM MOAMEN");

			/*				Access is done, give the semaphore now			*/
			xSemaphoreGive(LCDsem);
		}
		vTaskDelay(1000);
	}

}


void LCD2(void * pv)
{
	u8 Local_u8SemaphoreState;
	while(1)
	{
		Local_u8SemaphoreState = xSemaphoreTake(LCDsem,0);

		if(Local_u8SemaphoreState == pdPASS)
		{
			HLCD_VoidWriteStr("I AM MOAMEN number 2");

			xSemaphoreGive(LCDsem);
		}
		vTaskDelay(1000);
	}



}

