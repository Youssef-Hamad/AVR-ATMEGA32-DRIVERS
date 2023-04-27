#if 0
//#include "HAL/KEYPAD/KEYPAD_Interface.h"
//#include "HAL/SSD/SSD_Interface.h"
//#include "HAL/DCMOTOR/DCMOTOR_Interface.h"
#include <util/delay.h>
#include "MCAL/DIO/DIO_Interface.h"
#include "MCAL/EXTI/EXTI_Interface.h"
#include "MCAL/ADC/ADC_Interface.h"
#include "HAL/LCD/LCD_Interface.h"

void ADC_Void_ISR(void);
u16 GlobalReading=0;

void main(void){
	//Enable Global Interrupt
	GIE_VoidEnable();
	LCD_VoidInit();
	ADC_VoidInit();




	DIO_s8SetPortDirection(DIO_U8_PORTB,DIO_U8_PIN_DIR_OUTPUT);
	DIO_s8SetPinDirection(DIO_U8_PORTA,DIO_U8_PIN3,DIO_U8_PORT_DIR_INPUT);
	DIO_s8SetPinDirection(DIO_U8_PORTD,DIO_U8_PIN5,DIO_U8_PORT_DIR_INPUT);

	while(1){

//		ADC_u8StartConversionAsync(&GlobalReading,ADC_10BIT_DATA,ADC_MUX_SINGLE_PIN3,ADC_Void_ISR);
//		ADC_u8StartConversionSync(&GlobalReading,ADC_10BIT_DATA,ADC_MUX_SINGLE_PIN3);

		LCD_VoidSendNumber(GlobalReading);
		_delay_ms(100);
		LCD_VoidSendCommand(LCD_DisplayClear);
		_delay_ms(100);

	}

}
void ADC_Void_ISR(void){

}


#endif
