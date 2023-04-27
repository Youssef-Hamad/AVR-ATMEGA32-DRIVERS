/*
 * LED_prog.c
 *
 *  Created on: 27 Mar 2023
 *      Author: Youssef
 */

#include "../../MCAL/DIO/DIO_Interface.h"
#include "LED_config.h"
#include "LED_Interface.h"



void LED_VoidInit(u8 u8Copy_Led_PortId ,u8 u8Copy_Led_PinId){
	DIO_s8SetPinDirection(u8Copy_Led_PortId,u8Copy_Led_PinId,DIO_U8_PIN_DIR_OUTPUT);
}

void LED_VoidOn(u8 u8Copy_Led_PortId ,u8 u8Copy_Led_PinId){
	DIO_s8SetPinValue(u8Copy_Led_PortId,u8Copy_Led_PinId,DIO_U8_PIN_HIGH);
}

void LED_VoidOff(u8 u8Copy_Led_PortId ,u8 u8Copy_Led_PinId){
	DIO_s8SetPinValue(u8Copy_Led_PortId,u8Copy_Led_PinId,DIO_U8_PIN_LOW);
}

void LED_VoidToggleLed(u8 u8Copy_Led_PortId ,u8 u8Copy_Led_PinId){
	DIO_s8TogglePin(u8Copy_Led_PortId,u8Copy_Led_PinId);
}
