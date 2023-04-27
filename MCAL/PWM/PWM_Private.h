#ifndef MCAL_PWM_PWM_PRIVATE_H_
#define MCAL_PWM_PWM_PRIVATE_H_


/*Timer/Counter1 Control Register for Register A*/
#define TCCR1A 						*((volatile u8 *)0x4F)
#define TCCR1A_OutModeChannelA_BIT1			7
#define TCCR1A_OutModeChannelA_BIT0			6



#define TCCR1A_Match_MaskChannelA			0b00111111
/*TIMER1 CHANNELA PIN (OC1A,PORT D PIN5)*/
#define TIMER1_FAST_PWM_SetTopChannelA						(0b10<<6)
#define TIMER1_FAST_PWM_ClearTopChannelA					(0b11<<6)

#define TIMER1_CompareMatch_DisconnectOC1A					(0b00<<6)
#define TIMER1_CompareMatch_ToggleOC1A						(0b01<<6)
#define TIMER1_CompareMatch_ClearOC1A						(0b10<<6)
#define TIMER1_CompareMatch_SetOC1A							(0b11<<6)

#define TIMER1_PhaseCorrect_ClearUp_SetDownOC1A				(0b10<<6)
#define TIMER1_PhaseCorrect_SetUp_ClearDownOC1A				(0b11<<6)

#define TCCR1A_OutModeChannelB_BIT1			5
#define TCCR1A_OutModeChannelB_BIT0			4

#define TCCR1A_Match_MaskChannelB			0B11001111
/*TIMER1 CHANNELB PIN (OC1B,PORT D PIN4)*/
#define TIMER1_FAST_PWM_SetTopChannelB						(0B10<<4)
#define TIMER1_FAST_PWM_ClearTopChannelB					(0B11<<4)

#define TIMER1_CompareMatch_ToggleOC1B						(0b01<<4)
#define TIMER1_CompareMatch_ClearOC1B						(0b10<<4)
#define TIMER1_CompareMatch_SetOC1B							(0b11<<4)

#define TIMER1_PhaseCorrect_ClearUp_SetDownOC1B				(0b10<<4)
#define TIMER1_PhaseCorrect_SetUp_ClearDownOC1B				(0b11<<4)


#define TCCR1A_WaveFormModeBit0						0
#define TCCR1A_WaveFormModeBit1						1
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

/* ******************************** OCR1A ************************************** */
#define OCR1AH				 		*((volatile u8 *)0x4B)
#define OCR1AL						*((volatile u8 *)0x4A)
#define OCR1A_2BYTE					*((volatile u16 *)0x4A)

/* ******************************** TCNT1 ************************************** */
#define TCNT1H						*((volatile u8 *)0x4D)
#define TCNT1L						*((volatile u8 *)0x4C)
#define TCNT1_2BYTE					*((volatile u16 *)0x4C)

/* ******************************** ICR1 ************************************** */
#define ICR1H						*((volatile u8 *)0x47)
#define ICR1L						*((volatile u8 *)0x46)
#define ICR1_2BYTE					*((volatile u16 *)0x46)

/************************************OUTPUT MODES********************************/


#define MAX_16_BIT_VALUE			0XFFFF





#endif