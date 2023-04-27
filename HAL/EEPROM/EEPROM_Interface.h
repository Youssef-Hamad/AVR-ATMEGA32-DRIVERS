/*
 * EEPROM_Interface.h
 *
 *  Created on: Apr 24, 2023
 *      Author: DWEEBSTARK
 */

#ifndef HAL_EEPROM_EEPROM_INTERFACE_H_
#define HAL_EEPROM_EEPROM_INTERFACE_H_

u8  EEPROM_VoidSendDataByte(u16 Copy_u16address,u8 Copy_u8Data);
u8  EEPROM_VoidReadDataByte(u16 Copy_u16address,u8* Copy_pu8Data);




void  EEPROM_VoidSendAndReceiveBuffer(u16 Copy_u16address,u8 * Copy_u8Data,u8 size,u8 * Copy_u8RData);
#endif /* HAL_EEPROM_EEPROM_INTERFACE_H_ */
