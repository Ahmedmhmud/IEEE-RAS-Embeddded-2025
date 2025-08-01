/*
*<<<<<<<<<<LED_interface.h>>>>>>>>>>
*
*   Author  :  Ahmed Mahmoud
*   Layer   :  HAL
*   SWC     :  LED
*
*/

#ifndef _LED_INTERFACE_H_
#define _LED_INTERFACE_H_

#define LED_PORTA    0
#define LED_PORTB    1
#define LED_PORTC    2
#define LED_PORTD    3

#define LED_PIN0     0
#define LED_PIN1     1
#define LED_PIN2     2
#define LED_PIN3     3
#define LED_PIN4     4
#define LED_PIN5     5
#define LED_PIN6     6
#define LED_PIN7     7

#define ACTIVE_LOW   0
#define ACTIVE_HIGH  1

typedef struct{

    u_8 port  ;
    u_8 pin   ;
    u_8 state ;

}LED_Type;

void LED_voidInit   (LED_Type LED_Configuration);
void LED_voidOn     (LED_Type LED_Configuration);
void LED_voidOff    (LED_Type LED_Configuration);
void LED_voidToggle (LED_Type LED_Configuration);

#endif
