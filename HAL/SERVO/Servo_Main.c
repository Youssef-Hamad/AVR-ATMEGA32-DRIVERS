/*
 * Servo_Main.c
 *
 *  Created on: Apr 12, 2023
 *      Author: Youssef
 */
#if 0
#include "HAL/SERVO/SERVO_Interface.h"
//#include "HAL/KEYPAD/KEYPAD_Interface.h"
//#include "HAL/SSD/SSD_Interface.h"
//#include "HAL/DCMOTOR/DCMOTOR_Interface.h"
#include <util/delay.h>
#include "MCAL/DIO/DIO_Interface.h"
//#include "MCAL/EXTI/EXTI_Interface.h"
#include "MCAL/GPT/GPT_Interface.h"
//#include "MCAL/ADC/ADC_Interface.h"
//#include "HAL/LCD/LCD_Interface.h"
//#include "MCAL/GPT/GPT_Interface.h"
//#include "HAL/SSD/SSD_Interface.h"
//#include "MCAL/SPI/SPI_Interface.h"
void main(void){
	u8 MAP= 0;

	DIO_s8SetPinDirection(DIO_U8_PORTD,DIO_U8_PIN5,DIO_U8_PIN_DIR_OUTPUT);

	while(1){
			for(u16 i=0;i<180;i+=10)
			{
				_delay_ms(1000);
				Servo_VoidSetAngle(i);
				_delay_ms(1000);


			}
	}
}
#endif
