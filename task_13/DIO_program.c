/*
*<<<<<<<<<<DIO_interface.h>>>>>>>>>>
*
*   Author  :  Ahmed Mahmoud
*   Layer   :  MCAL
*   SWC     :  DIO/GPIO
*
*/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "DIO_private.h"
#include "DIO_config.h"

DIO_ErrorStatus DIO_enumSetPinDirection  (u_8 Copy_u8Port, u_8 Copy_u8Pin, u_8 Copy_u8Direction)
{
    DIO_ErrorStatus LOC_Status = DIO_OK;

    if(Copy_u8Port <= DIO_PORTD  && Copy_u8Pin <= DIO_PIN7)
        if      (Copy_u8Direction == DIO_PIN_OUTPUT)
        {
            switch(Copy_u8Port)
            {
                case DIO_PORTA: SET_BIT(DDRA, Copy_u8Pin); break;
                case DIO_PORTB: SET_BIT(DDRB, Copy_u8Pin); break;
                case DIO_PORTC: SET_BIT(DDRC, Copy_u8Pin); break;
                case DIO_PORTD: SET_BIT(DDRD, Copy_u8Pin); break;
            }
        }
        else if (Copy_u8Direction == DIO_PIN_INPUT)
        {
            switch(Copy_u8Port)
            {
                case DIO_PORTA: CLR_BIT(DDRA, Copy_u8Pin); break;
                case DIO_PORTB: CLR_BIT(DDRB, Copy_u8Pin); break;
                case DIO_PORTC: CLR_BIT(DDRC, Copy_u8Pin); break;
                case DIO_PORTD: CLR_BIT(DDRD, Copy_u8Pin); break;
            }
        }
        else
        {
            LOC_Status = DIO_NOK;
        }
    else
    {
        LOC_Status = DIO_NOK;
    }

    return LOC_Status;
}

DIO_ErrorStatus DIO_enumSetPinValue (u_8 Copy_u8Port, u_8 Copy_u8Pin, u_8 Copy_u8Value)
{
    DIO_ErrorStatus LOC_Status = DIO_OK;

    if(Copy_u8Port <= DIO_PORTD  && Copy_u8Pin <= DIO_PIN7)
        if      (Copy_u8Value == DIO_PIN_HIGH)
        {
            switch(Copy_u8Port)
            {
                case DIO_PORTA: SET_BIT(PORTA, Copy_u8Pin); break;
                case DIO_PORTB: SET_BIT(PORTB, Copy_u8Pin); break;
                case DIO_PORTC: SET_BIT(PORTC, Copy_u8Pin); break;
                case DIO_PORTD: SET_BIT(PORTD, Copy_u8Pin); break;
            }
        }
        else if (Copy_u8Value == DIO_PIN_LOW)
        {
            switch(Copy_u8Port)
            {
                case DIO_PORTA: CLR_BIT(PORTA, Copy_u8Pin); break;
                case DIO_PORTB: CLR_BIT(PORTB, Copy_u8Pin); break;
                case DIO_PORTC: CLR_BIT(PORTC, Copy_u8Pin); break;
                case DIO_PORTD: CLR_BIT(PORTD, Copy_u8Pin); break;
            }
        }
        else
        {
            LOC_Status = DIO_NOK;
        }
    else
    {
        LOC_Status = DIO_NOK;
    }

    return LOC_Status;
}

DIO_ErrorStatus DIO_enumGetPinValue (u_8 Copy_u8Port, u_8 Copy_u8Pin, u_8 * Copy_PtrData)
{
    DIO_ErrorStatus LOC_Status = DIO_OK;

    if(Copy_u8Port <= DIO_PORTD  && Copy_u8Pin <= DIO_PIN7)
    {
        switch(Copy_u8Port)
        {
            case DIO_PORTA: * Copy_PtrData = GET_BIT(PINA, Copy_u8Pin); break;
            case DIO_PORTB: * Copy_PtrData = GET_BIT(PINB, Copy_u8Pin); break;
            case DIO_PORTC: * Copy_PtrData = GET_BIT(PINC, Copy_u8Pin); break;
            case DIO_PORTD: * Copy_PtrData = GET_BIT(PIND, Copy_u8Pin); break;
        }
    }
    else
    {
        LOC_Status = DIO_NOK;
    }

    return LOC_Status;
}
DIO_ErrorStatus DIO_enumTogglePinValue   (u_8 Copy_u8Port, u_8 Copy_u8Pin                     )
{
    DIO_ErrorStatus LOC_Status = DIO_OK;

    if(Copy_u8Port <= DIO_PORTD && Copy_u8Pin <= DIO_PIN7)
    {
        switch(Copy_u8Port)
        {
            case DIO_PORTA: TOG_BIT(PORTA, Copy_u8Pin); break;
            case DIO_PORTB: TOG_BIT(PORTB, Copy_u8Pin); break;
            case DIO_PORTC: TOG_BIT(PORTC, Copy_u8Pin); break;
            case DIO_PORTD: TOG_BIT(PORTD, Copy_u8Pin); break;
        }
    }
    else
    {
        LOC_Status = DIO_NOK;
    }
    return LOC_Status;
}

