/*
 * GPT_Private.h
 *
 *  Created on: Apr 13, 2023
 *      Author: Youssef
 */

#ifndef MCAL_ICU_ICU_PRIVATE_H_
#define MCAL_ICU_ICU_PRIVATE_H_



/* ******************************** TIMSK ************************************** */
/*  Timer/Counter Interrupt Mask Register */
#define TIMSK						*((volatile u8 *)0x59)
/*Timer/Counter0 Overflow Interrupt Enable*/
#define TIMSK_TOIE0_BIT						0
/*Timer/Counter0 Compare Match Interrupt Enable*/
#define TIMSK_OCIE0_BIT						1


/*Timer/Counter1 Overflow Interrupt Enable*/
#define TIMSK_TOIE1_BIT						2
/*Timer/Counter1 Compare Match Interrupt Enable CHANNEL B*/
#define TIMSK_OCIE1B_BIT					3
/*Timer/Counter1 Compare Match Interrupt Enable CHANNEL A*/
#define TIMSK_OCIE1A_BIT					4
/*Timer/Counter1 Input Capture Interrupt Enable*/
#define TIMSK_TICIE_BIT						5

/* ******************************** TCCR1B ************************************** */
#define TCCR1B 						*((volatile u8 *)0x4E)


#define TCCR1B_ClockSelect_BIT2				2
#define TCCR1B_ClockSelect_BIT1				1
#define TCCR1B_ClockSelect_BIT0				0

#define TCCR1B_ClockSelectMask				0b11111000
#define TCCR1B_SOURCE_NOSOURCE				0
#define TCCR1B_SOURCE_1_PRE					1
#define TCCR1B_SOURCE_8_PRE					2
#define TCCR1B_SOURCE_64_PRE				3
#define TCCR1B_SOURCE_256_PRE				4
#define TCCR1B_SOURCE_1024_PRE				5
#define TCCR1B_SOURCE_EXT_FALL				6
#define TCCR1B_SOURCE_EXT_RISE				7

#define TCCR1B_WaveFormModeBit0				3
#define TCCR1B_WaveFormModeBit1				4

#define TCCR1B_ICNC1                        7   //INPUT CAPTURE NOISE CANCELER
#define TCCR1B_ICES1                        6   //INPUT CAPTURE EDGE SELECT

/* ******************************** ICR1 ************************************** */
#define ICR1H						*((volatile u8 *)0x47)
#define ICR1L						*((volatile u8 *)0x46)
#define ICR1_2BYTE					*((volatile u16 *)0x46)


#endif