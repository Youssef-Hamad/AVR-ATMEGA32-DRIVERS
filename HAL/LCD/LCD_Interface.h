/*
 * LCD_Interface.h
 *
 *  Created on: 28 Mar 2023
 *      Author: Youssef
 */

#ifndef HAL_LCD_LCD_INTERFACE_H_
#define HAL_LCD_LCD_INTERFACE_H_



#define LCD_ROW_ONE				1
#define LCD_ROW_TWO				2

#define LCD_COL_ONE				1
#define LCD_COL_TWO				2
#define LCD_COL_THREE			3
#define LCD_COL_FOUR			4
#define LCD_COL_FIVE			5
#define LCD_COL_SIX				6
#define LCD_COL_SEVEN			7
#define LCD_COL_EIGHT			8
#define LCD_COL_NINE			9
#define LCD_COL_TEN				10
#define LCD_COL_ELEVEN			11
#define LCD_COL_TWELVE			12
#define LCD_COL_THRTEEN			13
#define LCD_COL_FOURTEEN		14
#define LCD_COL_FIFTEEN			15
#define LCD_COL_SIXTEEN			16


#define LCD_CGRAM_CHAR1		0
#define LCD_CGRAM_CHAR2		1
#define LCD_CGRAM_CHAR3		2
#define LCD_CGRAM_CHAR4		3
#define LCD_CGRAM_CHAR5		4
#define LCD_CGRAM_CHAR6		5
#define LCD_CGRAM_CHAR7		6
#define LCD_CGRAM_CHAR8		7


#define LCD_EntryInc_MODE		0x6 //Increase DDRAM ADDRESS BY 1 WHEN Sending/Reading DATA,No Display shift
#define LCD_EntryDec_MODE		0x4 //Decrease DDRAM ADDRESS BY 1 WHEN Sending/Reading DATA,No Display shift


void LCD_VoidInit4bit(void);
void LCD_VoidSendCommand4bit(u8 u8Copy_LCD_Command);
void LCD_VoidSendCharactar4Bit(u8 u8Copy_LCD_Character);

void LCD_VoidInit(void);

void LCD_VoidSendCommand(u8 u8Copy_LCD_Command);

void LCD_VoidSendCharactar(u8 u8Copy_LCD_Character);

void LCD_VoidSendString(char *u8Copy_LCD_String);


void LCD_VoidSetCursorPos(u8 u8Copy_LCD_ROW,s8 u8Copy_LCD_COL);

void LCD_VoidSendNumber(u32 u8Copy_LCD_Number);
void LCD_voidSendSpecialChar(u8 *arr,u8 u8Copy_LCD_ROW,u8 u8Copy_LCD_COL,u8 Copy_CGAddress);


void LCD_voidSendSpecialCharRightToLeft(u8 *arr,u8 u8Copy_LCD_ROW,u8 u8Copy_LCD_COL,u8 Copy_CGAddress);

void LCD_VoidClearDisplay(void);
void LCD_VoidHelloHamkosha(void);
void LCD_VoidHamkoshaPlayFootball(void);
void LCD_VoidHamkoshaCanRun(void);
void LCD_VoidDontKillHamoksha(void);

#endif /* HAL_LCD_LCD_INTERFACE_H_ */
