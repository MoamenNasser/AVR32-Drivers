/*
 * ADC_Interface.h
 *
 *  Created on: Oct 14, 2021
 *      Author: naser
 */

#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

#include"STD_TYPES.h"

void ADC_VoidInit(void);

u16 ADC_u16SetADCReading(u8);

void ADC_VoidStartOfConversion(u8);

void ADC_VoidEnable(void);

void ADC_VoidDisable(void);

u16 ADC_GetDigital(void);
#endif /* ADC_INTERFACE_H_ */
