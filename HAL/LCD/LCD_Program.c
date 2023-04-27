/*
 * LCD_Program.c
 *
 *  Created on: 28 Mar 2023
 *      Author: Youssef
 */


#include <util/delay.h>
#include"../../MCAL/DIO/DIO_Interface.h"
#include "LCD_Config.h"
#include "LCD_Private.h"
#include "LCD_Interface.h"





void LCD_VoidInit(void){
	/*Setting the data port to output*/
	DIO_s8SetPortDirection(LCD_DATA_Port,DIO_U8_PORT_DIR_OUTPUT);//Setting data pins to output

	/*SETTING PINS RS/RW/EN to output*/
	DIO_s8SetPinDirection(LCD_CTRL_Port,LCD_U8_RS_PIN,DIO_U8_PIN_DIR_OUTPUT);
	DIO_s8SetPinDirection(LCD_CTRL_Port,LCD_U8_RW_PIN,DIO_U8_PIN_DIR_OUTPUT);
	DIO_s8SetPinDirection(LCD_CTRL_Port,LCD_U8_EN_PIN,DIO_U8_PIN_DIR_OUTPUT);
	_delay_ms(50);
#if LCD_MODE==LCD_8_BIT_MODE

	/*Send Function Set Command    */
	LCD_VoidSendCommand(LCD_FunctionSet8bit);
	_delay_us(50);
	LCD_VoidSendCommand(LCD_DisplayOn);
	_delay_us(50);
	LCD_VoidSendCommand(LCD_DisplayClear);
	_delay_ms(3);
	LCD_VoidSendCommand(LCD_EntryInc_MODE);

	_delay_ms(50);
#elif LCD_MODE==LCD_4_BIT_MODE
	//Sending 4bit Command Manually
	DIO_s8SetPinValue(LCD_CTRL_Port,LCD_U8_RS_PIN,DIO_U8_PIN_LOW); //Setting RS to zero Instruction Register
	DIO_s8SetPinValue(LCD_CTRL_Port,LCD_U8_RW_PIN,DIO_U8_PIN_LOW); //Setting RW to zero
	DIO_u8SetPortValue(LCD_DATA_Port, LCD_FunctionSet4bit);

	/* In order to read, Set enable to high then to low
	 * , read happens during the falling edge of enable signal
	 */
	DIO_s8SetPinValue(LCD_CTRL_Port,LCD_U8_EN_PIN,DIO_U8_PIN_HIGH);
	_delay_ms(2);
	DIO_s8SetPinValue(LCD_CTRL_Port,LCD_U8_EN_PIN,DIO_U8_PIN_LOW);
//	_delay_ms(2);

//	/*Send Function Set Command    */
//	LCD_VoidSendCommand4bit(LCD_FunctionSet4bit); //Function Set 4bit

	_delay_ms(4);
	LCD_VoidSendCommand(LCD_FunctionSet4bit); //Function Set 4bit
	_delay_ms(4);
	LCD_VoidSendCommand(LCD_DisplayOn); //DISPLAY ON
	_delay_ms(4);
	LCD_VoidSendCommand(LCD_DisplayClear); //Display clear
	_delay_ms(8);
	LCD_VoidSendCommand(LCD_EntryMode);//EntryMode Set
	_delay_ms(50);
#endif
}

