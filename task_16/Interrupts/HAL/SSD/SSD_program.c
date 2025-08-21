/*
*<<<<<<<<<<SSD_program.c>>>>>>>>>>
*
* Author : Ahmed Mahmoud
* Layer : HAL
* SWC : SSD
*
*/

#define F_CPU 8000000UL

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "SSD_interface.h"
#include "SSD_private.h"
#include "SSD_config.h"
#include <util/delay.h>
#include <avr/io.h>

static u_8 Local_u8SSDNumbers[10] = SSD_NUMBER_ARR;

void SSD_voidInitialDataPort(SSD_Type Copy_structConfig)
{
    DIO_enumSetPortDirection(Copy_structConfig.DataPort, 0xFF);
}

void SSD_voidSendNumber(SSD_Type Copy_structConfig, u_8 Copy_u8Number)
{
    if(Copy_structConfig.Type == SSD_COMMON_CATHODE) {
        DIO_enumSetPortValue(Copy_structConfig.DataPort, Local_u8SSDNumbers[Copy_u8Number]);
    }
    else if(Copy_structConfig.Type == SSD_COMMON_ANODE) {
        DIO_enumSetPortValue(Copy_structConfig.DataPort, Local_u8SSDNumbers[Copy_u8Number]);
    }
}

void SSD_voidDisplayTwoDigits(SSD_Type Copy_structConfigUnits, SSD_Type Copy_structConfigTens,
                             u_8 Copy_u8Number, u_16 Copy_u16DisplayTime)
{
    u_8 Local_u8Units = Copy_u8Number % 10;
    u_8 Local_u8Tens = Copy_u8Number / 10;
    u_16 Local_u16Cycles = (Copy_u16DisplayTime * 2) / 5;

    for(u_16 i = 0; i < Local_u16Cycles; i++)
    {
        if(Local_u8Tens > 0)
        {
            SSD_voidEnable(Copy_structConfigTens);
            SSD_voidDisable(Copy_structConfigUnits);
            SSD_voidSendNumber(Copy_structConfigTens, Local_u8Tens);
            _delay_ms(1);
        }
        else
        {
            SSD_voidDisable(Copy_structConfigTens);
            _delay_ms(1);
        }

        SSD_voidEnable(Copy_structConfigUnits);
        SSD_voidDisable(Copy_structConfigTens);
        SSD_voidSendNumber(Copy_structConfigUnits, Local_u8Units);
        _delay_ms(1);
    }
}

void SSD_voidCountdown(u_8 Copy_u8StartNumber, SSD_Type Copy_structConfigUnits, SSD_Type Copy_structConfigTens)
{
    for(u_8 i = Copy_u8StartNumber; i > 0; i--)
    {
        SSD_voidDisplayTwoDigits(Copy_structConfigUnits, Copy_structConfigTens, i, 1000);
    }
}

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
