/*
 * EXTI_Config.h
 *
 *  Created on: 2 Apr 2023
 *      Author: Youssef
 */

#ifndef MCAL_EXTI_EXTI_CONFIG_H_
#define MCAL_EXTI_EXTI_CONFIG_H_



//Please choose EXTI_SenseLow,EXTI_SenseAny,EXTI_SenseFall,EXTI_SenseRise for Interrupt sense
#define EXTI_SenseControlInt0	EXTI_SenseFall
#define EXTI_SenseControlInt1	EXTI_SenseFall
#define EXTI_SenseControlInt2 	EXTI_SenseFall

//Please Choose EXTI_INT0,EXTI_INT1,EXTI_INT2 For InterruptID
#define EXTI_Intrreupt   EXTI_INT0


#endif /* MCAL_EXTI_EXTI_CONFIG_H_ */
