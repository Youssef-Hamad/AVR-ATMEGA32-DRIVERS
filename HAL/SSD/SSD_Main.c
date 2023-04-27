/*
 * SSD_Main.c
 *
 *  Created on: Apr 11, 2023
 *      Author: Youssef
 */
#if 0



LCD_VoidInit();
KEYPAD_VoidInit();



void main (void){
	u8 x=KEYPAD_u8GetPressedButton();
	if(x!=0XFF)
		LCD_VoidSendCharactar(x);
}
#endif

