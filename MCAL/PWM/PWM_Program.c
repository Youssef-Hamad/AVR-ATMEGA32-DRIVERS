/*
 * PWM_Program.c
 *
 *  Created on: Apr 8, 2023
 *      Author: Youssef
 */
#include "../../INC/MATH_BIT.h"
#include "../../INC/STD_TYPES.h"


#include "PWM_Private.h"
#include "PWM_Config.h"
#include "PWM_Interface.h"

void PWM_VoidSetFreq(u8 Copy_u8Freq){

	u64 Local_TimerFreq=(u64)((SYSTEM_FREQ_MHZ*1000000)/PWM_TIMER1_PRESECALER_DIVISOR);

	ICR1_2BYTE=(Local_TimerFreq/Copy_u8Freq);


}
void PWM_VoidSetDutyCycle(u8 Copy_u8DutyCycle){
	u16 Local_u8Temp=0;
	Local_u8Temp=(ICR1_2BYTE*Copy_u8DutyCycle)/100;
	OCR1A_2BYTE=Local_u8Temp;
}
void PWM_VoidStartPWM(u8 Copy_u8Freq,u8 Copy_u8DutyCycle,u8 Copy_u8Channel){

	u64 Local_TimerFreq=(u64)((SYSTEM_FREQ_MHZ*1000000ULL)/(PWM_TIMER1_PRESECALER_DIVISOR*Copy_u8Freq));
	u64 Local_OCR1x=0;
	if(Copy_u8DutyCycle<100)
	{
		if(Local_TimerFreq<MAX_16_BIT_VALUE){
			/*If Tick counts and duty cycle are in range*/
			ICR1_2BYTE= Local_TimerFreq;
			Local_OCR1x=((u64)ICR1_2BYTE*Copy_u8DutyCycle)/100Ull;
			OCR1A_2BYTE=Local_OCR1x;

			/*Setting the timer to fast PWM*/
			ClearBit(TCCR1A,TCCR1A_WaveFormModeBit0);
			SetBit(TCCR1A,TCCR1A_WaveFormModeBit1);
			SetBit(TCCR1B,TCCR1B_WaveFormModeBit0);
			SetBit(TCCR1B,TCCR1B_WaveFormModeBit1);
			/*Choose channel output wave on */
			if(Copy_u8Channel==CHANNEL_A){
			/*NON inverting PWM CLEAR TOP, SET UPON MATCH*/
				ClearBit(TCCR1A,TCCR1A_OutModeChannelA_BIT0);
				SetBit(TCCR1A,TCCR1A_OutModeChannelA_BIT1);
			}
			else if(Copy_u8Channel==CHANNEL_B){
				/*NON inverting PWM CLEAR TOP, SET UPON MATCH*/
				ClearBit(TCCR1A,TCCR1A_OutModeChannelB_BIT0);
				SetBit(TCCR1A,TCCR1A_OutModeChannelB_BIT1);
			}
			else{
				/*No output will be generated since an invalid channel was selected*/
				ClearBit(TCCR1A,TCCR1A_OutModeChannelA_BIT0);
				ClearBit(TCCR1A,TCCR1A_OutModeChannelA_BIT1);
				ClearBit(TCCR1A,TCCR1A_OutModeChannelB_BIT0);
				ClearBit(TCCR1A,TCCR1A_OutModeChannelB_BIT1);
			}
			/*Set clock prescaler and start timer*/
			TCCR1B&=TCCR1B_ClockSelectMask;
			TCCR1B|=PWM_TIMER1_PRESECALER_Select;

		}
		else{
			/*Do nothing if Ticks counts are too high*/
		}
	}
	else
	{
		/*Do nothing if Duty cycle is too high*/
	}
}
void PWM_VoidStop(void){
	TCCR1B&=TCCR1B_ClockSelectMask;
	/*Flush Timer Counter Register*/
	TCNT1_2BYTE=0;

}