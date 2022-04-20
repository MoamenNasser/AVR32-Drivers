/*
 * MEXINT_Private.h
 *
 *  Created on: Oct 9, 2021
 *      Author: naser
 */

#ifndef MEXINT_PRIVATE_H_
#define MEXINT_PRIVATE_H_

#define MCUCR 	 *((volatile u8*)0x55)

#define MCUCSR	 *((volatile u8*)0x54)

#define GICR  	 *((volatile u8*)0x5B)

#define GIFR  	 *((volatile u8*)0x5A)

#define SREG  	 *((volatile u8*)0x5F)


void __vector_0(void) __attribute__((signal));

void __vector_1(void) __attribute__((signal));

void __vector_2(void) __attribute__((signal));

#endif /* MEXINT_PRIVATE_H_ */
