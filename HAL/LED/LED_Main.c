/*
 * main.c
 *
 *  Created on: 27 Mar 2023
 *      Author: Youssef
 */

#if 0
#include <util/delay.h>

#include "../../INC/MATH_BIT.h"
#include "../../INC/STD_TYPES.h"

#include "LED_Interface.h"
//#include "MCAL/DIO_Interface.h"
void Mode_one(void);
void Mode_two(void);
void Mode_three(void);

void lcdmain(void)
{
	LED_VoidInit(LED_ONE_PortId,LED_ONE_PinId);
	LED_VoidInit(LED_TWO_PortId,LED_TWO_PinId);
	LED_VoidInit(LED_THREE_PortId,LED_THREE_PinId);
	LED_VoidInit(LED_FOUR_PortId,LED_FOUR_PinId);
	LED_VoidInit(LED_FIVE_PortId,LED_FIVE_PinId);
	LED_VoidInit(LED_SIX_PortId,LED_SIX_PinId);
	LED_VoidInit(LED_SEVEN_PortId,LED_SEVEN_PinId);
	LED_VoidInit(LED_EIGHT_PortId,LED_EIGHT_PinId);
	while(1)
	{
//		Mode_one();
//		Mode_two();
		Mode_three();
//		LED_VoidOn(LED_TWO);
	}
}

void Mode_one(void){//Flashing


	for(u8 i = LED_ONE_PinId;i<=LED_EIGHT_PinId;i++){
		LED_VoidOn(LED_ONE_PortId,i);
	}
	_delay_ms(500);

	for(u8 i = LED_ONE_PinId;i<=LED_EIGHT_PinId;i++){
		LED_VoidOff(LED_ONE_PortId,i);
	}
	_delay_ms(500);

}
void Mode_two(void){//Shifting left
	for(s8 i = LED_ONE_PinId;i<=LED_EIGHT_PinId;i++)
	{
		LED_VoidOn(LED_ONE_PortId,i);
		_delay_ms(250);
		LED_VoidOff(LED_ONE_PortId,i);
	}
}

void Mode_three(void){//Shifting Right
	for(s8 i = LED_EIGHT_PinId;i>=LED_ONE_PinId;i--)
		{
			LED_VoidOn(LED_ONE_PortId,i);
			_delay_ms(250);
			LED_VoidOff(LED_ONE_PortId,i);
		}
}
void Mode_four(void){
}
#endif

