/*
 * LED_interface.h
 *
 *  Created on: 27 Mar 2023
 *      Author: Youssef
 */

#ifndef HAL_LED_LED_INTERFACE_H_
#define HAL_LED_LED_INTERFACE_H_



void LED_VoidInit(u8 u8Copy_Led_PortId ,u8 u8Copy_Led_PinId);

void LED_VoidOn(u8 u8Copy_Led_PortId ,u8 u8Copy_Led_PinId);

void LED_VoidOff(u8 u8Copy_Led_PortId ,u8 u8Copy_Led_PinId);

void LED_VoidToggleLed(u8 u8Copy_Led_PortId ,u8 u8Copy_Led_PinId);



#endif /* HAL_LED_LED_INTERFACE_H_ */
