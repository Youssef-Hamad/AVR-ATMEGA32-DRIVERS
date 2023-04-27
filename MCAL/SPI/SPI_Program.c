/*
 * SPI_Program.c
 *
 *  Created on: Apr 11, 2023
 *      Author: Youssef
 */
#include "../../INC/STD_TYPES.h"
#include "../../INC/MATH_BIT.h"
#include "SPI_Private.h"
#include "SPI_Interface.h"


static void(*GlobalPtr)(void)=NULL;
void SPI_SetAsMaster(void){
	/*Set as Master*/
	SetBit(SPCR,SPCR_MSTR);
}
void SPI_Double_Clock_Speed(void){
	/*Doubleing the transmission speed*/
	SetBit(SPSR,SPSR_SPI2X);
}

void SPI_Master_Init(const Master_Config* const UserConfig){

	if(UserConfig) //Checking if there is a configuration sent by the user
	{	
		switch(UserConfig->Dataorder)
		{
			case Data_Order_LSB_First:
				SetBit(SPCR,SPCR_DORD);
				break;
			case Data_Order_MSB_First:
				ClearBit(SPCR,SPCR_DORD);
				break;
			default:
				break;
		}
		switch(UserConfig->Interrupt_state)
		{
			case Enable_Interrupt:
				SetBit(SPCR,SPCR_SPIE);
				break;
			case Disable_Interrupt:
				ClearBit(SPCR,SPCR_SPIE);
				break;
			default:
				break;
		}
		switch(UserConfig->Clock_Polarity)
		{
			case Rise_Leading:
				ClearBit(SPCR,SPCR_CPOL);
				break;
			case Fall_Leading:
				SetBit(SPCR,SPCR_CPOL);
				break;
		}
		switch(UserConfig->Clock_Phase)
		{
			case Sample_Leading:
				ClearBit(SPCR,SPCR_CPHA);
				break;
			case Setup_Leading:
				SetBit(SPCR,SPCR_CPHA);
				break;
			default:
				break;
		}
		switch(UserConfig->Clock_Prescaler)
		{
			case Prescaler_4:
				ClearBit(SPCR,SPCR_CR0);
				ClearBit(SPCR,SPCR_CR1);
				ClearBit(SPSR,SPSR_SPI2X);
				break;
			case Prescaler_16:
				SetBit(SPCR,SPCR_CR0);
				ClearBit(SPCR,SPCR_CR1);
				ClearBit(SPSR,SPSR_SPI2X);
				break;
			case Prescaler_64:
				ClearBit(SPCR,SPCR_CR0);
				SetBit(SPCR,SPCR_CR1);
				ClearBit(SPSR,SPSR_SPI2X);
				break;
			case Prescaler_128:
				SetBit(SPCR,SPCR_CR0);
				SetBit(SPCR,SPCR_CR1);
				ClearBit(SPSR,SPSR_SPI2X);
				break;
			default:
				break;
		}
		/*Set as Master*/
		SetBit(SPCR,SPCR_MSTR);
		/*Enable SPI*/
		SetBit(SPCR,SPCR_SPE);
	}
	else{
		/*Do nothing*/
	}

}

void SPI_Slave_Init(const Slave_Config* const UserConfig){
	if(UserConfig) //Checking if there is a configuration sent by the user
	{
		switch(UserConfig->Interrupt_state)
		{
			case Enable_Interrupt:
				SetBit(SPCR,SPCR_SPIE);
				break;
			case Disable_Interrupt:
				ClearBit(SPCR,SPCR_SPIE);
				break;
			default:
				break;
		}
		switch(UserConfig->Clock_Polarity)
		{
			case Rise_Leading:
				ClearBit(SPCR,SPCR_CPOL);
				break;
			case Fall_Leading:
				SetBit(SPCR,SPCR_CPOL);
				break;
		}
		switch(UserConfig->Clock_Phase)
		{
			case Sample_Leading:
				ClearBit(SPCR,SPCR_CPHA);
				break;
			case Setup_Leading:
				SetBit(SPCR,SPCR_CPHA);
				break;
			default:
				break;
		}
		/*Set as Slave*/
		ClearBit(SPCR,SPCR_MSTR);
		/*Enable SPI*/
		SetBit(SPCR,SPCR_SPE);
	}
	else{
		/*Do nothing*/
	}
}
void SPI_Send_Data(const u8 Copy_u8Data){
	SPDR=Copy_u8Data;
}







void SPI_Setcallback(void(*FunPtr)(void)){
	if(FunPtr!=NULL){
		GlobalPtr=FunPtr;
	}
}

u8 SPI_Read_SPDR(void){

	return SPDR;
}
void __vector_12 (void) __attribute__((signal));
void __vector_12 (void){
	if(GlobalPtr!=NULL){
		GlobalPtr();
	}
}
