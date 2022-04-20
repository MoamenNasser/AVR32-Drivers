/*
 * ADC_CNF.h
 *
 *  Created on: Oct 14, 2021
 *      Author: naser
 */

#ifndef ADC_CNF_H_
#define ADC_CNF_H_


/********************************************************************************************
 * 						Reference Voltage Selection
 * 				range : ADC_VCC, ADC_INTERNAL_VREF, ADC_VREF_DIFF
 *******************************************************************************************/
#define  ADC_VREF           ADC_VCC

#define  ADC_RESULT_ADJUST  ADC_RIGHT

#define  ADC_AUTOTRIGGER    ADC_TRIGGER_ENABLE


/* *******************************************************************************************
 *
 * 						Please here give the mode of the ADC
 * 						1 for interrupt
 *
 * *******************************************************************************************/
#define  ADC_MODE			1



#endif /* ADC_CNF_H_ */
