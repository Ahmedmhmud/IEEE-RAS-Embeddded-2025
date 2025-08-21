/*
*<<<<<<<<<<EXTI_program.c>>>>>>>>>>
*
* Author : Ahmed Mahmoud
* Layer : MCAL
* SWC : EXTI
*
*/

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"

void (*EXTI_CallBack[3]) (void) = { NULL };

void EXTI_voidInit (void)
{
#ifdef EXTI_LINE

#if EXTI_LINE == EXTI_LINE0

#if EXTI_SENSE_MODE == EXTI_FALLING_EDGE
    SET_BIT(MCUCR, 1); CLR_BIT(MCUCR, 0);

#elif EXTI_SENSE_MODE == EXTI_RISING_EDGE
    SET_BIT(MCUCR, 1); SET_BIT(MCUCR, 0);

#elif EXTI_SENSE_MODE == EXTI_LOW_LEVEL
    CLR_BIT(MCUCR, 1); CLR_BIT(MCUCR, 0);

#elif EXTI_SENSE_MODE == EXTI_ON_CHANGE
    CLR_BIT(MCUCR, 1); SET_BIT(MCUCR, 0);

#endif

#elif EXTI_LINE == EXTI_LINE1

#if EXTI_SENSE_MODE == EXTI_FALLING_EDGE
    SET_BIT(MCUCR, 3); CLR_BIT(MCUCR, 2);

#elif EXTI_SENSE_MODE == EXTI_RISING_EDGE
    SET_BIT(MCUCR, 3); SET_BIT(MCUCR, 2);

#elif EXTI_SENSE_MODE == EXTI_LOW_LEVEL
    CLR_BIT(MCUCR, 3); CLR_BIT(MCUCR, 2);

#elif EXTI_SENSE_MODE == EXTI_ON_CHANGE
    CLR_BIT(MCUCR, 3); SET_BIT(MCUCR, 2);

#endif

#elif EXTI_LINE == EXTI_LINE2

#if EXTI_SENSE_MODE == EXTI_FALLING_EDGE
    CLR_BIT(MCUCSR, 6);

#elif EXTI_SENSE_MODE == EXTI_RISING_EDGE
    SET_BIT(MCUCSR, 6);

#endif

#else
#error "Wrong EXTI_LINE configuration option"

#endif

#endif
}

void EXTI_voidSetSignalLatch ( u_8 Copy_u8SenseMode , u_8 Copy_u8Line ){

    if( Copy_u8Line == EXTI_LINE0 || Copy_u8Line == EXTI_LINE1 ){

        u_8 bit_position;
        if(Copy_u8Line == EXTI_LINE0) {
            bit_position = 0;  // ISC00, ISC01
        } else {  // EXTI_LINE1
            bit_position = 2;  // ISC10, ISC11
        }

        switch( Copy_u8SenseMode ){
            case EXTI_LOW_LEVEL :
                CLR_BIT( MCUCR , bit_position );
                CLR_BIT( MCUCR , bit_position + 1 );
                break;
            case EXTI_ON_CHANGE :
                SET_BIT( MCUCR , bit_position );
                CLR_BIT( MCUCR , bit_position + 1 );
                break;
            case EXTI_FALLING_EDGE :
                CLR_BIT( MCUCR , bit_position );
                SET_BIT( MCUCR , bit_position + 1 );
                break;
            case EXTI_RISING_EDGE :
                SET_BIT( MCUCR , bit_position );
                SET_BIT( MCUCR , bit_position + 1 );
                break;
        }
    }
    else if(Copy_u8Line == EXTI_LINE2){
        switch( Copy_u8SenseMode ){
            case EXTI_FALLING_EDGE : CLR_BIT( MCUCSR , 6 ); break;
            case EXTI_RISING_EDGE : SET_BIT( MCUCSR , 6 ); break;
        }
    }
}

void EXTI_voidDisableInterrupt ( u_8 Copy_u8Line ){

    u_8 gicr_bit;
    switch(Copy_u8Line) {
        case EXTI_LINE0: gicr_bit = 6; break;  // INT0 bit in GICR
        case EXTI_LINE1: gicr_bit = 7; break;  // INT1 bit in GICR
        case EXTI_LINE2: gicr_bit = 5; break;  // INT2 bit in GICR
        default: return;
    }

    CLR_BIT( GICR , gicr_bit );
}

void EXTI_voidEnableInterrupt ( u_8 Copy_u8Line ){

    u_8 gicr_bit;
    switch(Copy_u8Line) {
        case EXTI_LINE0: gicr_bit = 6; break;  // INT0 bit in GICR
        case EXTI_LINE1: gicr_bit = 7; break;  // INT1 bit in GICR
        case EXTI_LINE2: gicr_bit = 5; break;  // INT2 bit in GICR
        default: return;
    }

    SET_BIT( GICR , gicr_bit );
}

void EXTI_voidClearFlag ( u_8 Copy_u8Line ){

    u_8 gifr_bit;
    switch(Copy_u8Line) {
        case EXTI_LINE0: gifr_bit = 6; break;  // INTF0 bit in GIFR
        case EXTI_LINE1: gifr_bit = 7; break;  // INTF1 bit in GIFR
        case EXTI_LINE2: gifr_bit = 5; break;  // INTF2 bit in GIFR
        default: return;
    }

    SET_BIT( GIFR , gifr_bit );
}

u_8 EXTI_u8GetFlag( u_8 Copy_u8Line ){

    u_8 gifr_bit;
    switch(Copy_u8Line) {
        case EXTI_LINE0: gifr_bit = 6; break;  // INTF0 bit in GIFR
        case EXTI_LINE1: gifr_bit = 7; break;  // INTF1 bit in GIFR
        case EXTI_LINE2: gifr_bit = 5; break;  // INTF2 bit in GIFR
        default: return 0;
    }

    return GET_BIT( GIFR , gifr_bit );
}

void EXTI_voidSetCallBack(void (*Copy_pvoidCallBack)(void) , u_8 Copy_u8EXTILine)
{
    if(Copy_pvoidCallBack != NULL && Copy_u8EXTILine <= 2)
    {
        EXTI_CallBack[Copy_u8EXTILine] = Copy_pvoidCallBack;
    }
}

void __vector_1(void) __attribute__((signal));
void __vector_1(void)
{
    if(EXTI_CallBack[0] != NULL)
    {
        EXTI_CallBack[0] ();
        EXTI_voidClearFlag(EXTI_LINE0);
    }
}

void __vector_2(void) __attribute__((signal));
void __vector_2(void)
{
    if(EXTI_CallBack[1] != NULL)
    {
        EXTI_CallBack[1] ();
        EXTI_voidClearFlag(EXTI_LINE1);
    }
}

void __vector_3(void) __attribute__((signal));
void __vector_3(void)
{
    if(EXTI_CallBack[2] != NULL)
    {
        EXTI_CallBack[2] ();
        EXTI_voidClearFlag(EXTI_LINE2);
    }
}

void GIE_voidEnable(void)
{
    SET_BIT(SREG_REG, 7);
}

void GIE_voidDisable(void)
{
    CLR_BIT(SREG_REG, 7);
}
