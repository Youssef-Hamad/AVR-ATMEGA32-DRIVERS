/*
 * EXTI_Program.c
 *
 *  Created on: 2 Apr 2023
 *      Author: Youssef
 */

#include "../../INC/MATH_BIT.h"
#include "../../INC/STD_TYPES.h"
#include "../GIE/GIE_Interface.h"
#include "../DIO/DIO_Interface.h"
#include "EXTI_Private.h"
#include "EXTI_Config.h"
#include "EXTI_Interface.h"

//Array of static function pointers
static void(*EXTI_ISR[3])(void)={NULL,NULL,NULL};

//Initialize Interrupt0 Pre-build
void EXTI_VoidInitInterrupt0(void){
#if EXTI_SenseControlInt0==EXTI_SenseFall

	//Set sense to Falling edge
	ClearBit(MCUCR,INT0_SENSEBIT0);
	SetBit(MCUCR,INT0_SENSEBIT1);

#elif EXTI_SenseControlInt0==EXTI_SenseRise
	//Set sense to Rising edge
	SetBit(MCUCR,INT0_SENSEBIT0);
	SetBit(MCUCR,INT0_SENSEBIT1);


#elif EXTI_SenseControlInt0==EXTI_SenseAny
	//Set sense to Detect Any change in signal
	SetBit(MCUCR,INT0_SENSEBIT0);
	ClearBit(MCUCR,INT0_SENSEBIT1);


#elif EXTI_SenseControlInt0==EXTI_SenseLow
	//Set sense to Low state signal
	ClearBit(MCUCR,INT0_SENSEBIT0);
	ClearBit(MCUCR,INT0_SENSEBIT1);

#endif

	//Enable External Interrupt0
	SetBit(GICR,INT0_CONTROLBIT);
}

//Initialize Interrupt1 Pre-build
void EXTI_VoidInitInterrupt1(void){
#if EXTI_SenseControlInt1==EXTI_SenseFall

	//Set sense to Falling edge//
	ClearBit(MCUCR,INT1_SENSEBIT0);
	SetBit(MCUCR,INT1_SENSEBIT1);

#elif EXTI_SenseControlInt1==EXTI_SenseRise
	//Set sense to Rising edge
	SetBit(MCUCR,INT1_SENSEBIT0);
	SetBit(MCUCR,INT1_SENSEBIT1);


#elif EXTI_SenseControlInt1==EXTI_SenseAny
	//Set sense to Detect Any change in signal
	SetBit(MCUCR,INT1_SENSEBIT0);
	ClearBit(MCUCR,INT1_SENSEBIT1);


#elif EXTI_SenseControlInt1==EXTI_SenseLow
	//Set sense to Low State
	ClearBit(MCUCR,INT1_SENSEBIT0);
	ClearBit(MCUCR,INT1_SENSEBIT1);

#endif

	//Enable External Interrupt  1
	SetBit(GICR,INT1_CONTROLBIT);
}

//Initialize Interrupt2 Pre-build
void EXTI_VoidInitInterrupt2(void){
#if EXTI_SenseControlInt2==EXTI_SenseFall

	//Set sense to Falling edge//
	ClearBit(MCUCSR,INT2_SENSEBIT0);

#elif EXTI_SenseControlInt2==EXTI_SenseRise
	//Set sense to Rising edge//
	SetBit(MCUCSR,INT2_SENSEBIT0);



#endif


	SetBit(GICR,INT2_CONTROLBIT); //Enable External Interrupt0
}


