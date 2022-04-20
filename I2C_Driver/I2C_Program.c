/*
 * I2C_Program.c
 *
 *  Created on: Dec 3, 2021
 *      Author: naser
 */
#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"I2C_Interface.h"
#include"I2C_Program.h"
#include"I2C_Private.h"
#include"I2C_CNF.h"
/*******************************************************************************************
 *
 * 						Initialization function for the I2C
 *
 *******************************************************************************************/
void I2C_Master_VoidInit(u8 Copy_u8SlaveAddress)
{
	/*					Set Clock frequency to 400KPbs						*/
	/*					set the TWBR value to 2 							*/
	TWBR = 0x02;
	/*					clear the 2 bits of the TWPS						*/
	CLR_BIT(TWSR,TWPS0);
	CLR_BIT(TWSR,TWPS1);

	/*	*/
	SET_BIT(TWCR,TWINT);
	/**/
	if(Copy_u8SlaveAddress != 0)
	{
		TWAR = Copy_u8SlaveAddress <<1;
	}
	/**/
	//CLR_BIT(TWCR,TWEA);
	/**/
	SET_BIT(TWCR,TWEN);
}

/*******************************************************************************************
 *
 * 						Initialization function for the I2C
 *
 *******************************************************************************************/
void I2C_Slave_VoidInit(u8 Copy_u8SlaveAddress)
{
	/**/
	TWAR  =  Copy_u8SlaveAddress <<1 ;
	/**/
	SET_BIT(TWCR,TWEN);
	/**/

}


/*******************************************************************************************
 *
 * 						Function to send the start condition and start the transmit
 *
 *******************************************************************************************/
void I2C_VoidStartCondition(void)
{
	/**/
	SET_BIT(TWCR,TWINT);
	/**/
	SET_BIT(TWCR,TWSTA);
	/**/
	SET_BIT(TWCR,TWEN);
	/**/
	while (!(TWCR & (1<<TWINT)));
}


/*******************************************************************************************
 *
 * 						Function to send the stop condition and start the transmit
 *
 *******************************************************************************************/
void I2C_VoidStopCondition(void)
{
	/**/
	SET_BIT(TWCR,TWINT);
	/**/
	SET_BIT(TWCR,TWSTO);
	/**/
	SET_BIT(TWCR,TWEN);
	/**/
	while (!(TWCR & (1<<TWINT)));
}


/*******************************************************************************************
 *
 * 						Refresh function for the watch dog timer
 *
 *******************************************************************************************/
void I2C_VoidSendSlaveAddress_Read(u8 Copy_u8SlaveAddress)
{
	/*					Shift the address to make sure that it is the MSB	*/
	TWDR = (Copy_u8SlaveAddress << 1) | 0x01;
	/**/
	TWCR = (1<<TWINT) | (1<<TWEN);
	/*					Polling till the flag is up 						*/
	while (!(TWCR & (1<<TWINT)));
}

/*******************************************************************************************
 *
 * 						Refresh function for the watch dog timer
 *
 *******************************************************************************************/
void I2C_VoidSendSlaveAddress_Write(u8 Copy_u8SlaveAddress)
{
	/*					Shift the address to make sure that it is the MSB	*/
	TWDR = Copy_u8SlaveAddress << 1;
	/**/
	TWCR = (1<<TWINT) | (1<<TWEN);
	/*					Polling till the flag is up 						*/
	while (!(TWCR & (1<<TWINT)));
}

/*******************************************************************************************
 *
 * 						Refresh function for the watch dog timer "Receive"
 *
 *******************************************************************************************/
u8 I2C_VoidReadData(void)
{
	/**/
	TWCR = (1 << TWINT) | (1 << TWEN);
	/**/
	/*					Polling till the flag is up 						*/
	while (!(TWCR & (1<<TWINT)));

	/*					Return the value in the data register				*/
	return TWDR;
}


/*******************************************************************************************
 *
 * 						Function to write the data in the I2C
 *
 *******************************************************************************************/
void I2C_VoidWriteData(u8 Copy_Data)
{
	/**/
	TWDR = Copy_Data;
	/**/
	TWCR = (1<<TWINT) | (1<<TWEN);
	/**/
	while (!(TWCR & (1<<TWINT)));
}


/*******************************************************************************************
 *
 * 						Refresh function for the watch dog timer
 *
 *******************************************************************************************/
void I2C_VoidMasterReadData(void)
{
	/*					M send start Condition									*/
	//I2C_VoidSendStartCondition();
	/*					M send Slave Address + write bit						*/

	/*					S send ACK												*/

	/*					M send Data												*/

	/*					S send ACK 												*/

	/*					M send stop 											*/

}



/*******************************************************************************************
 *
 * 						Function to check the status of the register and I2C
 *
 *******************************************************************************************/
u8 I2C_u8CheckStatus(u8 Copy_u8Status)
{
	/**/
	if((TWSR & 0xF8) == Copy_u8Status)
	{
		return 1;

	}
	else
		return 0;
}


/*******************************************************************************************
 *
 * 						Function to send the repeated start condition and start the transmit
 *
 *******************************************************************************************/
void I2C_VoidRepeatedStart(void)
{


}

/*******************************************************************************************
 *
 * 						Refresh function for the watch dog timer
 *
 *******************************************************************************************/
void I2C_VoidSlaveSendData(u8 Copy_u8Data)
{

}

