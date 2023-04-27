/*
 * SSD_TIMER.C
 *
 *  Created on: Apr 7, 2023
 *      Author: Youssef
 */

/*Multiplexing 2 SSDs with 2 opposite counters (Ascending & Descending) using one timer*/
#if 0

//#include "HAL/KEYPAD/KEYPAD_Interface.h"
//#include "HAL/SSD/SSD_Interface.h"
//#include "HAL/DCMOTOR/DCMOTOR_Interface.h"
#include <util/delay.h>
#include "MCAL/DIO/DIO_Interface.h"
#include "MCAL/EXTI/EXTI_Interface.h"
#include "MCAL/ADC/ADC_Interface.h"
#include "HAL/LCD/LCD_Interface.h"
#include "MCAL/GPT/GPT_Interface.h"
#include "HAL/SSD/SSD_Interface.h"

void TIMER0_Void_CompareISR(void);


void main(void){
	DIO_s8SetPinDirection(DIO_U8_PORTA,DIO_U8_PIN3,DIO_U8_PORT_DIR_OUTPUT);//SSD1 ENABLE PIN
	DIO_s8SetPortDirection(DIO_U8_PORTB,DIO_U8_PIN_DIR_OUTPUT);//SSD2 ENABLE PIN
	SSD_VoidInit();

	TIMER0_VoidInit();
	TIMER0_VoidCallBack(TIMER0_Void_CompareISR);

	//Enable Global Interrupt
	GIE_VoidEnable();


	while(1){


	}

}


void TIMER0_Void_CompareISR(void){
	static u16 u16_1SeCounter=0;
	static u16 u16_5miliCounter=0;
	static s8 Displaynumber=9;
	static s8 DisplayNumber2=0;

	static u8 flag=0;
	u16_1SeCounter++;
	u16_5miliCounter++;
	/*For a Compare of 125Ticks(64 Pre-scaler) ,5 ms pass at 5 counts*/
	if(u16_5miliCounter==5){
		if(Displaynumber<0)
		{
			Displaynumber=9;

		}
		if(DisplayNumber2>9)
		{
			DisplayNumber2=0;
		}
		if(flag==0){
			DIO_s8SetPinValue(DIO_U8_PORTB,DIO_U8_PIN7,0);//DISABLE SSD2
			DIO_s8SetPinValue(DIO_U8_PORTA,DIO_U8_PIN4,1);//ENABLE SSD1
			SSD_VoidDisplayNumber(DisplayNumber2);
			flag=1;
		}
		else if (flag==1){
			DIO_s8SetPinValue(DIO_U8_PORTA,DIO_U8_PIN4,0);//DISABLE SSD1
			DIO_s8SetPinValue(DIO_U8_PORTB,DIO_U8_PIN7,1);//ENABLE SSD2
			SSD_VoidDisplayNumber(Displaynumber);
			flag=0;
		}
		u16_5miliCounter=0;
	}
	/*For a Compare of 125Ticks(64 Pre-scaler) , a second passes at 1000 counts*/
	if(u16_1SeCounter==1000)
	{

		Displaynumber--;
		DisplayNumber2++;

		u16_1SeCounter=0;
	}

}
#endif
