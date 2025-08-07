/*
*<<<<<<<<<<DIO_interface.h>>>>>>>>>>
*
*   Author  :  Ahmed Mahmoud
*   Layer   :  MCAL
*   SWC     :  DIO/GPIO
*
*/

#ifndef _DIO_INTERFACE_H_
#define _DIO_INTERFACE_H_

#include "../../LIB/STD_TYPES.h"

typedef enum{
    DIO_NOK,
    DIO_OK
} DIO_ErrorStatus;

#define DIO_PIN_OUTPUT  1
#define DIO_PIN_INPUT   0

#define DIO_PORT_OUTPUT 0xFF
#define DIO_PORT_INPUT  0

#define DIO_PIN_HIGH    1
#define DIO_PIN_LOW     0

#define DIO_PORT_HIGH   0xFF
#define DIO_PORT_LOW    0

#define DIO_PORTA 0
#define DIO_PORTB 1
#define DIO_PORTC 2
#define DIO_PORTD 3

#define DIO_PIN0  0
#define DIO_PIN1  1
#define DIO_PIN2  2
#define DIO_PIN3  3
#define DIO_PIN4  4
#define DIO_PIN5  5
#define DIO_PIN6  6
#define DIO_PIN7  7

DIO_ErrorStatus DIO_enumSetPinDirection  (u_8 Copy_u8Port, u_8 Copy_u8Pin, u_8 Copy_u8Direction);
DIO_ErrorStatus DIO_enumSetPinValue      (u_8 Copy_u8Port, u_8 Copy_u8Pin, u_8 Copy_u8Value);
DIO_ErrorStatus DIO_enumGetPinValue      (u_8 Copy_u8Port, u_8 Copy_u8Pin, u_8 * Copy_PtrData);
DIO_ErrorStatus DIO_enumTogglePinValue   (u_8 Copy_u8Port, u_8 Copy_u8Pin);

DIO_ErrorStatus DIO_enumSetPortDirection (u_8 Copy_u8Port, u_8 Copy_u8Direction);
DIO_ErrorStatus DIO_enumSetPortValue     (u_8 Copy_u8Port, u_8 Copy_u8Value);
DIO_ErrorStatus DIO_enumGetPortValue     (u_8 Copy_u8Port, u_8 * Copy_PtrData);
DIO_ErrorStatus DIO_enumTogglePortValue  (u_8 Copy_u8Port);

DIO_ErrorStatus DIO_enumWritePort        (u_8 Copy_u8Port, u_8 Copy_u8Value);
DIO_ErrorStatus DIO_enumWriteLowNibbles  (u_8 Copy_u8Port, u_8 Copy_u8Value);
DIO_ErrorStatus DIO_enumWriteHighNibbles (u_8 Copy_u8Port, u_8 Copy_u8Value);

#endif
