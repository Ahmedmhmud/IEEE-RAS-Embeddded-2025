/*
*<<<<<<<<<<main.c>>>>>>>>>>
*
* Traffic Light with Multiplexed SSD Countdown
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
    // Initialize LEDs
    LED_Type ledRed = {LED_PORTA, LED_PIN0, ACTIVE_HIGH};
    LED_Type ledYellow = {LED_PORTA, LED_PIN1, ACTIVE_HIGH};
    LED_Type ledGreen = {LED_PORTA, LED_PIN2, ACTIVE_HIGH};

    LED_voidInit(ledRed);
    LED_voidInit(ledYellow);
    LED_voidInit(ledGreen);

    // Initialize Two SSDs for multiplexing
    SSD_Type ssdUnits = {SSD_COMMON_ANODE, SSD_PORTC, SSD_PORTD, SSD_PIN0}; // Units digit
    SSD_Type ssdTens  = {SSD_COMMON_ANODE, SSD_PORTC, SSD_PORTD, SSD_PIN1}; // Tens digit

    // Initialize both SSDs
    SSD_voidInitialDataPort(ssdUnits);  // Only need to init data port once (shared)

    while(1)
    {
        // RED on for 15 seconds (countdown 15->1)
        LED_voidOn(ledRed);
        LED_voidOff(ledYellow);
        LED_voidOff(ledGreen);

        SSD_voidCountdown(15, ssdUnits, ssdTens);

        // YELLOW on for 5 seconds (countdown 5->1)
        LED_voidOn(ledYellow);
        LED_voidOff(ledRed);
        LED_voidOff(ledGreen);

        SSD_voidCountdown(5, ssdUnits, ssdTens);

        // GREEN on for 10 seconds (countdown 10->1)
        LED_voidOn(ledGreen);
        LED_voidOff(ledRed);
        LED_voidOff(ledYellow);

        SSD_voidCountdown(10, ssdUnits, ssdTens);

        // YELLOW again for 5 seconds (countdown 5->1)
        LED_voidOn(ledYellow);
        LED_voidOff(ledRed);
        LED_voidOff(ledGreen);

        SSD_voidCountdown(5, ssdUnits, ssdTens);
    }
}
