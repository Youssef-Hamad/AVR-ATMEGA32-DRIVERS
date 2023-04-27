/*
 * PWM_Config.h
 *
 *  Created on: Apr 8, 2023
 *      Author: Youssef
 */
#ifndef MCAL_PWM_PWM_CONFIG_H_
#define MCAL_PWM_PWM_CONFIG_H_






#define SYSTEM_FREQ_MHZ						8ULL
/*OPTIONS FOR TIMER PRESCALER (PWM & DELAY):
 * 1,8,64,256,1024
 *
 * */
#define PWM_TIMER1_PRESECALER_DIVISOR			64
#define PWM_TIMER1_PRESECALER_Select			TCCR1B_SOURCE_8_PRE



#endif