//Initialize Specific Interrupt (Runtime build)
void EXTI_voidInitInterrupt(u8 u8CopyInturruptID,u8 u8CopySenseControl){
	//Loop Over Interrupts
	switch(u8CopyInturruptID)
	{
	case INT_0:
		//Loop Over Sense Signals for Interrupt 0
		switch(u8CopySenseControl)
		{
		case EXTI_SenseLow:
			//Set sense to Low State
			ClearBit(MCUCR,INT0_SENSEBIT0);
			ClearBit(MCUCR,INT0_SENSEBIT1);

			//Enable External Interrupt0
			SetBit(GICR,INT0_CONTROLBIT);
			break;
		case EXTI_SenseAny:
			//Set sense to Detect Any change in signal
			SetBit(MCUCR,INT0_SENSEBIT0);
			ClearBit(MCUCR,INT0_SENSEBIT1);

			//Enable External Interrupt0
			SetBit(GICR,INT0_CONTROLBIT);
			break;
		case EXTI_SenseFall:
			//Set sense to Falling edge
			ClearBit(MCUCR,INT0_SENSEBIT0);
			SetBit(MCUCR,INT0_SENSEBIT1);

			//Enable External Interrupt0
			SetBit(GICR,INT0_CONTROLBIT);
			break;
		case EXTI_SenseRise:
			//Set sense to Rising edge
			SetBit(MCUCR,INT0_SENSEBIT0);
			SetBit(MCUCR,INT0_SENSEBIT1);

			//Enable External Interrupt0
			SetBit(GICR,INT0_CONTROLBIT);
			break;
		default:
			break;
		}
			break;
	case INT_1:
		//Loop Over Sense Signals for Interrupt 1
		switch(u8CopySenseControl)
		{
		case EXTI_SenseLow:
			//Set sense to Low State
			ClearBit(MCUCR,INT1_SENSEBIT0);
			ClearBit(MCUCR,INT1_SENSEBIT1);

			//Enable External Interrupt  1
			SetBit(GICR,INT1_CONTROLBIT);
			break;
		case EXTI_SenseAny:
			//Set sense to Detect Any change in signal
			SetBit(MCUCR,INT1_SENSEBIT0);
			ClearBit(MCUCR,INT1_SENSEBIT1);

			//Enable External Interrupt  1
			SetBit(GICR,INT1_CONTROLBIT);
			break;
		case EXTI_SenseFall:
			//Set sense to Falling edge
			ClearBit(MCUCR,INT1_SENSEBIT0);
			SetBit(MCUCR,INT1_SENSEBIT1);

			//Enable External Interrupt  1
			SetBit(GICR,INT1_CONTROLBIT);
			break;
		case EXTI_SenseRise:
			//Set sense to Rising edge
			SetBit(MCUCR,INT1_SENSEBIT0);
			SetBit(MCUCR,INT1_SENSEBIT1);

			//Enable External Interrupt  1
			SetBit(GICR,INT1_CONTROLBIT);
			break;
		default:
			break;
		}
	break;
	case INT_2:
		//Loop Over Sense Signals for Interrupt 2
		switch(u8CopySenseControl)
		{
		case EXTI_SenseFall:
			//Set sense to Falling edge
			ClearBit(MCUCSR,INT2_SENSEBIT0);

			//Enable External Interrupt0
			SetBit(GICR,INT2_CONTROLBIT);
			break;
		case EXTI_SenseRise:
			//Set sense to Rising edge
			SetBit(MCUCSR,INT2_SENSEBIT0);

			//Enable External Interrupt0
			SetBit(GICR,INT2_CONTROLBIT);
			break;
		default:
			break;
		}
			break;
		default:
		break;
	}
}

//Disable   Interrupt
void EXIT_VoidDisableInterrupt(u8 u8CopyInterrupt)
{
	//Loop Over Interrupts
	switch(u8CopyInterrupt)
	{
	case INT_0:
		//Disable External Interrupt0
		ClearBit(GICR,INT0_CONTROLBIT);
		break;
	case INT_1:
		//Disable External Interrupt1
		ClearBit(GICR,INT1_CONTROLBIT);
		break;
	case INT_2:
		//Disable External Interrupt2
		ClearBit(GICR,INT2_CONTROLBIT);
		break;
	default:
		break;
	}
}

//Call back   Interrupt0
u8 EXTI_VoidSetcallback0(void(*user_function)(void))
{
	u8 u8Errorstate=OK;
	if(user_function==NULL){
		u8Errorstate=NULL_POINTER;
	}
	else
	{
		EXTI_ISR[0]=user_function;
	}
	return u8Errorstate;

}

//Call back   Interrupt1
u8 EXTI_voidSetcallback1(void(*user_function)(void)){
	u8 u8Errorstate=OK;
	if(user_function==NULL){
		u8Errorstate=NULL_POINTER;
	}
	else
	{
		EXTI_ISR[1]=user_function;
	}
	return u8Errorstate;
}
//Call back   Interrupt2
u8 EXTI_voidSetcallback2(void(*user_function)(void)){
	u8 u8Errorstate=OK;
	if(user_function==NULL){
		u8Errorstate=NULL_POINTER;
	}
	else
	{
		EXTI_ISR[2]=user_function;
	}
	return u8Errorstate;
}


/*Watch Dog Enable */
void WatchDog_VoidEnable(void){
	/*Turn off disable bit*/
	ClearBit(WDTCR,WDTCR_WDTOE);
	/*Enable WatchDog*/
	SetBit(WDTCR,WDTCR_WDE);
}
/*Start Watch Dog*/
void WatchDog_VoidStart(u8 Copy_Prescaler){
	WDTCR&=WDTCR_PRESCALER_MASK;
	WDTCR |=Copy_Prescaler;
}

void WatchDog_VoidDisable(void){

	WDTCR|=0b00011000;
	WDTCR=0x00;
}





//Interrupt 0 PORTD PIN 2
u8 __vector_1(void) __attribute__((signal));
u8 __vector_1(void)
{
	u8 u8ErrorState=OK;
	if(EXTI_ISR[0]==NULL){
		u8ErrorState=NULL_POINTER;
	}
	else
	{
		EXTI_ISR[0]();
	}
	return u8ErrorState;
}
//Interrupt 1 PORT D PIN 3
u8 __vector_2(void) __attribute__((signal));
u8 __vector_2(void)
{
	u8 u8ErrorState=OK;
	if(EXTI_ISR[1]==NULL){
		u8ErrorState=NULL_POINTER;
	}
	else
	{
		EXTI_ISR[1]();
	}
	return u8ErrorState;

}
//Interrupt 2 PORT B PIN 3
u8 __vector_3(void) __attribute__((signal));
u8 __vector_3(void)
{
	u8 u8ErrorState=OK;
	if(EXTI_ISR[0]==NULL){
		u8ErrorState=NULL_POINTER;
	}
	else
	{
		EXTI_ISR[2]();
	}
	return u8ErrorState;
}
u8 (*ptr0)(void)=&__vector_1;
u8 (*ptr1)(void)=&__vector_2;
