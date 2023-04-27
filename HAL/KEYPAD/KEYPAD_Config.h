/*
 * KEYPAD_Config.h
 *
 *  Created on: Mar 31, 2023
 *      Author: DWEEBSTARK
 */

#ifndef HAL_KEYPAD_KEYPAD_CONFIG_H_
#define HAL_KEYPAD_KEYPAD_CONFIG_H_


#define KEYPAD_ROW_PORT			DIO_U8_PORTB
#define KEYPAD_COL_PORT			DIO_U8_PORTB

#define KEYPAD_ROW_ONE			DIO_U8_PIN0
#define KEYPAD_ROW_TWO			DIO_U8_PIN1
#define KEYPAD_ROW_THREE		DIO_U8_PIN2
#define KEYPAD_ROW_FOUR			DIO_U8_PIN3

#define KEYPAD_COL_ONE			DIO_U8_PIN4
#define KEYPAD_COL_TWO			DIO_U8_PIN5
#define KEYPAD_COL_THREE		DIO_U8_PIN6
#define KEYPAD_COL_FOUR			DIO_U8_PIN7


#define KEYPAD_CHARACTERS    {{'7','8','9','/'},{'4','5','6','*'},{'1','2','3','-'},{'C','0','=','+'}}

#endif /* HAL_KEYPAD_KEYPAD_CONFIG_H_ */
