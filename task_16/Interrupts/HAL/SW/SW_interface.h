/*
*<<<<<<<<<<SW_interface.h>>>>>>>>>>
*
*   Author  :  Ahmed Mahmoud
*   Layer   :  HAL
*   SWC     :  Switch
*
*/

#ifndef _SW_INTERFACE_H_
#define _SW_INTERFACE_H_

#define SW_PORTA    0
#define SW_PORTB    1
#define SW_PORTC    2
#define SW_PORTD    3

#define SW_PIN0     0
#define SW_PIN1     1
#define SW_PIN2     2
#define SW_PIN3     3
#define SW_PIN4     4
#define SW_PIN5     5
#define SW_PIN6     6
#define SW_PIN7     7

#define SW_INT_PULL_UP    0
#define SW_EXT_PULL_UP    1
#define SW_EXT_PULL_DOWN  2
#define SW_FLOATING       3

#define SW_PRESSED        1
#define SW_NOT_PRESSED    0

typedef struct{

    u_8 port       ;
    u_8 pin        ;
    u_8 Pull_State ;

}SW_Type;

void SW_voidInit        (SW_Type SW_Configuration);
u_8  SW_u8GetPressed    (SW_Type SW_Configuration);
//  void LED_voidOff    (SW_Type SW_Configuration);
//  void LED_voidToggle (SW_Type SW_Configuration);

#endif
