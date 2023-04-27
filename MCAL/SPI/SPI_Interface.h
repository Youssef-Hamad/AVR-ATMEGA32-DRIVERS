/*
 * SPI_Interface.h
 *
 *  Created on: Apr 11, 2023
 *      Author: Youssef
 */

#ifndef MCAL_SPI_SPI_INTERFACE_H_
#define MCAL_SPI_SPI_INTERFACE_H_



typedef enum{
	Data_Order_LSB_First=1,
	Data_Order_MSB_First
}DataOrder_Type;

typedef enum{
	Enable_Interrupt=1,
	Disable_Interrupt
}Interrupt_state_Type;

typedef enum{
	Rise_Leading=1,
	Fall_Leading
}Clock_Polarity_Type;

typedef enum{
	Sample_Leading=1,
	Setup_Leading
}Clock_Phase;

typedef enum{
	Prescaler_4=0,
	Prescaler_16=1,
	Prescaler_64=2,
	Prescaler_128=3,
}Clock_Prescaler_Type;




typedef struct {
	DataOrder_Type Dataorder;
	Interrupt_state_Type Interrupt_state;
	Clock_Polarity_Type Clock_Polarity;
	Clock_Phase Clock_Phase;
	Clock_Prescaler_Type Clock_Prescaler;
}Master_Config;

typedef struct {
	Interrupt_state_Type Interrupt_state;
	Clock_Polarity_Type Clock_Polarity;
	Clock_Phase Clock_Phase;
}Slave_Config;


void SPI_Master_Init(const Master_Config* const UserConfig);
void SPI_Slave_Init(const Slave_Config* const UserConfig);

void SPI_Send_Data(const u8 Copy_u8Data);
u8 SPI_Read_SPDR(void);

void SPI_Setcallback(void(*FunPtr)(void));

void SPI_SetAsMaster(void);

#endif /* MCAL_SPI_SPI_INTERFACE_H_ */
