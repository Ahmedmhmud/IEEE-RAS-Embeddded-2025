/*
*<<<<<<<<<<main.c>>>>>>>>>>
*
* Author : Ahmed Mahmoud
* Layer : APP
*
*/

#define F_CPU 8000000UL

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "LED_interface.h"
#include "SSD_interface.h"
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    LED_Type ledRed = {LED_PORTA, LED_PIN0, ACTIVE_HIGH};
    LED_Type ledYellow = {LED_PORTA, LED_PIN1, ACTIVE_HIGH};
    LED_Type ledGreen = {LED_PORTA, LED_PIN2, ACTIVE_HIGH};

    LED_voidInit(ledRed);
    LED_voidInit(ledYellow);
    LED_voidInit(ledGreen);

    SSD_Type ssdUnits = {SSD_COMMON_ANODE, SSD_PORTC, SSD_PORTD, SSD_PIN0};
    SSD_Type ssdTens  = {SSD_COMMON_ANODE, SSD_PORTC, SSD_PORTD, SSD_PIN1};

    SSD_voidInitialDataPort(ssdUnits);

    while(1)
    {
        LED_voidOn(ledRed);
        LED_voidOff(ledYellow);
        LED_voidOff(ledGreen);

        SSD_voidCountdown(15, ssdUnits, ssdTens);

        LED_voidOn(ledYellow);
        LED_voidOff(ledRed);
        LED_voidOff(ledGreen);

        SSD_voidCountdown(5, ssdUnits, ssdTens);

        LED_voidOn(ledGreen);
        LED_voidOff(ledRed);
        LED_voidOff(ledYellow);

        SSD_voidCountdown(10, ssdUnits, ssdTens);

        LED_voidOn(ledYellow);
        LED_voidOff(ledRed);
        LED_voidOff(ledGreen);

        SSD_voidCountdown(5, ssdUnits, ssdTens);
    }
}
