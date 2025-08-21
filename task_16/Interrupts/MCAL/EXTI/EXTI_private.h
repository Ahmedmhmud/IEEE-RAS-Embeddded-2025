/*
*<<<<<<<<<<EXTI_private.h>>>>>>>>>>
*
*   Author  :  Ahmed Mahmoud
*   Layer   :  MCAL
*   SWC     :  EXTI
*
*/

#ifndef _EXTI_PRIVATE_H_
#define _EXTI_PRIVATE_H_

#include "../../LIB/STD_TYPES.h"

#define GICR      *((v_u_8*) 0x5B)
#define GIFR      *((v_u_8*) 0x5A)
#define MCUCR     *((v_u_8*) 0x55)
#define MCUCSR    *((v_u_8*) 0x54)
#define SREG_REG  *((v_u_8*) 0x5F)

#endif
