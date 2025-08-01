/*
*<<<<<<<<<<LED_program.c>>>>>>>>>>
*
*   Author  :  Ahmed Mahmoud
*   Layer   :  HAL
*   SWC     :  LED
*
*/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"

#include "LED_interface.h"

void LED_voidInit(LED_Type LED_Configuration)
{
    DIO_enumSetPinDirection(LED_Configuration.port, LED_Configuration.pin, DIO_PIN_OUTPUT);
}

void LED_voidOn(LED_Type LED_Configuration)
{
    if(LED_Configuration.state == ACTIVE_HIGH)
    {
        DIO_enumSetPinValue(LED_Configuration.port, LED_Configuration.pin, DIO_PIN_HIGH);
    }
    else
    {
        DIO_enumSetPinValue(LED_Configuration.port, LED_Configuration.pin, DIO_PIN_LOW);
    }
}

void LED_voidOff(LED_Type LED_Configuration)
{
    if(LED_Configuration.state == ACTIVE_HIGH)
    {
        DIO_enumSetPinValue(LED_Configuration.port, LED_Configuration.pin, DIO_PIN_LOW);
    }
    else
    {
        DIO_enumSetPinValue(LED_Configuration.port, LED_Configuration.pin, DIO_PIN_HIGH);
    }
}

void LED_voidToggle(LED_Type LED_Configuration)
{
    DIO_enumTogglePinValue   (LED_Configuration.port, LED_Configuration.pin);
}
