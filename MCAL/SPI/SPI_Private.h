/*
 * SPI_Private.h
 *
 *  Created on: Apr 11, 2023
 *      Author: Youssef
 */

#ifndef MCAL_SPI_SPI_PRIVATE_H_
#define MCAL_SPI_SPI_PRIVATE_H_



#define SPDR              *((volatile u8*)0x2F)     /*SPI Data Register*/

#define SPSR              *((volatile u8*)0x2E)     /*SPI Status Register*/

#define SPSR_SPIF         7                         /*SPI Interrupt Flag*/
#define SPSR_WCOL         6                         /*Write COLlision flag*/
#define SPSR_SPI2X        0                         /*Prescaler bit 2*/

#define SPCR              *((volatile u8*)0x2D)     /*SPI Control Register*/
#define SPCR_SPIE         7                         /*SPI interrupt enable*/
#define SPCR_SPE          6                         /*SPI Enable*/
#define SPCR_DORD         5                         /*Data order*/
#define SPCR_MSTR         4                         /*Master/slave Bit*/
#define SPCR_CPOL         3                         /*Clock polarity*/
#define SPCR_CPHA         2                         /*Clock phase*/
#define SPCR_CR1          1                         /*Clock Bit1*/
#define SPCR_CR0          0                          /*Clock Bit0*/




#endif /* MCAL_SPI_SPI_PRIVATE_H_ */
