/*
*<<<<<<<<<<MOTOR_interface.h>>>>>>>>>>
*
*   Author  :  Ahmed Mahmoud
*   Layer   :  HAL
*   SWC     :  Motor
*
*/

#ifndef _MOTOR_INTERFACE_H_
#define _MOTOR_INTERFACE_H_

#define MOTOR_PORTA    0
#define MOTOR_PORTB    1
#define MOTOR_PORTC    2
#define MOTOR_PORTD    3

#define MOTOR_PIN0     0
#define MOTOR_PIN1     1
#define MOTOR_PIN2     2
#define MOTOR_PIN3     3
#define MOTOR_PIN4     4
#define MOTOR_PIN5     5
#define MOTOR_PIN6     6
#define MOTOR_PIN7     7

typedef struct{

    u_8 port    ;
    u_8 pin1    ;
    u_8 pin2    ;

}MOTOR_Type;

void MOTOR_voidInit          (MOTOR_Type MOTOR_Configuration);
void MOTOR_voidRotateCW      (MOTOR_Type MOTOR_Configuration);
void MOTOR_voidRotateCCW     (MOTOR_Type MOTOR_Configuration);
void MOTOR_voidStop          (MOTOR_Type MOTOR_Configuration);

#endif
