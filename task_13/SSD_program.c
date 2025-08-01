/*
*<<<<<<<<<<SSD_program.c>>>>>>>>>>
*
* Enhanced version with multiplexing support
* Author : Ahmed Mahmoud
* Layer : HAL
* SWC : SSD
*
*/

#define F_CPU 8000000UL

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "SSD_interface.h"
#include "SSD_private.h"
#include "SSD_config.h"
#include <util/delay.h>
#include <avr/io.h>

static u_8 Local_u8SSDNumbers[10] = SSD_NUMBER_ARR;

//====================================================================================================================================================
/*
* Brief : This Function initialize the port which connected to 7 Seg leds as output pins ( 8 Pins or Port )
* Parameters : Copy_structConfig --> SSD configuration struct
* return : void
*/
void SSD_voidInitialDataPort(SSD_Type Copy_structConfig)
{
    DIO_enumSetPortDirection(Copy_structConfig.DataPort, 0xFF);
}

//----------------------------------------------------------------------------------------------------------------------------------------------------
/*
* Brief : This Function write Number on 7 seg [ 0 : 9 ]
* Parameters : Copy_structConfig --> SSD configuration, Copy_u8Number --> digit to display
* return : void
*/
void SSD_voidSendNumber(SSD_Type Copy_structConfig, u_8 Copy_u8Number)
{
    if(Copy_structConfig.Type == SSD_COMMON_CATHODE) {
        DIO_enumSetPortValue(Copy_structConfig.DataPort, Local_u8SSDNumbers[Copy_u8Number]);
    }
    else if(Copy_structConfig.Type == SSD_COMMON_ANODE) {
        DIO_enumSetPortValue(Copy_structConfig.DataPort, Local_u8SSDNumbers[Copy_u8Number]);
    }
}

//----------------------------------------------------------------------------------------------------------------------------------------------------
/*
* Brief : Display a two-digit number using multiplexing
* Parameters : Copy_structConfigUnits --> Units SSD config
*             Copy_structConfigTens --> Tens SSD config
*             Copy_u8Number --> Number to display (0-99)
*             Copy_u16DisplayTime --> Total display time in ms
* return : void
*/
void SSD_voidDisplayTwoDigits(SSD_Type Copy_structConfigUnits, SSD_Type Copy_structConfigTens,
                             u_8 Copy_u8Number, u_16 Copy_u16DisplayTime)
{
    u_8 Local_u8Units = Copy_u8Number % 10;        // Extract units digit
    u_8 Local_u8Tens = Copy_u8Number / 10;         // Extract tens digit
    u_16 Local_u16Cycles = (Copy_u16DisplayTime * 2) / 5; // Reduce total cycles to speed up

    for(u_16 i = 0; i < Local_u16Cycles; i++)
    {
        // Display tens digit
        if(Local_u8Tens > 0) // Don't show leading zero
        {
            SSD_voidEnable(Copy_structConfigTens);
            SSD_voidDisable(Copy_structConfigUnits);
            SSD_voidSendNumber(Copy_structConfigTens, Local_u8Tens);
            _delay_ms(1);
        }
        else
        {
            // If no tens digit, still need to wait the same time for balance
            SSD_voidDisable(Copy_structConfigTens);
            _delay_ms(1);
        }

        // Display units digit
        SSD_voidEnable(Copy_structConfigUnits);
        SSD_voidDisable(Copy_structConfigTens);
        SSD_voidSendNumber(Copy_structConfigUnits, Local_u8Units);
        _delay_ms(1);
    }
}

//----------------------------------------------------------------------------------------------------------------------------------------------------
/*
* Brief : Enhanced countdown function with proper two-digit display
* Parameters : Copy_u8StartNumber --> Starting countdown number
*             Copy_structConfigUnits --> Units SSD config
*             Copy_structConfigTens --> Tens SSD config
* return : void
*/
void SSD_voidCountdown(u_8 Copy_u8StartNumber, SSD_Type Copy_structConfigUnits, SSD_Type Copy_structConfigTens)
{
    for(u_8 i = Copy_u8StartNumber; i > 0; i--)
    {
        SSD_voidDisplayTwoDigits(Copy_structConfigUnits, Copy_structConfigTens, i, 1000);
    }
}

//----------------------------------------------------------------------------------------------------------------------------------------------------
/*
* Brief : This Function enable common pin
* Parameters : Copy_structConfig --> SSD configuration
* return : void
*/
void SSD_voidEnable(SSD_Type Copy_structConfig)
{
    if(Copy_structConfig.Type == SSD_COMMON_CATHODE) {
        DIO_enumSetPinDirection(Copy_structConfig.EnablePort, Copy_structConfig.EnablePin, DIO_PIN_OUTPUT);
        DIO_enumSetPinValue(Copy_structConfig.EnablePort, Copy_structConfig.EnablePin, DIO_PIN_LOW);
    }
    else if(Copy_structConfig.Type == SSD_COMMON_ANODE) {
        DIO_enumSetPinDirection(Copy_structConfig.EnablePort, Copy_structConfig.EnablePin, DIO_PIN_OUTPUT);
        DIO_enumSetPinValue(Copy_structConfig.EnablePort, Copy_structConfig.EnablePin, DIO_PIN_HIGH);
    }
}

//----------------------------------------------------------------------------------------------------------------------------------------------------
/*
* Brief : This Function disable common pin
* Parameters : Copy_structConfig --> SSD configuration
* return : void
*/
void SSD_voidDisable(SSD_Type Copy_structConfig)
{
    if(Copy_structConfig.Type == SSD_COMMON_CATHODE) {
        DIO_enumSetPinDirection(Copy_structConfig.EnablePort, Copy_structConfig.EnablePin, DIO_PIN_OUTPUT);
        DIO_enumSetPinValue(Copy_structConfig.EnablePort, Copy_structConfig.EnablePin, DIO_PIN_HIGH);
    }
    else if(Copy_structConfig.Type == SSD_COMMON_ANODE) {
        DIO_enumSetPinDirection(Copy_structConfig.EnablePort, Copy_structConfig.EnablePin, DIO_PIN_OUTPUT);
        DIO_enumSetPinValue(Copy_structConfig.EnablePort, Copy_structConfig.EnablePin, DIO_PIN_LOW);
    }
}
