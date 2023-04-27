/*
 * EXTI_Interface.h
 *
 *  Created on: 2 Apr 2023
 *      Author: Youssef
 */

#ifndef MCAL_EXTI_EXTI_INTERFACE_H_
#define MCAL_EXTI_EXTI_INTERFACE_H_



#define EXTI_SenseLow	    0x0
#define EXTI_SenseAny		0x1
#define EXTI_SenseFall		0x2
#define EXTI_SenseRise		0x3

#define INT_0				1
#define INT_1				2
#define INT_2				3

#define WATCHDOG_16_3m_SECs				0
#define WATCHDOG_32_5m_SECs				1
#define WATCHDOG_65_SECs				2
#define WATCHDOG_0_13_CSECs				3
#define WATCHDOG_0_26_CSECs				4
#define WATCHDOG_0_52_CSECs				5
#define WATCHDOG_1_SECs					6
#define WATCHDOG_2_1_SECs				7




void EXTI_VoidInitInterrupt0(void);			//Initialize Interrupt0 Pre-build
void EXTI_VoidInitInterrupt1(void);			//Initialize Interrupt1 Pre-build
void EXTI_VoidInitInterrupt2(void);			//Initialize Interrupt2 Pre-build

//Initialize Specific Interrupt (Runtime build)
void EXTI_voidInitInterrupt(u8 u8CopyInturruptID,u8 u8CopySenseControl);



//Disable Interrupt (Run-time)
void EXIT_VoidDisableInterrupt(u8 u8CopyInterrupt);


//Call back functions
u8 EXTI_VoidSetcallback0(void(*ptr)(void));
u8 EXTI_voidSetcallback1(void(*ptr)(void));
u8 EXTI_voidSetcallback2(void(*ptr)(void));


/*Watch Dog Enable */
void WatchDog_VoidEnable(void);
/*Start Watch Dog*/
void WatchDog_VoidStart(u8 Copy_Prescaler);
/*Watch Dog Disable */
void WatchDog_VoidDisable(void);
#endif /* MCAL_EXTI_EXTI_INTERFACE_H_ */
