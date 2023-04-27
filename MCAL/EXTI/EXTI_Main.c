/*
 * EXTI_Main.c
 *
 *  Created on: 4 Apr 2023
 *      Author: Youssef
 */
/*
//#include "HAL/LCD/LCD_Interface.h"
//#include "HAL/KEYPAD/KEYPAD_Interface.h"
//#include "HAL/SSD/SSD_Interface.h"
//#include "HAL/DCMOTOR/DCMOTOR_Interface.h"
//#include <util/delay.h>
//#include "MCAL/DIO/DIO_Interface.h"
//#include "MCAL/EXTI/EXTI_Interface.h"


extern void(*EXTI_ISR[3])(void);
void EXTI_VoidISR0(void);  	//User defined ISR
void EXTI_VoidISR1(void);	//User defined ISR

void __vector_1(void) __attribute__((signal));

void __vector_1(void)
{
	EXTI_ISR[0]();
}
void __vector_2(void) __attribute__((signal));

void __vector_2(void)
{
	EXTI_ISR[1]();

}



void main(void){
	DIO_s8SetPinDirection(DIO_U8_PORTD,DIO_U8_PIN3,DIO_U8_PORT_DIR_INPUT_PULLUP);
	DIO_s8SetPinDirection(DIO_U8_PORTD,DIO_U8_PIN2,DIO_U8_PORT_DIR_INPUT_PULLUP);

	DIO_s8SetPinDirection(DIO_U8_PORTD,DIO_U8_PIN7,DIO_U8_PIN_DIR_OUTPUT);
	DIO_s8SetPinDirection(DIO_U8_PORTD,DIO_U8_PIN5,DIO_U8_PIN_DIR_OUTPUT);



	EXTI_VoidSetcallback0(EXTI_VoidISR0);
	EXTI_voidSetcallback1(EXTI_VoidISR1);
	//For run time build
	//	EXTI_voidInitInturrupt(INT_1,EXTI_SenseAny);
	//	EXTI_voidInitInturrupt(INT_0,EXTI_SenseLow);
	// for pre-build
	EXTI_VoidInitInterrupt1();
	EXTI_VoidInitInterrupt0();


	//Enable Global Interrupt
	GIE_VoidEnable();



	while(1){

		//Dummy Main (toggle  an led Every second)
		DIO_s8SetPinValue(DIO_U8_PORTD,DIO_U8_PIN5,DIO_U8_PIN_HIGH);
		_delay_ms(1000);
		DIO_s8SetPinValue(DIO_U8_PORTD,DIO_U8_PIN5,DIO_U8_PIN_LOW);
		_delay_ms(1000);

	}

}

void EXTI_VoidISR0(void){//Function for INT0
	EXIT_VoidDisableInterrupt(INT_1);
}
void EXTI_VoidISR1(void){//Function for INT1
	ToggleBit(PORTD,DIO_U8_PIN7);
}
*/
