/*
*<<<<<<<<<<ADC_interface.h>>>>>>>>>>
*
*   Author  :  Ahmed Mahmoud
*   Layer   :  MCAL
*   SWC     :  ADC
*
*/

#ifndef _ADC_INTERFACE_H_
#define _ADC_INTERFACE_H_

#define ADC_ENABLE               0
#define ADC_DISABLE              1

#define INT_ENABLE               0
#define INT_DISABLE              1

#define AREF                     0
#define AVCC                     1
#define INTERNAL_2_56            2

#define RIGHT_ADJUSTMENT         0
#define LEFT_ADJUSTMENT          1

#define ADC0                     0
#define ADC1                     1
#define ADC2                     2
#define ADC3                     3
#define ADC4                     4
#define ADC5                     5
#define ADC6                     6
#define ADC7                     7

#define ADC_SINGLE_CONVERSION    0
#define ADC_FREE_RUNNING         1
#define ADC_ANALOG_COMPARATOR    2
#define ADC_EXTI0                3
#define ADC_TIM0_CTC             4
#define	ADC_TIM0_OVF             5
#define ADC_TIM1_CTC_CHANNEL_B   6
#define ADC_TIM1_OVF             7
#define	ADC_TIM1_ICU             8

#define ADC_PRE_2                0
#define ADC_PRE_4                1
#define ADC_PRE_8                2
#define ADC_PRE_16               3
#define ADC_PRE_32               4
#define ADC_PRE_64               5
#define ADC_PRE_128              6

#define SINGLE_CHANNEL_ASYNCH    1
#define CHAIN_CHANNEL_ASYNCH     0

#define IDLE                     1
#define BUSY                     0

#define NULL                     0

typedef struct 
{
	u_8*  Channel ;
	u_16* Result  ;
	u_8   Size    ;
	void (*NotificationFunc)(void);
}Chain_t ;

void ADC_voidEnable           (void);
void ADC_voidDisable          (void);
void ADC_voidInterruptEnable  (void);
void ADC_voidInterruptDisable (void);

void ADC_voidInit                ( void                                                                             );
u_8   ADC_u8GetResultSync        ( u_8 Copy_u8Channel , u_16* Copy_pu16Result                                       );
u_8   ADC_u8StartConversionAsynch( u_8 Copy_u8Channel , u_16* Copy_pu16Reading , void(*Copy_pvNotificationFunc)(void) );
u_8   ADC_u8StartChainAsynch     ( Chain_t * Copy_Chain                                                             );

#endif
