/*
*<<<<<<<<<<KPD_interface.h>>>>>>>>>>
*
*   Author  :  Ahmed Mahmoud
*   Layer   :  HAL
*   SWC     :  Keypad
*
*/

#ifndef _KPD_INTERFACE_H_
#define _KPD_INTERFACE_H_

#include "../../LIB/STD_TYPES.h"

#define NOTPRESSED 0xff

void KPD_voidInit     ( void );
u_8  KPD_u8GetPressed ( void );

#endif
