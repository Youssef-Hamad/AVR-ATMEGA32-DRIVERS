#ifndef MCAL_ICU_ICU_INTERFACE_H_
#define MCAL_ICU_ICU_INTERFACE_H_





#define CHANNEL_A					1
#define CHANNEL_B					2

#define ICU_RISE_TRIGGER            1
#define ICU_FALL_TRIGGER            0






void ICU_SetEdgeTrigger(u8 Copy_u8Edege);
void ICU_VoidEnableICU(u8 Copy_u8Edege);
void ICU_VoidDisableICU(void);
u16 ICU_VoidReadICR(void);
void ICU_VoidSetCallBack(void (*UserFunction)(void));
#endif