/*
*<<<<<<<<<<ADC_private.h>>>>>>>>>>
*
*   Author  :  Ahmed Mahmoud
*   Layer   :  MCAL
*   SWC     :  ADC
*
*/

#ifndef _ADC_PRIVATE_H_
#define _ADC_PRIVATE_H_

#define ADMUXR     *((v_u_8*) 0x27)
#define ADC_MUX0   0
#define ADC_MUX1   1
#define ADC_MUX2   2
#define ADC_MUX3   3
#define ADC_MUX4   4
#define ADC_LAR    5
#define ADC_REF0   6
#define ADC_REF1   7

#define ADCSAR     *((v_u_8*) 0x26)
#define ADC_PS0    0
#define ADC_PS1    1
#define ADC_PS2    2
#define ADC_IE     3
#define ADC_IF     4
#define ADC_ATE    5
#define ADC_SC     6
#define ADC_EN     7

#define ADC_HR     *((v_u_8*) 0x25)
#define ADC_LR     *((v_u_8*) 0x24)

#define SFIOR      *((v_u_8*) 0x50)
#define ADC_TS0    5
#define ADC_TS1    6
#define ADC_TS2    7

#endif
