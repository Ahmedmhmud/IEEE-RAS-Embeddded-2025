/*
* <<<<<<<<<<<<<<<main.c>>>>>>>>>>>>>>>>>>
*
* Created on: ٢٨‏/٠٨‏/٢٠٢٥
* Author: Ahmed Mahmoud
*/

#include "../HAL/LED/LED_interface.h"
#include "../HAL/CLCD/CLCD_interface.h"
#include "../LIB/BIT_MATH.h"
#include "../LIB/STD_TYPES.h"
#include "../MCAL/ADC/ADC_interface.h"
#include "stdlib.h"
#include "stdio.h"
#include <util/delay.h>

LED_Type leds[8] = {
    { LED_PORTD, LED_PIN0, ACTIVE_HIGH },
    { LED_PORTD, LED_PIN1, ACTIVE_HIGH },
    { LED_PORTD, LED_PIN2, ACTIVE_HIGH },
    { LED_PORTD, LED_PIN3, ACTIVE_HIGH },
    { LED_PORTD, LED_PIN4, ACTIVE_HIGH },
    { LED_PORTD, LED_PIN5, ACTIVE_HIGH },
    { LED_PORTD, LED_PIN6, ACTIVE_HIGH },
    { LED_PORTD, LED_PIN7, ACTIVE_HIGH }
};

int main(void)
{
    CLCD_voidInit();
    _delay_ms(100);
    for(u_8 i = 0; i < 8; i++){
        LED_voidInit(leds[i]);
    }
    ADC_voidInit();
    u_16 result;
    u_8 str[] = "Percentage = ";

    while(1)
    {
        for(u_8 i = 0; i < 8; i++){
            LED_voidOff(leds[i]);
        }
        CLCD_voidSetPosition(CLCD_ROW_1, CLCD_COL_1);
        CLCD_voidSendString(str);
        ADC_u8GetResultSync(ADC0, &result);
        u_8 percentage = (u_8)(100 * (result/1023.0));

        if(percentage >= 100) {
            CLCD_voidSendData('1');
            CLCD_voidSendData('0');
            CLCD_voidSendData('0');
        } else if(percentage >= 10) {
            CLCD_voidSendData('0' + (percentage / 10));
            CLCD_voidSendData('0' + (percentage % 10));
        } else {
            CLCD_voidSendData('0' + percentage);
        }
        CLCD_voidSendData('%');

        u_8 no_of_leds = (percentage * 8) / 100;
        if(no_of_leds > 8) no_of_leds = 8;
        for(u_8 i = 0; i < no_of_leds; i++){
            LED_voidOn(leds[i]);
        }
        _delay_ms(3000);
    }
}
