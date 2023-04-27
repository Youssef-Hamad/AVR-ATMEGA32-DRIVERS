#if 0
#include "HAL/KEYPAD/KEYPAD_Interface.h"
//#include "HAL/SSD/SSD_Interface.h"
//#include "HAL/DCMOTOR/DCMOTOR_Interface.h"
#include <util/delay.h>
#include "MCAL/DIO/DIO_Interface.h"
#include "MCAL/EXTI/EXTI_Interface.h"
#include "MCAL/ADC/ADC_Interface.h"
#include "HAL/LCD/LCD_Interface.h"
#include "MCAL/GPT/GPT_Interface.h"
#include "HAL/SSD/SSD_Interface.h"

LCD_VoidInit();
KEYPAD_VoidInit();

void main(void){
    while(1){
            u8 x=KEYPAD_u8GetPressedButton();
            if(x!=0XFF)
            LCD_VoidSendCharactar(x);
    }
}


#endif