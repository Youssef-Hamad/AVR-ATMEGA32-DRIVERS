/*
 * LCD_Config.h
 *
 *  Created on: 28 Mar 2023
 *      Author: Youssef
 */

#ifndef HAL_LCD_LCD_CONFIG_H_
#define HAL_LCD_LCD_CONFIG_H_

#define LCD_MODE	LCD_8_BIT_MODE            //Please choose 4BIT or 8BIT mode

#define LCD_EntryMode  LCD_EntryInc_MODE  	  //Please Choose Increment or decrement Mode (Shift off)

#define LCD_DATA_Port  DIO_U8_PORTC
#define LCD_CTRL_Port  DIO_U8_PORTA



#define LCD_U8_RS_PIN DIO_U8_PIN7
#define LCD_U8_RW_PIN DIO_U8_PIN6
#define LCD_U8_EN_PIN DIO_U8_PIN5


#endif /* HAL_LCD_LCD_CONFIG_H_ */
