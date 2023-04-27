/*
 * LCD_Private.h
 *
 *  Created on: 28 Mar 2023
 *      Author: Youssef
 */

#ifndef HAL_LCD_LCD_PRIVATE_H_
#define HAL_LCD_LCD_PRIVATE_H_

#define LCD_4_BIT_MODE		7
#define LCD_8_BIT_MODE		6

#define LCD_FunctionSet8bit  0x3C //8bit ,2 lines, 5x7 dot
#define LCD_FunctionSet4bit	0b00101000 //4bit ,2 lines, 5x7 dot

#define LCD_Cursor_Display_shift 0b00011000//Shift entire display to left once without affecting Data
										   //Cursor follows the display shift

#define LCD_DisplayOn		0x0F
#define LCD_DisplayClear 	0x01



#define LCD_ReturnHome		0x2













#define LCD_RightShiftCursor 	0b00010100 //Increment Address counter by one, Keep Display still





//u8 Y[8]={0B00000,0B00000,0B00001,0B00001,0B11111,0B00000,0B00110,0B00000};
//u8 OU[8]={0B00000,0B00110,0B01001,0B00110,0B00111,0B01000,0B10000,0B00000};
//u8 S[8]={0B00000,0B00000,0B10101,0B10101,0B11111,0B00000,0B00000,0B00000};
//u8 F[8]={0B00000,0B00010,0B00000,0B00101,0B11111,0B00000,0B00000,0B00000};
//u8 F2[8]={0B00000,0B00000,0B00000,0B00100,0B00111,0B00000,0B00000,0B00000};

#endif /* HAL_LCD_LCD_PRIVATE_H_ */
