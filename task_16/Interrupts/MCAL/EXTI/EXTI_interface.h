/*
*<<<<<<<<<<EXTI_interface.h>>>>>>>>>>
*
* Author : Ahmed Mahmoud
* Layer : MCAL
* SWC : EXTI
*
*/

#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

// Changed to match array indices
#define EXTI_LINE0  0
#define EXTI_LINE1  1
#define EXTI_LINE2  2

#define EXTI_FALLING_EDGE  0
#define EXTI_RISING_EDGE   1
#define EXTI_LOW_LEVEL     2
#define EXTI_ON_CHANGE     3

#define NULL 0

void EXTI_voidInit ( void );
void EXTI_voidSetSignalLatch ( u_8 Copy_u8SenseMode , u_8 Copy_u8Line );
void EXTI_voidDisableInterrupt ( u_8 Copy_u8Line );
void EXTI_voidEnableInterrupt ( u_8 Copy_u8Line );
void EXTI_voidClearFlag ( u_8 Copy_u8Line );
void EXTI_voidSetCallBack ( void (*Copy_pvoidCallBack)(void) , u_8 Copy_u8EXTILine );
void GIE_voidEnable ( void );
void GIE_voidDisable ( void );

#endif
