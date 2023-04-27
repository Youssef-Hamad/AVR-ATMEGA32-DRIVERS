/*
 * Voltmeter.c
 *
 *  Created on: Apr 6, 2023
 *      Author: Youssef
 */

#if 0

#include <util/delay.h>
#include "../MCAL/DIO/DIO_Interface.h"
#include "../MCAL/EXTI/EXTI_Interface.h"
#include "../MCAL/ADC/ADC_Interface.h"
#include "../HAL/LCD/LCD_Interface.h"

//void EXTI_VoidISR0(void);  	//User defined ISR for INT0
//void EXTI_VoidISR1(void);	//User defined ISR for INT1
//void EXTI_VoidISR2(void);	//User defined ISR for INT2
//extern u8 (*ptr0)(void);
//extern u8 (*ptr1)(void);




void main(void){
	ADC_VoidInit();
	u16 Reading=0;

	DIO_s8SetPortDirection(DIO_U8_PORTB,DIO_U8_PIN_DIR_OUTPUT);
	DIO_s8SetPinDirection(DIO_U8_PORTD,DIO_U8_PIN5,DIO_U8_PORT_DIR_INPUT);

//	DIO_s8SetPinDirection(DIO_U8_PORTD,DIO_U8_PIN3,DIO_U8_PORT_DIR_INPUT_PULLUP);
//	DIO_s8SetPinDirection(DIO_U8_PORTD,DIO_U8_PIN2,DIO_U8_PORT_DIR_INPUT_PULLUP);
//
//	DIO_s8SetPinDirection(DIO_U8_PORTD,DIO_U8_PIN7,DIO_U8_PIN_DIR_OUTPUT);
//	DIO_s8SetPinDirection(DIO_U8_PORTD,DIO_U8_PIN5,DIO_U8_PIN_DIR_OUTPUT);

	LCD_VoidInit();

//	LCD_VoidSendCharactar('A');
//	EXTI_VoidSetcallback0(&EXTI_VoidISR0);
//	EXTI_voidSetcallback1(&EXTI_VoidISR1);
//	EXTI_voidSetcallback2(&EXTI_VoidISR2);
	//For run time build
	//	EXTI_voidInitInturrupt(INT_1,EXTI_SenseAny);
	//	EXTI_voidInitInturrupt(INT_0,EXTI_SenseLow);

	// for pre-build
//	EXTI_VoidInitInterrupt0();
//	EXTI_VoidInitInterrupt1();
////	EXTI_VoidInitInterrupt2();


	//Enable Global Interrupt
	GIE_VoidEnable();




	while(1){
		Reading=ADC_u16GetchannelReading();
		DIO_u8SetPortValue(DIO_U8_PORTB,Reading);
		//Dummy Main (toggle  an led Every second)
//		DIO_s8SetPinValue(DIO_U8_PORTD,DIO_U8_PIN5,DIO_U8_PIN_HIGH);
		_delay_ms(1000);
		LCD_VoidSendCommand(LCD_DisplayClear);
		f64 voltage=(f32)(ADC_TWO_BYTE_DATA*5)/1024;
		LCD_VoidSendNumber(voltage); //2
		LCD_VoidSendString(".");	//
		LCD_VoidSendNumber((voltage*1000)-(((u32)voltage%1000)*1000));
		LCD_VoidSendString(" Volts");
//		DIO_s8SetPinValue(DIO_U8_PORTD,DIO_U8_PIN5,DIO_U8_PIN_LOW);
//		_delay_ms(1000);
//		LCD_VoidSendCharactar('A');
	}

}

//void EXTI_VoidISR0(void){//User defined Function for INT0
////	EXIT_VoidDisableInterrupt(INT_1);
//	LCD_VoidSendCommand(LCD_DisplayClear);
//	LCD_VoidSendNumber(ptr0);
//}
//void EXTI_VoidISR1(void){//User defined Function for INT1
//	ToggleBit(PORTD,DIO_U8_PIN7);
//	LCD_VoidSendCommand(LCD_DisplayClear);
//	LCD_VoidSendNumber(ptr1);
////	LCD_VoidSendCharactar(" ");
////	LCD_VoidSendNumber(&LCD_VoidSendCommand);
//}
//void EXTI_VoidISR2(void)	//User defined Function for INT2
//{
//
//}
void Temp(void){
	u16 Reading=0;
	Reading=ADC_u16GetchannelReading();
	LCD_VoidSendCommand(LCD_DisplayClear);
	u32 mV=((u32)Reading*5000ULL)/1024ULL;
	u32 Temp=mV/10;
	LCD_VoidSendNumber(Temp);
	LCD_VoidSendString(" C");

}

#endif