DIO_ErrorStatus DIO_enumSetPortDirection(u_8 Copy_u8Port, u_8 Copy_u8Direction)
{
    DIO_ErrorStatus LOC_Status = DIO_OK;

    if (Copy_u8Port <= DIO_PORTD)
    {
        if (Copy_u8Direction == DIO_PORT_OUTPUT)
        {
            switch (Copy_u8Port)
            {
                case DIO_PORTA: SET_PORT(DDRA); break;
                case DIO_PORTB: SET_PORT(DDRB); break;
                case DIO_PORTC: SET_PORT(DDRC); break;
                case DIO_PORTD: SET_PORT(DDRD); break;
            }
        }
        else if (Copy_u8Direction == DIO_PORT_INPUT)
        {
            switch (Copy_u8Port)
            {
                case DIO_PORTA: CLR_PORT(DDRA); break;
                case DIO_PORTB: CLR_PORT(DDRB); break;
                case DIO_PORTC: CLR_PORT(DDRC); break;
                case DIO_PORTD: CLR_PORT(DDRD); break;
            }
        }
        else
        {
            LOC_Status = DIO_NOK;
        }
    }
    else
    {
        LOC_Status = DIO_NOK;
    }

    return LOC_Status;
}

DIO_ErrorStatus DIO_enumSetPortValue(u_8 Copy_u8Port, u_8 Copy_u8Value)
{
    DIO_ErrorStatus LOC_Status = DIO_OK;

    if (Copy_u8Port <= DIO_PORTD)
    {
        if (Copy_u8Value == DIO_PORT_HIGH)
        {
            switch (Copy_u8Port)
            {
                case DIO_PORTA: SET_PORT(PORTA); break;
                case DIO_PORTB: SET_PORT(PORTB); break;
                case DIO_PORTC: SET_PORT(PORTC); break;
                case DIO_PORTD: SET_PORT(PORTD); break;
            }
        }
        else if (Copy_u8Value == DIO_PORT_LOW)
        {
            switch (Copy_u8Port)
            {
                case DIO_PORTA: CLR_PORT(PORTA); break;
                case DIO_PORTB: CLR_PORT(PORTB); break;
                case DIO_PORTC: CLR_PORT(PORTC); break;
                case DIO_PORTD: CLR_PORT(PORTD); break;
            }
        }
        else
        {
        	switch (Copy_u8Port)
        	{
        	    case DIO_PORTA: PORTA = Copy_u8Value; break;
        	    case DIO_PORTB: PORTB = Copy_u8Value; break;
        	    case DIO_PORTC: PORTC = Copy_u8Value; break;
        	    case DIO_PORTD: PORTD = Copy_u8Value; break;
        	}
        }
    }
    else
    {
        LOC_Status = DIO_NOK;
    }

    return LOC_Status;
}

DIO_ErrorStatus DIO_enumGetPortValue(u_8 Copy_u8Port, u_8 *Copy_PtrData)
{
    DIO_ErrorStatus LOC_Status = DIO_OK;

    if (Copy_u8Port <= DIO_PORTD)
    {
        switch (Copy_u8Port)
        {
            case DIO_PORTA: *Copy_PtrData = PINA; break;
            case DIO_PORTB: *Copy_PtrData = PINB; break;
            case DIO_PORTC: *Copy_PtrData = PINC; break;
            case DIO_PORTD: *Copy_PtrData = PIND; break;
        }
    }
    else
    {
        LOC_Status = DIO_NOK;
    }

    return LOC_Status;
}

DIO_ErrorStatus DIO_enumTogglePortValue(u_8 Copy_u8Port)
{
    DIO_ErrorStatus LOC_Status = DIO_OK;

    if (Copy_u8Port <= DIO_PORTD)
    {
        switch (Copy_u8Port)
        {
            case DIO_PORTA: TOG_PORT(PORTA); break;
            case DIO_PORTB: TOG_PORT(PORTB); break;
            case DIO_PORTC: TOG_PORT(PORTC); break;
            case DIO_PORTD: TOG_PORT(PORTD); break;
        }
    }
    else
    {
        LOC_Status = DIO_NOK;
    }

    return LOC_Status;
}
