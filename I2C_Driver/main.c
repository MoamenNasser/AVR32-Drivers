/*
 * main.c
 *
 *  Created on: Dec 3, 2021
 *      Author: naser
 */
#include"I2C_Interface.h"



int main(void)
{
	I2C_Master_VoidInit();
	/**/
	while(1)
	{
		I2C_VoidStartCondition();
		u8 Copy_Status = I2C_u8CheckStatus(0x08);
		if(Copy_Status != 1)
		{
			/*
			I2C_VoidSendSlaveAddress_Write();
			I2C_u8CheckStatus();
			I2C_VoidMasterSendData("MOAMEN");
			I2C_u8CheckStatus();
			 */
		}
	}

	return 0;
}