void LCD_VoidSendCommand(u8 u8Copy_LCD_Command){
	DIO_s8SetPinValue(LCD_CTRL_Port,LCD_U8_RS_PIN,DIO_U8_PIN_LOW); //Setting RS to zero Instruction Register
	DIO_s8SetPinValue(LCD_CTRL_Port,LCD_U8_RW_PIN,DIO_U8_PIN_LOW); //Setting RW to zero

#if LCD_MODE==LCD_8_BIT_MODE

	/*Send the command to Instruction register (IR)
	 * After data is sent to IR,Data is Read from Ram
	 *  then transfered automatically to Data Register
	 *  (Reading from Data Register completes the instruction write operation
	 */
	DIO_u8SetPortValue(LCD_DATA_Port, u8Copy_LCD_Command);

	/* In order to read, Set enable to high then to low
	 * , read happens during the falling edge of enable signal
	 */
	DIO_s8SetPinValue(LCD_CTRL_Port,LCD_U8_EN_PIN,DIO_U8_PIN_HIGH);
	_delay_ms(2);
	DIO_s8SetPinValue(LCD_CTRL_Port,LCD_U8_EN_PIN,DIO_U8_PIN_LOW);
	_delay_ms(2);
#elif LCD_MODE==LCD_4_BIT_MODE

	/*Send the command to Instruction register (IR)
	 * After data is sent to IR,Data is Read from Ram
	 *  then transfered automatically to Data Register
	 *  (Reading from Data Register completes the instruction write operation
	 */

	//Sending higher nibble
	DIO_u8SetPortValue(LCD_DATA_Port, u8Copy_LCD_Command);

	/* In order to read, Set enable to high then to low
	 * , read happens during the falling edge of enable signal
	 */
	_delay_ms(2);
	DIO_s8SetPinValue(LCD_CTRL_Port,LCD_U8_EN_PIN,DIO_U8_PIN_HIGH);
	_delay_ms(2);
	DIO_s8SetPinValue(LCD_CTRL_Port,LCD_U8_EN_PIN,DIO_U8_PIN_LOW);

	//sending lower nibble
	DIO_u8SetPortValue(LCD_DATA_Port, u8Copy_LCD_Command<<4);
	/* In order to read, Set enable to high then to low
	 * , read happens during the falling edge of enable signal
	 */
	_delay_ms(2);
	DIO_s8SetPinValue(LCD_CTRL_Port,LCD_U8_EN_PIN,DIO_U8_PIN_HIGH);
	_delay_ms(2);
	DIO_s8SetPinValue(LCD_CTRL_Port,LCD_U8_EN_PIN,DIO_U8_PIN_LOW);
	_delay_ms(2);
#endif
}

void LCD_VoidSendCharactar(u8 u8Copy_LCD_Character){
	DIO_s8SetPinValue(LCD_CTRL_Port,LCD_U8_RS_PIN,DIO_U8_PIN_HIGH); //Setting RS to ONE Data Register
	DIO_s8SetPinValue(LCD_CTRL_Port,LCD_U8_RW_PIN,DIO_U8_PIN_LOW); //Setting RW to zero (Write)

#if LCD_MODE==LCD_8_BIT_MODE

	DIO_u8SetPortValue(LCD_DATA_Port, u8Copy_LCD_Character);		//Sending the Character
	/* In order to read from Data Register, Set enable to high then to low
	 * , read happens during the falling edge of enable signal
	 */
	DIO_s8SetPinValue(LCD_CTRL_Port,LCD_U8_EN_PIN,DIO_U8_PIN_HIGH);
	_delay_ms(1);
	DIO_s8SetPinValue(LCD_CTRL_Port,LCD_U8_EN_PIN,DIO_U8_PIN_LOW);

#elif LCD_MODE==LCD_4_BIT_MODE
	DIO_u8SetPortValue(LCD_DATA_Port, u8Copy_LCD_Character); //Sending the Character Higher Nibble

	DIO_s8SetPinValue(LCD_CTRL_Port,LCD_U8_EN_PIN,DIO_U8_PIN_HIGH);
	_delay_ms(1);
	DIO_s8SetPinValue(LCD_CTRL_Port,LCD_U8_EN_PIN,DIO_U8_PIN_LOW);
	_delay_ms(1);
	DIO_u8SetPortValue(LCD_DATA_Port, u8Copy_LCD_Character<<4);		//Sending the Character Lower Nibble
	/* Enable Pulse */
	DIO_s8SetPinValue(LCD_CTRL_Port,LCD_U8_EN_PIN,DIO_U8_PIN_HIGH);
	_delay_ms(1);
	DIO_s8SetPinValue(LCD_CTRL_Port,LCD_U8_EN_PIN,DIO_U8_PIN_LOW);
#endif
}

