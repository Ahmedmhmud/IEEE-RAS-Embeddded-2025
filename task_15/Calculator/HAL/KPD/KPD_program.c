/*
*<<<<<<<<<<KPD_program.c>>>>>>>>>>
*
*   Author  :  Ahmed Mahmoud
*   Layer   :  HAL
*   SWC     :  Keypad
*
*/

#define F_CPU 8000000UL

#include <util/delay.h>
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../../MCAL/DIO/DIO_interface.h"

#include "KPD_interface.h"
#include "KPD_config.h"

void KPD_voidInit     ( void )
{
    DIO_enumSetPinPullUp (KPD_Port, KPD_R0);
    DIO_enumSetPinPullUp (KPD_Port, KPD_R1);
    DIO_enumSetPinPullUp (KPD_Port, KPD_R2);
    DIO_enumSetPinPullUp (KPD_Port, KPD_R3);

    DIO_enumSetPinDirection (KPD_Port, KPD_C0, DIO_PIN_OUTPUT);
    DIO_enumSetPinDirection (KPD_Port, KPD_C1, DIO_PIN_OUTPUT);
    DIO_enumSetPinDirection (KPD_Port, KPD_C2, DIO_PIN_OUTPUT);
    DIO_enumSetPinDirection (KPD_Port, KPD_C3, DIO_PIN_OUTPUT);

    DIO_enumSetPinValue (KPD_Port, KPD_C0, DIO_PIN_HIGH);
    DIO_enumSetPinValue (KPD_Port, KPD_C1, DIO_PIN_HIGH);
    DIO_enumSetPinValue (KPD_Port, KPD_C2, DIO_PIN_HIGH);
    DIO_enumSetPinValue (KPD_Port, KPD_C3, DIO_PIN_HIGH);
}

u_8 KPD_u8GetPressed(void)
{
    u_8 LOC_u8ReturnData = NOTPRESSED;
    u_8 LOC_u8GetPressed;
    u_8 LOC_u8Row, LOC_u8Col;

    for (LOC_u8Col = KPD_COL_INIT; LOC_u8Col <= KPD_COL_END; LOC_u8Col++)
    {
        // Activate this column
        DIO_enumSetPinValue(KPD_Port, LOC_u8Col, DIO_PIN_LOW);

        for (LOC_u8Row = KPD_ROW_INIT; LOC_u8Row <= KPD_ROW_END; LOC_u8Row++)
        {
            DIO_enumGetPinValue(KPD_Port, LOC_u8Row, &LOC_u8GetPressed);

            if (LOC_u8GetPressed == DIO_PIN_LOW)   // Key pressed
            {
                _delay_ms(50); // debounce
                DIO_enumGetPinValue(KPD_Port, LOC_u8Row, &LOC_u8GetPressed);

                if (LOC_u8GetPressed == DIO_PIN_LOW)
                {
                    LOC_u8ReturnData = KPD_u8Buttons[LOC_u8Row - KPD_ROW_INIT][LOC_u8Col - KPD_COL_INIT];

                    // Wait until key is released
                    do {
                        DIO_enumGetPinValue(KPD_Port, LOC_u8Row, &LOC_u8GetPressed);
                    } while (LOC_u8GetPressed == DIO_PIN_LOW);

                    break; // Exit row loop
                }
            }
        }

        // Deactivate this column
        DIO_enumSetPinValue(KPD_Port, LOC_u8Col, DIO_PIN_HIGH);
    }

    return LOC_u8ReturnData;
}
