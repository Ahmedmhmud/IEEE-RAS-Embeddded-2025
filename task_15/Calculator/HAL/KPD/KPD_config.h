/*
*<<<<<<<<<<KPD_config.h>>>>>>>>>>
*
*   Author  :  Ahmed Mahmoud
*   Layer   :  HAL
*   SWC     :  Keypad
*
*/

#ifndef _KPD_CONFIG_H_
#define _KPD_CONFIG_H_

#include "../../LIB/STD_TYPES.h"

#define KPD_ROW_INIT  0
#define KPD_ROW_END   3

#define KPD_COL_INIT  4
#define KPD_COL_END   7

u_8 KPD_u8Buttons[4][4] = {
    {'7', '8', '9', '/'},
    {'4', '5', '6', '*'},
    {'1', '2', '3', '-'},
    {'C', '0', '=', '+'}
};

#define KPD_Port 3

#define KPD_R0   0
#define KPD_R1   1
#define KPD_R2   2
#define KPD_R3   3

#define KPD_C0   4
#define KPD_C1   5
#define KPD_C2   6
#define KPD_C3   7

#endif
