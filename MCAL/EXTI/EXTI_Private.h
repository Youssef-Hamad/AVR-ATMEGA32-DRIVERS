/*
 * EXTI_Private.h
 *
 *  Created on: 2 Apr 2023
 *      Author: Youssef
 */

#ifndef MCAL_EXTI_EXTI_PRIVATE_H_
#define MCAL_EXTI_EXTI_PRIVATE_H_



#define MCUCR	 	*((volatile u8*) 0x55)						//MCU Control Register
#define MCUCSR 		*((volatile u8*) 0x54)						//MCU Control and Status Register
#define GICR 		*((volatile u8*) 0x5B)                  	//General Interrupt Control Register
#define GIFR 		*((volatile u8*) 0x5A)				 	    //General Interrupt Flag Register


#define WDTCR		*((volatile u8*) 0x41)						//Watchdog Timer Control Register
#define WDTCR_WDTOE				4								//Watchdog Turn-off Enable
#define WDTCR_WDE				3								//Watchdog Enable
#define WDTCR_WDP2				2								//Watchdog Timer Prescaler Bit 2
#define WDTCR_WDP1				1								//Watchdog Timer Prescaler Bit 2
#define WDTCR_WDP0				0								//Watchdog Timer Prescaler Bit 2
#define WDTCR_PRESCALER_MASK	0b11000							//Watchdog Timer Prescaler MASK


#define INT1_SENSEBIT0			2
#define INT1_SENSEBIT1			3
#define INT1_CONTROLBIT			7

#define INT0_SENSEBIT0			0
#define INT0_SENSEBIT1			1
#define INT0_CONTROLBIT			6

#define INT2_SENSEBIT0			6
#define INT2_CONTROLBIT			5



#endif /* MCAL_EXTI_EXTI_PRIVATE_H_ */