void LCD_VoidSendString(char *u8Copy_LCD_String){
	u8 local_u8_Counter=0;
	while(*(u8Copy_LCD_String+local_u8_Counter)!='\0'){
		LCD_VoidSendCharactar(*(u8Copy_LCD_String+local_u8_Counter));
		local_u8_Counter++;
	}

}


void LCD_VoidSetCursorPos(u8 u8Copy_LCD_ROW,s8 u8Copy_LCD_COL){
//	s8 s8Local_Erorr_State=0;
	u8 u8Local_DDRAM_address=0;

	if(((u8Copy_LCD_ROW == 1) || (u8Copy_LCD_ROW == 2)) && ((u8Copy_LCD_COL > 0) && (u8Copy_LCD_COL < 16)))
	{
		if(u8Copy_LCD_ROW==1){//First Row, Start at 00H
			u8Local_DDRAM_address=u8Copy_LCD_COL-1;
		}
		else if (u8Copy_LCD_ROW==2){//Second Row, Start at 40H
			u8Local_DDRAM_address=(u8Copy_LCD_COL-1)+0x40;
		}
	}
//	u8Local_DDRAM_address=u8Copy_LCD_ROW*0x40 + u8Copy_LCD_COL;
	else{
//		s8Local_Erorr_State=-1;
	}
	SetBit(u8Local_DDRAM_address,7);
	LCD_VoidSendCommand(u8Local_DDRAM_address);         //Sending command to set DDRAM address TO LCD POS
//	return s8Local_Erorr_State;
}



void LCD_VoidSendNumber(u32 u8Copy_LCD_Number){
	u32 Local_u32_ReversedNum=0;
	u8  Local_u8_ZeroCounter=0;
	if(u8Copy_LCD_Number==0)
	{ // Condition for printing the number 0 as a digit
		LCD_VoidSendCharactar('0');
	}
	else
	{
		/*Counting number of ZEROS in Least significant digits (before a non zero digit)
		 * For example 1020055000 (3 Zeros)*/
		while(u8Copy_LCD_Number%10==0){
			Local_u8_ZeroCounter++;
			u8Copy_LCD_Number/=10;
		}
		while(u8Copy_LCD_Number!=0)//Reversing the input number
		{
			Local_u32_ReversedNum = Local_u32_ReversedNum*10+ u8Copy_LCD_Number%10;
			u8Copy_LCD_Number/=10;
		}
		while(Local_u32_ReversedNum!=0)//Printing Reversed number digits reversely (In correct way)
		{
			LCD_VoidSendCharactar((Local_u32_ReversedNum%10)+0x30); //Sending ASCII for digits (Adding offset of 0 in hex can be written x+'0'
			Local_u32_ReversedNum/=10;
		}
		// Printing Zeros in Least Significant  Digits
		while(Local_u8_ZeroCounter>0)
		{
			LCD_VoidSendCharactar('0');
			Local_u8_ZeroCounter--;
		}
	}
/*Another Way of printing NUMBER Go To Decrement Mode, PrintNumber, Then Back to Increment Mode
	s8 Local_counter=0;
	u8 Local_num=u8Copy_LCD_Number;

	while(Local_num!=0)//Reversing the input number
	{
	Local_counter++;
	Local_num/=10;
	}
	while(Local_counter>-1){	//Shift the cursor to the Correct Position
	LCD_VoidSendCommand(LCD_RightShiftCursor);
	Local_counter--;
	}
	Local_counter=0;
	LCD_VoidSendCommand(LCD_EntryDec_MODE);		//Go to Decrement EntryModeSet
	_delay_ms(50);
	while(u8Copy_LCD_Number!=0)//Printing the input number Reversed
	{
	Local_counter++;
	LCD_VoidSendCharactar((u8Copy_LCD_Number%10)+0x30); //Sending ASCII for digits (Adding offset of 0 in hex can be written x+'0'
	u8Copy_LCD_Number/=10;
	}
	while(Local_counter>-1){	//Shift the cursor to the Correct Position
		LCD_VoidSendCommand(LCD_RightShiftCursor);
		Local_counter--;
	}
	LCD_VoidSendCommand(LCD_EntryInc_MODE);//Go to Decrement EntryModeSet, Shift Display
	_delay_ms(50);
 */


}


