/*
 * BIT_MATH.h
 *
 *  Created on: Sep 24, 2021
 *      Author: naser
 */

#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define GET_BIT(Var,BitNo)	(Var>>BitNo)&1
#define SET_BIT(Var,BitNo)   Var |= (1 << BitNo)
#define CLR_BIT(Var,BitNo)   Var &= (~(1 << BitNo))
#define TOGGLE_BIT(Var,BitNo)   Var ^= 1 << BitNo

#endif /* BIT_MATH_H_ */
