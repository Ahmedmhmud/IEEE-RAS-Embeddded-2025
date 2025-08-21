/*
*<<<<<<<<<<SW_program.c>>>>>>>>>>
*
*   Author  :  Ahmed Mahmoud
*   Layer   :  HAL
*   SWC     :  Switch
*
*/

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../../MCAL/DIO/DIO_interface.h"

#include "SW_interface.h"

void SW_voidInit (SW_Type SW_Configuration)
{
    DIO_enumSetPinDirection(SW_Configuration.port, SW_Configuration.pin, DIO_PIN_INPUT);

    if (SW_Configuration.Pull_State == SW_INT_PULL_UP)
    {
        DIO_enumSetPinValue(SW_Configuration.port, SW_Configuration.pin, DIO_PIN_HIGH);
    }
}

u_8 SW_u8GetPressed (SW_Type SW_Configuration)
{
    u_8 PtrData, LOC_state = SW_NOT_PRESSED;
    DIO_enumGetPinValue (SW_Configuration.port, SW_Configuration.pin, &PtrData);

    if(SW_Configuration.Pull_State == SW_INT_PULL_UP || SW_Configuration.Pull_State == SW_EXT_PULL_UP)
    {
        if (PtrData == DIO_PIN_LOW)
        {
            LOC_state = SW_PRESSED;
        }
    }
    else if(SW_Configuration.Pull_State == SW_EXT_PULL_DOWN)
    {
        if (PtrData == DIO_PIN_HIGH)
        {
            LOC_state = SW_PRESSED;
        }
    }

    return LOC_state;
}
