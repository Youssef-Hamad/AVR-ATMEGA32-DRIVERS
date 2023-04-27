/*
 * EEPROM_Program.c
 *
 *  Created on: Apr 24, 2023
 *      Author: DWEEBSTARK
 */
#include <util/delay.h>
#include "EEPROM_Private.h"
#include "EEPROM_Config.h"
#include "../../MCAL/I2C/I2C_Interface.h"
#include "EEPROM_Interface.h"

u8  EEPROM_VoidSendDataByte(u16 Copy_u16address,u8 Copy_u8Data){
	u8 Local_ErrorState=NoError;
	Local_ErrorState=I2C_SendStartCondition();
	if(Local_ErrorState==NoError){
		Local_ErrorState=I2C_SendSlaveAddressWithWrite(EEPROM_FIXED_ADDRESS | EEPROM_A2_VALUE | ((u8)((Copy_u16address>>8)&EEPROM_8K_ADDRESS_MASK)));
		if(Local_ErrorState==NoError){
			Local_ErrorState=I2C_MstrSendDataByte((u8)Copy_u16address);
			if(Local_ErrorState==NoError){
				Local_ErrorState=I2C_MstrSendDataByte(Copy_u8Data);
				if(Local_ErrorState==NoError){
					I2C_SendStopCondition();
						_delay_ms(15);
					/*Writing Process delay for EEPROM minimum 10ms*/

				}
				else{

				}
			}
			else{

			}

		}
		else{

		}
	}
	else{

	}
	return Local_ErrorState;
}


u8  EEPROM_VoidReadDataByte(u16 Copy_u16address,u8* Copy_pu8Data){
	u8 Local_ErrorState=NoError;
	Local_ErrorState=I2C_SendStartCondition();
	if(Local_ErrorState==NoError){
	Local_ErrorState=I2C_SendSlaveAddressWithWrite(EEPROM_FIXED_ADDRESS | EEPROM_A2_VALUE | ((u8)((Copy_u16address>>8)&EEPROM_8K_ADDRESS_MASK)));
		if(Local_ErrorState==NoError){
			Local_ErrorState=I2C_MstrSendDataByte((u8)Copy_u16address);
			if(Local_ErrorState==NoError){
				Local_ErrorState=I2C_SendRepeatedStart();
				if(Local_ErrorState==NoError){
					Local_ErrorState=I2C_SendSlaveAddressWithRead(EEPROM_FIXED_ADDRESS | EEPROM_A2_VALUE | ((u8)((Copy_u16address>>8)&EEPROM_8K_ADDRESS_MASK)));
					if(Local_ErrorState==NoError){
						I2C_MstrReadDataByte(Copy_pu8Data);
						I2C_MstrReadDataByteNoAck(Copy_pu8Data);
						if(Local_ErrorState==NoError){

							I2C_SendStopCondition();

							_delay_ms(20);
						}
						else{

						}
					}
					else{

					}
				}
				else{

				}
			}
			else{

			}
		}
		else{

		}
	}
	else{

	}
	return Local_ErrorState;
}

void  EEPROM_VoidSendAndReceiveBuffer(u16 Copy_u16address,u8 * Copy_u8Data,u8 size,u8 * Copy_u8RData){
	/*Data is sent by (Byte write) method not Page write, why ?
	 * Cuz, Pages layout are fixed i.e Page0 bytes are from byte 0 to byte 15, if user chooses
	 * Byte address 14 or chooses a Buffer larger than 16, the EEPROM will reach the
	 * end of this page then re-roll and overwrite the data written at the page beginning
	 *therefore, the data is written Byte by Byte*/


	for(u8 LocalIterator=1;LocalIterator<size;LocalIterator++){
		EEPROM_VoidSendDataByte(Copy_u16address+LocalIterator,Copy_u8Data[LocalIterator]);

	}

	/*Read data bytes one by one , Reading could be done sequentially by Acknowledging the read
	 * Data (By the MCU) and atomically reading the next byte of data
	 * without sending STOP condition, till last byte is reached, Acknowledging it then not
	 * Acknowledging the next data then sending Stop Condition. this process successfully
	 * stops the reading operation (If a data byte is not acknowledged by the MCU
	 * it is not recognized by MCU) therefore an extra reading is required if data is read
	 * sequentially */
	for(u8 LocalIterator=0;LocalIterator<size;LocalIterator++){
		EEPROM_VoidReadDataByte((Copy_u16address+LocalIterator),(Copy_u8RData+LocalIterator));
		}
}
