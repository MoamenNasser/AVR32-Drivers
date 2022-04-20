/*
 * SPI_Private.h
 *
 *  Created on: Nov 15, 2021
 *      Author: naser
 */

#ifndef SPI_PRIVATE_H_
#define SPI_PRIVATE_H_


/********************************************************************************************
 *
 * 							MACRO FOR SPCR REGESTER
 *
 *******************************************************************************************/
#define SPCR						*((volatile u8*)(0x2D))


/********************************************************************************************
 *
 * 							MACRO FOR SPCR pins
 *
 *******************************************************************************************/
#define SPIE						7
#define SPE							6
#define DORD						5
#define MSTR						4
#define CPOL						3
#define CPHA						2
#define SPR1						1
#define SPR0						0



/********************************************************************************************
 *
 * 							MACRO FOR SPSR REGESTER
 *
 *******************************************************************************************/
#define SPSR						*((volatile u8*)(0x2E))


/********************************************************************************************
 *
 * 							MACRO FOR SPSR pins
 *
 *******************************************************************************************/
#define SPIF						7
#define WCOL						6
#define SPI2X						0



/********************************************************************************************
 *
 * 							MACRO FOR SPDR REGISTER
 *
 *******************************************************************************************/
#define SPDR						*((volatile u8*)(0x2F))


/********************************************************************************************
 *
 * 							MACRO FOR SPDR pins
 *
 *******************************************************************************************/
#define MSB							7
#define LSB							0


#endif /* SPI_PRIVATE_H_ */
