/*
 * ADC_Program.c
 *
 *  Created on: Oct 14, 2021
 *      Author: Moamen Naser
 */

#include"STD_TYPES.h"
#include"ADC_Interface.h"
#include"ADC_Private.h"
#include"ADC_CNF.h"


u16 Result;
/********************************************************************************************
 *
 * 						Initialize the ADC to be able to convert
 *
 *******************************************************************************************/
void ADC_VoidInit(void)
{
	ADC_ADMUX = (ADC_VREF << REFS0) | (ADC_RESULT_ADJUST << ADLAR);

	ADC_ADCSRA = (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1) | (1<< ADPS0);

}


/********************************************************************************************
 *
 * 						Setting the ADC  reading
 *
 *******************************************************************************************/
u16 ADC_u16SetADCReading(u8 Copy_u8ChannelIndex)
{
	/*			Make sure that channel index doesn't exceeds the 7 ADC channels				*/
	Copy_u8ChannelIndex = Copy_u8ChannelIndex & 0b00000111;
	/*			Clear the 3 bottom bits before selecting the channel						*/
	ADC_ADMUX = (ADC_ADMUX & 0xf8) | Copy_u8ChannelIndex;
	/*			Start of the conversion after making sure that all is ok					*/
	ADC_ADCSRA |= (1 << ADC_ADCSRA);
	/*			This line making sure that enable flag set to 1								*/
	while(!(ADC_ADCSRA & (1 << ADIF)));
	/*			Return the value at the end of conversion									*/
	return ADC_ADCRES;
}




/********************************************************************************************
 *
 * 						Enabling the ADC
 *
 *******************************************************************************************/
void ADC_VoidEnable(void)
{

}


/********************************************************************************************
 *
 * 						Disabling the ADC
 *
 *******************************************************************************************/
void ADC_VoidDisable(void)
{

}


#if(ADC_MODE == ADC_INT)
/********************************************************************************************
 *
 * 						Send the start of conversion bit to start the conversion
 *
 *******************************************************************************************/
void ADC_VoidStartOfConversion(u8 Copy_u8ChannelIndex)
{

	/*			Make sure that channel index doesn't exceeds the 7 ADC channels				*/
	Copy_u8ChannelIndex = Copy_u8ChannelIndex & 0b00000111;
	/*			Clear the 3 bottom bits before selecting the channel						*/
	ADC_ADMUX = (ADC_ADMUX & 0xf8) | Copy_u8ChannelIndex;
	/*			Start of the conversion after making sure that all is ok					*/
	ADC_ADCSRA |= (1 << ADC_ADCSRA);

}

u16 ADC_GetDigital(void)
{

	return Result;
}



ISR(ADC_vect)
{
	Result = ADC_ADCRES;

}
#endif
