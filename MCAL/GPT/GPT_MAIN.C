/*
/*
 * main.c
 *
 *  Created on: 28 Mar 2023
 *      Author: Youssef
 */
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

void TIMER0_Void_CompareMatchISR(void);

//void PWM_WAVE(void);
void AsyncDelay(void);
void main(void){

	DIO_s8SetPinDirection(DIO_U8_PORTD,DIO_U8_PIN5,DIO_U8_PIN_DIR_OUTPUT);

	TIMER1_VoidSetICR(40000);
	TIMER1_VoidInit();
	LCD_VoidInit();
//	SPI_Master_Init(&user_Master);

	DIO_s8SetPinDirection(DIO_U8_PORTB,DIO_U8_PIN3,DIO_U8_PIN_DIR_OUTPUT); 	//	TIMER0 PWM WAVE OUTPUT
//	DIO_s8SetPinDirection(DIO_U8_PORTD,DIO_U8_PIN5,DIO_U8_PIN_DIR_OUTPUT);
	DIO_s8SetPinDirection(DIO_U8_PORTD,DIO_U8_PIN6,DIO_U8_PIN_DIR_INPUT);	//ICU POINT


	TIMER0_SetCompareValue(100);
	ICU_VoidSetCallBack(ICU_MeasureFreq);
	ICU_VoidEnableICU(ICU_RISE_TRIGGER);


	TIMER0_VoidPWM();
	TIMER1_VoidStart();
	GIE_VoidEnable();


	while(1){
			for(u32 i=1500;i<3500;i++){
				TIMER1SetChannelACompareValue(i);
				_delay_ms(15);
			}
	}

}


void TIMER0_Void_CompareMatchISR(void){
	/* the PWM wave starts every 20ms 16MHz,64 Pre-scaler(125 Compare Value)*/

	static u16 u16_20ms_Counter=0;
	//static u16_5ms_counter=0;
	//static u16_15ms_counter=0;
	u16_20ms_Counter++;
	/*5ms after Wave starts Turn LED off*/
	if(u16_20ms_Counter==10){
		DIO_s8SetPinValue(DIO_U8_PORTA,DIO_U8_PIN0,DIO_U8_PIN_LOW);
	}
	/*10ms after Wave starts Turn LED off*/
	if(u16_20ms_Counter==20){
		DIO_s8SetPinValue(DIO_U8_PORTA,DIO_U8_PIN3,DIO_U8_PIN_LOW);
	}
	/*15ms after Wave starts Turn LED off*/
	if(u16_20ms_Counter==30){
		DIO_s8SetPinValue(DIO_U8_PORTA,DIO_U8_PIN7,DIO_U8_PIN_LOW);
	}

	/* Every 20ms Turn LED ON*/
	if(u16_20ms_Counter==40)
	{
		DIO_s8SetPinValue(DIO_U8_PORTA,DIO_U8_PIN0,DIO_U8_PIN_HIGH);
		DIO_s8SetPinValue(DIO_U8_PORTA,DIO_U8_PIN3,DIO_U8_PIN_HIGH);
		DIO_s8SetPinValue(DIO_U8_PORTA,DIO_U8_PIN7,DIO_U8_PIN_HIGH);
		u16_20ms_Counter=0;
	}


}

void AsyncDelay(void){
	DIO_s8TogglePin(DIO_U8_PORTD,DIO_U8_PIN0);
	/*Disable OCR1A Interrupt*/
	ClearBit(TIMSK,TIMSK_OCIE0_BIT);

}


void ICU_MeasureFreq(void){
	static u8 local_u8Flag=0;
		local_u8Flag++;
		/*Skip first Reading to avoid any disorders in wave and timers */
		if(2==local_u8Flag){

			ICU_Readings[0]=ICR1_2BYTE;

		}
		else if(3==local_u8Flag){
			ICU_Readings[1]=ICR1_2BYTE;
			ICU_SetEdgeTrigger(ICU_FALL_TRIGGER);


		}
		else if(4==local_u8Flag){
			ICU_Readings[2]=ICR1_2BYTE;

			PeriodTime=ICU_Readings[1]-ICU_Readings[0];
			Timeon=ICU_Readings[2]-ICU_Readings[1];
			LCD_VoidSendNumber(PeriodTime);
			LCD_VoidSendString(" ");
			LCD_VoidSendNumber(Timeon);
			ICU_VoidDisableICU();
			TIMER1_VoidStop();

	}

}
 * GPT_MAIN.C
 *
 *  Created on: Apr 10, 2023
 *      Author: Youssef
 */


#endif