void LCD_voidSendSpecialChar(u8 *arr,u8 u8Copy_LCD_ROW,u8 u8Copy_LCD_COL,u8 Copy_CGAddress){
	u8 address=0;
	SetBit(address,6); 			//Instruction for setting CGRAM ADDRESS
	LCD_VoidSendCommand(address|(Copy_CGAddress*8)); //Sending CGRAM ADDRESS WITH
	//Appropriate Location(First Row in the specified Character)

	for(int i=0;i<8;i++){
		LCD_VoidSendCharactar(arr[i]);
	}

	LCD_VoidSetCursorPos(u8Copy_LCD_ROW,u8Copy_LCD_COL);	//Return to DDRAM Address


	LCD_VoidSendCharactar(Copy_CGAddress);//In order to print ,The address of
	//first Row of CG Character is sent to DDRAM which gets redirected
	//to the sent address in CGRAM.
}

void LCD_voidSendSpecialCharRightToLeft(u8 *arr,u8 u8Copy_LCD_ROW,u8 u8Copy_LCD_COL,u8 Copy_CGAddress){
	//This function is used when EntryMode is set to decrement address
	//Please note that arr[0] is treated as cursor instead of arr[8]

	u8 address=0;
	SetBit(address,6); 			//Instruction for setting CGRAM ADDRESS
	LCD_VoidSendCommand(address|(((Copy_CGAddress+1)*8)-1));//Sending CGRAM ADDRESS WITH
	//Appropriate Location(Last Row in the specified Character)

	for(int i=7;i>-1;i--){	//Data is sent inversely as it is
		//written from bottom to TOP in CGRAM
		LCD_VoidSendCharactar(arr[i]);
	}

	LCD_VoidSetCursorPos(u8Copy_LCD_ROW,u8Copy_LCD_COL);

	LCD_VoidSendCharactar(Copy_CGAddress);//In order to print ,The address of
	//first Row of CG Character is sent to DDRAM which gets redirected
	//to the sent address in CGRAM.
}

void LCD_VoidClearDisplay(void){
	LCD_VoidSendCommand(LCD_DisplayClear);
}
void LCD_VoidHelloHamkosha(void){
	u8 Hamoksha[8]={0B00000,0B00100,0B01010,0B01010,0B00100,0B01110,0B00100,0B01010};
	LCD_VoidSendString("Hi,I am Hamoksha");
	LCD_voidSendSpecialChar(Hamoksha,LCD_ROW_TWO,LCD_COL_EIGHT,LCD_CGRAM_CHAR1);
}
void LCD_VoidHamkoshaPlayFootball(void){
	u8 Hamoksha[8]={0B00000,0B00100,0B01010,0B01010,0B00100,0B01110,0B00100,0B01010};
	u8 Ball_DOWN[8]={0B00000,0B00000,0B00000,0B00000,0B00000,0B01000,0B10100,0B01000};
	u8 Ball_UP[8]={0B00000,0B01000,0B10100,0B01000,0B00000,0B00000,0B00000,0B00000};

	LCD_VoidSendCommand(LCD_ReturnHome);
//	LCD_VoidSendCommand(LCD_DisplayClear);
	LCD_VoidSendString("I play football");
	LCD_voidSendSpecialChar(Hamoksha,LCD_ROW_TWO,LCD_COL_EIGHT,LCD_CGRAM_CHAR1);
	LCD_voidSendSpecialChar(Ball_DOWN,LCD_ROW_TWO,LCD_COL_NINE,LCD_CGRAM_CHAR2);
	_delay_ms(50);

//	LCD_VoidSendCommand(LCD_DisplayClear);

//	LCD_VoidSendCommand(LCD_ReturnHome);

//	LCD_VoidSendString("I play football");
//	LCD_voidSendSpecialChar(Hamoksha,LCD_ROW_TWO,LCD_COL_EIGHT,LCD_CGRAM_CHAR1);
	LCD_voidSendSpecialChar(Ball_UP,LCD_ROW_TWO,LCD_COL_NINE,LCD_CGRAM_CHAR3);
	_delay_ms(50);

}


