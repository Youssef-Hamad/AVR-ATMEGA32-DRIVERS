/*
 * ADC_Interface.h
 *
 *  Created on: 4 Apr 2023
 *      Author: Youssef
 */

#ifndef MCAL_ADC_ADC_INTERFACE_H_
#define MCAL_ADC_ADC_INTERFACE_H_




#define SFIOR_FREE_RUN								0
#define SFIOR_ANALOG								1
#define SFIOR_EXTERNAL_INT							2
#define SFIOR_TIMER0_MATCH							3
#define SFIOR_TIMER0_OVERFLOW						4
#define SFIOR_TIMER1_MATCH							5
#define SFIOR_TIMER1_OVERFLOW						6
#define SFIOR_TIMER1_CAPTURE_EVENT					7


typedef void(*Cbf)(void);

/*Pre-Build Initialize ADC with (Voltage reference, 8~10 bit , Pres-caler Division,
  * Channel selection) Configurations
  */
void ADC_VoidInit(void);
/*Pre-Build Channel Reading ADC with Polling  (Asynchronous Reading) */
u16 ADC_u16GetchannelReading(void);

u8 ADC_u8StartConversionSync(u16 *Reading,const u8 Resolution_Mode,const s8 Channel);

u8 ADC_u8StartConversionAsync(u16 *Reading,const u8 Resolution_Mode,const s8 Channel,Cbf FuncPtr);

/*To be done */
u8 ADC_u8StartChainConversionAsync(void);
//void ADC_VoidSetCallBack(void(*FuncPtr)(void));
#endif /* MCAL_ADC_ADC_INTERFACE_H_ */
