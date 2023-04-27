/*
 * PB_Program.c
 *
 *  Created on: 2 Apr 2023
 *      Author: Youssef
 */

#include "../../INC/STD_TYPES.h"

#include "../../MCAL/DIO/DIO_Interface.h"

#include "PB_Private.h"
#include "PB_Config.h"

#include "PB_Interface.h"

void PB_u8_PBInit(u8 u8CopyConnection)
{

     if(u8CopyConnection==PB_PULLUP)
     {
    	DIO_s8SetPinDirection(PB_PIN ,DIO_U8_PIN_DIR_INPUT_PULLUP);

     }
     else if (u8CopyConnection==PB_PULLDOWN)
     {
    	 DIO_s8SetPinDirection(PB_PIN ,DIO_U8_PIN_DIR_INPUT);
     }
}

s8   PB_u8_PBState(u8 u8CopyConnection)
{
	u8 u8local_state=0 ;
	if(u8CopyConnection==PB_PULLUP)
	{
		u8local_state=DIO_u8GetPinValue(PB_PIN);
		if(u8local_state ==1 )
		{
			return PB_NONPRESSED;
		}
		else if (u8local_state ==0)
		{
			return PB_PRESSED;
		}
	}
	else if(u8CopyConnection==PB_PULLDOWN)
	{
		u8local_state=DIO_u8GetPinValue(PB_PIN);
		if(u8local_state==0 )
		{
			return PB_NONPRESSED;
		}
		else if (u8local_state==1)
		{
			return PB_PRESSED;
		}
	}
	else
	{

	}
	return -1;
}
