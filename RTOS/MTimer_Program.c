/*
 * MTimer_Program.c
 *
 *  Created on: Oct 23, 2021
 *      Author: naser
 */

#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"MTimer_Interface.h"
#include"MTimer_Private.h"
#include"MTimer_CNF.h"
#include"MDIO_interface.h"
#include"MDIO_Private.h"
#include"avr/interrupt.h"
#include"CNF.h"

u16 Tick_Number = 0;
Task_T Tasks[Number_of_elements];


/***************************************************************************************************************************
 **************************************************************************************************************************
 *													TIMER NUMBER 0
 **************************************************************************************************************************
 ***************************************************************************************************************************/
/********************************************************************************************
 *
 * 							Initialization function for the timer number 0
 *
 *******************************************************************************************/
void MTimer0_Init(void)
{
	/*							If the user select the Normal Mode									*/
#if TIMER_MODE == NORMAL_MODE
	/*							Choosing the normal mode											*/
	CLR_BIT(TCCR0,WGM00);
	CLR_BIT(TCCR0,WGM01);
	/*							Choosing the Pre scaller	binary = 100							*/
	SET_BIT(TCCR0,CS00);
	CLR_BIT(TCCR0,CS01);
	SET_BIT(TCCR0,CS02);
	/*							Enable the over flow interrupt										*/
	SET_BIT(TIMSK,TOIE0);
	/*							Set the values into the register									*/
	TCNT0 = 238;
#endif
	/**/
#if TIMER_MODE == CTC_MODE
	/*						Choosing the CTC mode											*/
	CLR_BIT(TCCR0,WGM00);
	SET_BIT(TCCR0,WGM01);
	/*						Choosing the pre-scaller	binary = 100							*/
	CLR_BIT(TCCR0,CS00);
	CLR_BIT(TCCR0,CS01);
	SET_BIT(TCCR0,CS02);
	/*							Enable the over flow interrupt										*/
	SET_BIT(TIMSK,TOIE0);
	/*							Set the values into the register									*/
	TCNT0 = 238;
#endif

/*								FAST PWM MODE															*/
#if TIMER_MODE == FAST_PWM_MODE
	/*							Choosing the normal mode											*/
	SET_BIT(TCCR0,WGM00);
	SET_BIT(TCCR0,WGM01);
	/*							Choosing the pre-scaller	binary = 100							*/
	CLR_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS01);
	CLR_BIT(TCCR0,CS02);
	/*							Non-Inverting Mode	binary = 10										*/
	SET_BIT(TCCR0,COM01);
	CLR_BIT(TCCR0,COM00);
	/*							Disable the over flow interrupt										*/
	CLR_BIT(TIMSK,TOIE0);
	CLR_BIT(TIMSK,OCIE0);

#endif

}


/********************************************************************************************
 *
 * 							Function interrupt for the timer number 0
 *
 *******************************************************************************************/
void __vector_11(void)
{
	/*						Define a counter for overflow 										*/
	static u8 Copy_u8OV_Counter = 0;
	Copy_u8OV_Counter++;
	if(Copy_u8OV_Counter == 123)
	{
		Scheduler();
		/*					To solve the problem of the next second 							*/
		TCNT0 = 238;
		/*					Toggle a LED														*/
		//MDIO_VoidTogglePin(DIO_PORTA,DIO_PIN0);
		/*					Clear the counter for the next counts								*/
		Copy_u8OV_Counter = 0;
	}
}


/***************************************************************************************************************************
 **************************************************************************************************************************
 *											TIMER NUMBER 1
 **************************************************************************************************************************
 ***************************************************************************************************************************/
/********************************************************************************************
 *
 * 							Initialization function for the timer number 1
 *
 *******************************************************************************************/
void MTimer1_Init(void)
{
	/*						Choosing the normal mode											*/
	CLR_BIT(TCCR0,WGM00);
	CLR_BIT(TCCR0,WGM01);
	/*						Choosing the pre-scaller	binary = 100											*/
	CLR_BIT(TCCR0,CS00);
	CLR_BIT(TCCR0,CS01);
	SET_BIT(TCCR0,CS02);
	/*						Enable the over flow interrupt										*/
	SET_BIT(TIMSK,TOIE0);
	/*						Set the values into the register*/
	TCNT0 = 238;

}


/********************************************************************************************
 *
 * 							Function interrupt for the timer number 1
 *
 *******************************************************************************************/
void __vector_9(void)
{
	static u8 Copy_u8OV_Counter_Timer1 = 0;
	Copy_u8OV_Counter_Timer1++;
	if(Copy_u8OV_Counter_Timer1 == 123)
	{
		/*					To solve the problem of the next second 							*/
		TCNT0 = 238;
		/*					Toggle a LED														*/
		MDIO_VoidTogglePin(DIO_PORTB,DIO_PIN0);
		/*					Clear the counter for the next counts								*/
		Copy_u8OV_Counter_Timer1 = 0;
	}
}


