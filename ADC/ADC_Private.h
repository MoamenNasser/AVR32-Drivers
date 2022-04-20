/*
 * ADC_Private.h
 *
 *  Created on: Oct 14, 2021
 *      Author: naser
 */

#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_

/********************************************************************************************
 *
 * 						Macros for the registers
 *
 *******************************************************************************************/
#define  ADC_ADCSRA  *((volatile u8*)(0x26))

#define  ADC_ADMUX   *((volatile u8*)(0x27))

#define  ADC_ADCRES  *((volatile u16*)(0x24))


/********************************************************************************************
 *
 * 						Macros for the right and left
 * 						adjustment macros
 *
 *******************************************************************************************/
#define  ADC_RIGHT            0
#define  ADC_LEFT             1

/********************************************************************************************
 *
 * 						ADC Reference voltage
 * 						adjustment macros
 *
 *******************************************************************************************/
#define  ADC_VCC              1
#define  ADC_INTERNAL_VREF    3
#define  ADC_VREF_OFF		  0


/********************************************************************************************
 *
 * 						Auto trigger Macros
 * 						adjustment macros
 *
 *******************************************************************************************/
#define  ADC_TRIGGER_ENABLE	  0
#define  ADC_TRIGGER_DISABLE  1


/********************************************************************************************
 *
 * 						ADMUX register bits
 * 						adjustment macros
 *
 *******************************************************************************************/
#define  REFS1                 7
#define  REFS0				   6
#define  ADLAR                 5
#define  MUX4                  4
#define  MUX3                  3
#define  MUX2                  2
#define  MUX1                  1
#define  MUX0                  0


/********************************************************************************************
 *
 * 						ADCSRA register bits
 * 						adjustment macros
 *
 *******************************************************************************************/
#define  ADEN                   7
#define  ADSC                   6
#define  ADATE                  5
#define  ADIF                   4
#define  ADIE                   3
#define  ADPS2				    2
#define  ADPS1                  1
#define  ADPS0 					0


/********************************************************************************************
 *
 * 						Choose which to use polling or interrupt
 * 						adjustment macros
 *
 *******************************************************************************************/
#define  ADC_POLL               0
#define	 ADC_INT				1



/********************************************************************************************
 *
 * 						ADCSRA register bits
 * 						adjustment macros
 *
 *******************************************************************************************/







#endif /* ADC_PRIVATE_H_ */
