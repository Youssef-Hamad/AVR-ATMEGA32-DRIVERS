/*
 * KEYPAD_Program.c
 *
 *  Created on: Mar 31, 2023
 *      Author: DWEEBSTARK
 */
#include <util/delay.h>
#include "../../MCAL/DIO/DIO_Interface.h"
#include "KEYPAD_Config.h"
#include "KEYPAD_Private.h"
#include "KEYPAD_Interface.h"
#include "../LCD/LCD_Interface.h"




void KEYPAD_VoidInit(void){

	DIO_s8SetPinDirection(KEYPAD_ROW_PORT,KEYPAD_ROW_ONE,DIO_U8_PIN_DIR_INPUT_PULLUP);
	DIO_s8SetPinDirection(KEYPAD_ROW_PORT,KEYPAD_ROW_TWO,DIO_U8_PIN_DIR_INPUT_PULLUP);
	DIO_s8SetPinDirection(KEYPAD_ROW_PORT,KEYPAD_ROW_THREE,DIO_U8_PIN_DIR_INPUT_PULLUP);
	DIO_s8SetPinDirection(KEYPAD_ROW_PORT,KEYPAD_ROW_FOUR,DIO_U8_PIN_DIR_INPUT_PULLUP);

	DIO_s8SetPinDirection(KEYPAD_COL_PORT,KEYPAD_COL_ONE,DIO_U8_PIN_DIR_OUTPUT);
	DIO_s8SetPinDirection(KEYPAD_COL_PORT,KEYPAD_COL_TWO,DIO_U8_PIN_DIR_OUTPUT);
	DIO_s8SetPinDirection(KEYPAD_COL_PORT,KEYPAD_COL_THREE,DIO_U8_PIN_DIR_OUTPUT);
	DIO_s8SetPinDirection(KEYPAD_COL_PORT,KEYPAD_COL_FOUR,DIO_U8_PIN_DIR_OUTPUT);

	DIO_s8SetPinValue(KEYPAD_COL_PORT,KEYPAD_COL_ONE,DIO_U8_PIN_HIGH);
	DIO_s8SetPinValue(KEYPAD_COL_PORT,KEYPAD_COL_TWO,DIO_U8_PIN_HIGH);
	DIO_s8SetPinValue(KEYPAD_COL_PORT,KEYPAD_COL_THREE,DIO_U8_PIN_HIGH);
	DIO_s8SetPinValue(KEYPAD_COL_PORT,KEYPAD_COL_FOUR,DIO_U8_PIN_HIGH);

}


u8 KEYPAD_u8GetPressedButton(void){

	u8 Local_u8PressedButton=NO_KEY_PRESSED;
	u8 Local_u8State=1;

	u8 Local_u8ColIterator=0;
	u8 Local_u8RowIterator=0;

	u8 Local_u8ColArray[4]={KEYPAD_COL_ONE,KEYPAD_COL_TWO,KEYPAD_COL_THREE,KEYPAD_COL_FOUR};
	u8 Local_u8RowArray[4]={KEYPAD_ROW_ONE,KEYPAD_ROW_TWO,KEYPAD_ROW_THREE,KEYPAD_ROW_FOUR};

	u8 KeyPadArray[4][4]=KEYPAD_CHARACTERS;
	// Iterate between Columns
	for(Local_u8ColIterator=0;Local_u8ColIterator<4;Local_u8ColIterator++){
		//Activate Columns One by one(Setting to Low)
		DIO_s8SetPinValue(KEYPAD_COL_PORT,Local_u8ColArray[Local_u8ColIterator],DIO_U8_PIN_LOW);

		for(Local_u8RowIterator=0;Local_u8RowIterator<4;Local_u8RowIterator++){

			//For each Activated Column check All 4 Rows
			Local_u8State=DIO_u8GetPinValue(KEYPAD_ROW_PORT,Local_u8RowArray[Local_u8RowIterator]);

			//If a button is pressed , the Row Pin will be ZERO
			if(Local_u8State==DIO_U8_PIN_LOW){
				//Get the value of the pressed button
				Local_u8PressedButton=KeyPadArray[Local_u8RowIterator][Local_u8ColIterator];

				/*Busy waiting	(polling) until the key is released*/
				while(Local_u8State==DIO_U8_PIN_LOW){
					Local_u8State=DIO_u8GetPinValue(KEYPAD_ROW_PORT,Local_u8RowArray[Local_u8RowIterator]);
				}
				/*Deactivate the Column if A Button is pressed*/
				DIO_s8SetPinValue(KEYPAD_COL_PORT,Local_u8ColArray[Local_u8ColIterator],DIO_U8_PIN_HIGH);
				return Local_u8PressedButton;
			}
		}
		//Deactivate the Column If no Buttons are pressed to iterate to the next column (Setting to High)
		DIO_s8SetPinValue(KEYPAD_COL_PORT,Local_u8ColArray[Local_u8ColIterator],DIO_U8_PIN_HIGH);
	}
	return Local_u8PressedButton;
}