/***************************************************************************************************************************
 **************************************************************************************************************************
 *											TIMER NUMBER 2
 **************************************************************************************************************************
 ***************************************************************************************************************************/
/********************************************************************************************
 *
 * 							Initialization function for the timer number 2
 *
 *******************************************************************************************/
void MTimer2_Init(void)
{
	/*						Choosing the normal mode											*/
	CLR_BIT(TCCR2,WGM20);
	CLR_BIT(TCCR2,WGM21);
	/*						Choosing the prescaler	binary = 100											*/
	CLR_BIT(TCCR2,CS00);
	CLR_BIT(TCCR2,CS01);
	SET_BIT(TCCR2,CS02);
	/*						Enable the over flow interrupt										*/
	SET_BIT(TIMSK,TOIE0);
	/*						Set the values into the register*/
	TCNT0 = 238;

}


/********************************************************************************************
 *
 * 							Function interrupt for the timer number 2
 *
 *******************************************************************************************/
void __vector_5(void)
{
	static u8 Copy_u8OV_Counter_Timer2 = 0;
	Copy_u8OV_Counter_Timer2++;
	if(Copy_u8OV_Counter_Timer2 == 123)
	{
		/*					To solve the problem of the next second 							*/
		TCNT0 = 238;
		/*					Toggle a LED														*/
		MDIO_VoidTogglePin(DIO_PORTB,DIO_PIN0);
		/*					Clear the counter for the next counts								*/
		Copy_u8OV_Counter_Timer2 = 0;
	}
}


/***************************************************************************************************************************
 **************************************************************************************************************************
 *										Watch Dog TIMER
 **************************************************************************************************************************
 ***************************************************************************************************************************/

/*******************************************************************************************
 *
 * 							Enable function for the watch dog timer
 *
 *******************************************************************************************/
void MWatchDogTimer_Enable(void)
{
	/*						Set the enable bit to 1 											*/
	SET_BIT(WDTCR,WDE);
	/*						Choosing the Prescaler value	1 second >> 110						*/
	SET_BIT(WDTCR,WDP2);
	SET_BIT(WDTCR,WDP1);
	CLR_BIT(WDTCR,WDP0);

}


/*******************************************************************************************
 *
 * 							Disable function for the watch dog timer
 *
 *******************************************************************************************/
void MWatchDogTimer_Disable(void)
{
	/*******************************************************************************************
	 *
	 * 						Here we need the critical section to make sure we can disable
	 * 						The Watch dog timer in 4 cycles
	 *
	 ********************************************************************************************/
	//DISABLE_GIE();
	/*						Set the turn off enable bit to 1 write a logic one to WDTOE and WDE */
	/*						write a logic one to WDTOE and WDE									*/
	WDTCR = 0b00011110;
	/*
	 * 						Within the next four clock cycles, write a logic 0 to WDE.
	 * 							This disables the Watch dog
	 * 																						*/
	WDTCR = 0;
	//CLR_BIT(WDTCR,WDE);
	/*						Now we can safely enable the interrupts again					*/
	//ENABLE_GIE();

}

/*******************************************************************************************
 *
 * 								Refresh function for the watch dog timer
 *
 *******************************************************************************************/
void MWatchDogTimer_Refresh(void)
{
	/*																			*/
	__asm__("WDR");
}


/*******************************************************************************************
 *
 * 						Refresh function for the watch dog timer
 *
 *******************************************************************************************/
void MTIMER_VoidSetDutyCycle(u8 Copy_u8DutyCycle)
{
	/**/
	OCR0 = Copy_u8DutyCycle;
}

/**/
void CreateTask(void (*Copy_ptf)(void),u16 Copy_priority,u16 periodicity)
{
	/**/
	Tasks[Copy_priority].ptf = Copy_ptf;
	/**/
	Tasks[Copy_priority].Periodicity = periodicity;
	/**/
}

/**/
void Scheduler(void)
{
	/**/
	Tick_Number++;
	for(u8 Copy_counter = 0;Copy_counter < 3;Copy_counter++)
	{
		/**/
		if((Tick_Number % Tasks[Copy_counter].Periodicity) == 0)
		{
			/**/
			Tasks[Copy_counter].ptf();
		}
	}
}

/**/
void OS_start(void)
{
	MTimer0_Init();
}



/**/
void CreateTask_4Tasks(void (*Copy_ptf)(void),u16 Copy_priority,u16 periodicity)
{
	/**/

}

/**/

//void Scheduler_4Tasks(void)
//{
	/**/
	/**/
	//Tick_Number++;
	//for(u8 Copy_counter = 0;Copy_counter < 4;Copy_counter++)
	//{
		/**/
		//if((Copy_First_Delay.Periodicity) == 0)
		//{
			/**/

			/**/
			//Tasks[Copy_counter].ptf();
			/**/

		//}
	//}
//}

/**/
void OS_start1(void)
{
	/**/
	MTimer0_Init();

}
