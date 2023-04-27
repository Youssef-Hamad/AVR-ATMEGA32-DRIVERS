/*
 * KEYPAD_Interface.h
 *
 *  Created on: Mar 31, 2023
 *      Author: DWEEBSTARK
 */

#ifndef HAL_KEYPAD_KEYPAD_INTERFACE_H_
#define HAL_KEYPAD_KEYPAD_INTERFACE_H_



#define NO_KEY_PRESSED    0XFF




u8 KEYPAD_u8GetPressedButton(void);
void KEYPAD_VoidInit(void);
#endif /* HAL_KEYPAD_KEYPAD_INTERFACE_H_ */