void LCD_VoidHamkoshaCanRun(void){
	u8 HamokshaRun[8]={0B00000,0B00100,0B01010,0B01010,0B00110,0B00100,0B01110,0B00000};
	u8 Hamoksha[8]={0B00000,0B00100,0B01010,0B01010,0B00100,0B01110,0B00100,0B01010};
	for(u8 i=LCD_COL_ONE;i<LCD_COL_SIXTEEN;i+=2){
		LCD_VoidSendCommand(LCD_DisplayClear);
		LCD_VoidSendCommand(LCD_ReturnHome);
		LCD_VoidSendString("I can Run");
		LCD_voidSendSpecialChar(Hamoksha,LCD_ROW_TWO,i,LCD_CGRAM_CHAR1);
		_delay_ms(80);
		LCD_VoidSendCommand(LCD_DisplayClear);
		LCD_VoidSendCommand(LCD_ReturnHome);
		LCD_VoidSendString("I can Run");
		LCD_voidSendSpecialChar(HamokshaRun,LCD_ROW_TWO,i+1,LCD_CGRAM_CHAR2);
		_delay_ms(80);

	}
}

void LCD_VoidDontKillHamoksha(void){
	u8 Hamoksha[8]={0B00000,0B00100,0B01010,0B01010,0B00100,0B01110,0B00100,0B01010};
	u8 Gun[8]={0B00000,0B00000,0B00111,0B00100,0B00100,0B00100,0B00000,0B00000};
	u8 Bullet[8]={0B00000,0B00000,0B00100,0B00000,0B00000,0B00000,0B00000,0B00000};
	u8 DeadHamoksha[8]={0B00000,0B00000,0B00000,0B00000,0B00000,0B00000,0B00000,0B11111};
	//	LCD_VoidSendCommand(LCD_ReturnHome);
	//	LCD_VoidSendCommand(LCD_DisplayClear);
	//	LCD_VoidSendString("Don't Kill ME ");
	//	LCD_voidSendSpecialChar(Hamoksha,LCD_ROW_TWO,LCD_COL_SIXTEEN,LCD_CGRAM_CHAR1);
	//	LCD_voidSendSpecialChar(Gun,LCD_ROW_TWO,LCD_COL_ONE,LCD_CGRAM_CHAR2);
	//	LCD_voidSendSpecialChar(Bullet,LCD_ROW_TWO,LCD_COL_TWO,LCD_CGRAM_CHAR3);

	for(u8 i=LCD_COL_ONE;i<LCD_COL_SIXTEEN;i+=2){
		LCD_VoidSendCommand(LCD_ReturnHome);
		LCD_VoidSendCommand(LCD_DisplayClear);
		LCD_VoidSendString("Don't Kill ME ");
		LCD_voidSendSpecialChar(Hamoksha,LCD_ROW_TWO,LCD_COL_SIXTEEN,LCD_CGRAM_CHAR1);
		LCD_voidSendSpecialChar(Gun,LCD_ROW_TWO,LCD_COL_ONE,LCD_CGRAM_CHAR2);
		LCD_voidSendSpecialChar(Bullet,LCD_ROW_TWO,i,LCD_CGRAM_CHAR3);
		_delay_ms(80);


	}
	LCD_VoidSendCommand(LCD_ReturnHome);
	LCD_VoidSendCommand(LCD_DisplayClear);
	LCD_VoidSendString("Don't Kill ME ");
	LCD_voidSendSpecialChar(Gun,LCD_ROW_TWO,LCD_COL_ONE,LCD_CGRAM_CHAR2);
//	LCD_voidSendSpecialChar(Bullet,LCD_ROW_TWO,LCD_COL_SIXTEEN,LCD_CGRAM_CHAR3);
	LCD_voidSendSpecialChar(DeadHamoksha,LCD_ROW_TWO,LCD_COL_SIXTEEN,LCD_CGRAM_CHAR4);

}
