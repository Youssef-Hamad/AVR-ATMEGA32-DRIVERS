/*
 * ICU_Program.c
 *
 *  Created on: Apr 13, 2023
 *      Author: Youssef
 */

#include "../../INC/MATH_BIT.h"
#include "../../INC/STD_TYPES.h"
#include "ICU_Private.h"
#include "ICU_Config.h"
#include "ICU_Interface.h"



void ICU_SetEdgeTrigger(u8 Copy_u8Edege){
	/*Select ICU EDGE TRIGGER*/
	switch (Copy_u8Edege)
	{
	case ICU_FALL_TRIGGER:
		ClearBit(TCCR1B,TCCR1B_ICES1);
		break;
	case ICU_RISE_TRIGGER:
		SetBit(TCCR1B,TCCR1B_ICES1);
		break;
	default:
		break;
	}
}
void ICU_VoidDisableICU(void){
	/*Disable Input capture Interrupt */
	ClearBit(TIMSK,TIMSK_TICIE_BIT);
}
void ICU_VoidEnableICU(u8 Copy_u8Edege){

	/*Select ICU EDGE TRIGGER*/
	switch (Copy_u8Edege)
	{
	case ICU_FALL_TRIGGER:
		ClearBit(TCCR1B,TCCR1B_ICES1);
		break;
	
	case ICU_RISE_TRIGGER:
		SetBit(TCCR1B,TCCR1B_ICES1);
		break;
	default:
		break;
	}
	/*Enable Noise Mitigation*/
	SetBit(TCCR1B,TCCR1B_ICNC1);
	/*Enable Input capture Interrupt */
	SetBit(TIMSK,TIMSK_TICIE_BIT);
}

void ICU_VoidSetCallBack(void(*UserFunction)(void)){

	CallBackPtrICU=UserFunction;
}
u16 ICU_VoidReadICR(void){
	return ICR1_2BYTE;
}






/*Interrupt Vector for Input capture event*/
void __vector_6(void) __attribute__((signal));
void __vector_6(void){

	if(CallBackPtrICU!=NULL){
		CallBackPtrICU();
	}
	else{
		/*Do nothing*/
	}
}
