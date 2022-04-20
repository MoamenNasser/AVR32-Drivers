/*
 * main.c
 *
 *  Created on: Sep 24, 2021
 *      Author: naser
 */
#include"STD_TYPES.h"
#include"MDIO_interface.h"
#include"HLCD_Interface.h"
#include<avr/delay.h>
int main(void)
{

/*
	HLCD_SendNumber(521);
*/
	HLCD_enuInit();
	HLCD_VoidSendCommand(0x80);
	HLCD_ClearDisplay();
	while(1)
	{


		HLCD_GoToXY(1,1);
		/*
		HLCD_VoidSendChar('M');
		HLCD_VoidSendChar('O');
		HLCD_VoidSendChar('A');
		HLCD_VoidSendChar('M');
		HLCD_VoidSendChar('E');
		HLCD_VoidSendChar('N');
		_delay_ms(2000);
		HLCD_ClearDisplay();
		HLCD_GoToXY(2,7);
		HLCD_VoidWriteStr("MOAMEN");
		_delay_ms(2000);
		HLCD_ClearDisplay();
		HLCD_GoToXY(1,14);
		HLCD_VoidWriteStr("MOAMEN");
		_delay_ms(2000);
		HLCD_SendNumber(521);
		HLCD_GoToXY(1,1);
*/

	/*
		HLCD_DrawCharacterE();
		HLCD_DrawCharacterF();
	*/
		//HLCD_DrawHuman();


	}
	return 0;
}

