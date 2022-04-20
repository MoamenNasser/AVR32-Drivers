/*
 * INT_CNF.h
 *
 *  Created on: Oct 9, 2021
 *      Author: naser
 */

#ifndef INT_CNF_H_
#define INT_CNF_H_

#define INT0_vect __vector_1

#define ISR(vector)     void vector(void) __attribute__((signal)); \
						void vector(void)


#endif /* INT_CNF_H_ */
