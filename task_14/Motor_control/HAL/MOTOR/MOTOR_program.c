/*
*<<<<<<<<<<MOTOR_program.c>>>>>>>>>>
*
*   Author  :  Ahmed Mahmoud
*   Layer   :  HAL
*   SWC     :  Motor
*
*/

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../../MCAL/DIO/DIO_interface.h"

#include "MOTOR_interface.h"

void MOTOR_voidInit          (MOTOR_Type MOTOR_Configuration)
{
    DIO_enumSetPinDirection(MOTOR_Configuration.port, MOTOR_Configuration.pin1, DIO_PIN_OUTPUT);
    DIO_enumSetPinDirection(MOTOR_Configuration.port, MOTOR_Configuration.pin2, DIO_PIN_OUTPUT);
}

void MOTOR_voidRotateCW      (MOTOR_Type MOTOR_Configuration)
{
    DIO_enumSetPinValue(MOTOR_Configuration.port, MOTOR_Configuration.pin1, DIO_PIN_HIGH);
    DIO_enumSetPinValue(MOTOR_Configuration.port, MOTOR_Configuration.pin2, DIO_PIN_LOW);
}

void MOTOR_voidRotateCCW     (MOTOR_Type MOTOR_Configuration)
{
    DIO_enumSetPinValue(MOTOR_Configuration.port, MOTOR_Configuration.pin2, DIO_PIN_HIGH);
    DIO_enumSetPinValue(MOTOR_Configuration.port, MOTOR_Configuration.pin1, DIO_PIN_LOW);
}

void MOTOR_voidStop          (MOTOR_Type MOTOR_Configuration)
{
    DIO_enumSetPinValue(MOTOR_Configuration.port, MOTOR_Configuration.pin1, DIO_PIN_LOW);
    DIO_enumSetPinValue(MOTOR_Configuration.port, MOTOR_Configuration.pin2, DIO_PIN_LOW);
}
