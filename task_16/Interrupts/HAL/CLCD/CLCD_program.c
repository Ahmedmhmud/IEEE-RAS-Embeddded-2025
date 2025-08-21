/*
*<<<<<<<<<<CLCD_program.c>>>>>>>>>>
*
* Author : Ahmed Mahmoud
* Layer  : HAL
* SWC    : CLCD
*
*/


#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "CLCD_interface.h"
#include "CLCD_private.h"
#include "CLCD_config.h"
#include "CLCD_extrachar.h"
#include <util/delay.h>

#define CLCD_Data_Port     DIO_PORTA
#define CLCD_Control_Port  DIO_PORTC

#define CLCD_RS  DIO_PIN0
#define CLCD_RW  DIO_PIN1
#define CLCD_EN  DIO_PIN2

void CLCD_voidInit        ( void ){



	//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<      8 Bits Mode       >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

	#if   CLCD_MODE == 8

	_delay_ms(50);
	DIO_enumSetPortDirection ( CLCD_Data_Port    , DIO_PORT_OUTPUT           );
	DIO_enumSetPinDirection  ( CLCD_Control_Port , CLCD_RS , DIO_PIN_OUTPUT  );
	DIO_enumSetPinDirection  ( CLCD_Control_Port , CLCD_RW , DIO_PIN_OUTPUT  );
	DIO_enumSetPinDirection  ( CLCD_Control_Port , CLCD_EN , DIO_PIN_OUTPUT  );

	CLCD_voidSendCommand(LCD_Home);
	_delay_ms(1);

	CLCD_voidSendCommand( EIGHT_BITS ); // 8 Bit Mode ==> 0x38
	_delay_ms(1); // wait more than 39 Ms

	CLCD_voidSendCommand( LCD_DisplayOn_CursorOff );
	_delay_ms(1);

	CLCD_voidClearScreen();

	CLCD_voidSendCommand( LCD_EntryMode );
	_delay_ms(1);



	//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<      4 Bits Mode       >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

	#elif   CLCD_MODE == 4

	_delay_ms(50);
	DIO_enumSetPinDirection      (CLCD_DATA_PORT,DIO_PIN4,DIO_PIN_OUTPUT);
	DIO_enumSetPinDirection      (CLCD_DATA_PORT,DIO_PIN5,DIO_PIN_OUTPUT);
	DIO_enumSetPinDirection      (CLCD_DATA_PORT,DIO_PIN6,DIO_PIN_OUTPUT);
	DIO_enumSetPinDirection      (CLCD_DATA_PORT,DIO_PIN7,DIO_PIN_OUTPUT);
	DIO_enumSetPinDirection  ( CLCD_CONTROL_PORT , CLCD_RS , DIO_PIN_OUTPUT  );
	DIO_enumSetPinDirection  ( CLCD_CONTROL_PORT , CLCD_RW , DIO_PIN_OUTPUT  );
	DIO_enumSetPinDirection  ( CLCD_CONTROL_PORT , CLCD_EN , DIO_PIN_OUTPUT  );



	/*return home*/
	CLCD_voidSendCommand( lcd_Home );
	_delay_ms(30);

	/*FUNCTION SET Command*/
	CLCD_voidSendCommand( FOUR_BITS ); // 4 Bit Mode
	_delay_ms(1);

	/* DISPLAY & Cursor (ON / OFF) Control */
	CLCD_voidSendCommand( lcd_DisplayOn_CursorOff );
	_delay_ms(1);

	/* DISPLAY CLEAR */
	CLCD_voidClearScreen();

	/* ENTRY MODE  Set*/
	CLCD_voidSendCommand( lcd_EntryMode );
	_delay_ms(1);


	#endif




}

void CLCD_voidSendData    ( u_8 Copy_u8Data ){

	//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<      8 Bits Mode       >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
	#if   CLCD_MODE == 8
	DIO_enumSetPinValue  ( CLCD_Control_Port , CLCD_RS , DIO_PIN_HIGH );
	DIO_enumSetPinValue  ( CLCD_Control_Port , CLCD_RW , DIO_PIN_LOW  );
	DIO_enumSetPortValue ( CLCD_Data_Port    , Copy_u8Data        );

	CLCD_voidSendFallingEdge();



	//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<      4 Bits Mode       >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
	#elif   CLCD_MODE == 4

	DIO_enumSetPinValue  ( CLCD_CONTROL_PORT , CLCD_RS , DIO_PIN_HIGH );
	DIO_enumSetPinValue  ( CLCD_CONTROL_PORT , CLCD_RW , DIO_PIN_LOW  );
	DIO_voidWriteHighNibbles (CLCD_DATA_PORT ,(Copy_u8Data>>4));            // send the most 4 bits of data to high nibbles
	CLCD_voidSendFallingEdge();
	DIO_voidWriteHighNibbles (CLCD_DATA_PORT ,Copy_u8Data);               // send the least 4 bits of data to high nibbles
	CLCD_voidSendFallingEdge();

	#endif

	_delay_ms(1);

}

void CLCD_voidSendString  ( const u_8 * Copy_u8ptrString ){

	u_8 LOC_u8Iterator = 0 ;

	while( Copy_u8ptrString[LOC_u8Iterator] != '\0' ){

		CLCD_voidSendData( Copy_u8ptrString[LOC_u8Iterator] );
		LOC_u8Iterator++ ;

	}

}

void CLCD_voidSendCommand ( u_8 Copy_u8Command ){

	//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<      8 Bits Mode       >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
	#if   CLCD_MODE == 8

	DIO_enumSetPortValue ( CLCD_Data_Port    , Copy_u8Command     );
	DIO_enumSetPinValue  ( CLCD_Control_Port , CLCD_RS , DIO_PIN_LOW  );
	// RW always connect to GND to Write
	DIO_enumSetPinValue          (CLCD_Control_Port,CLCD_RW , DIO_PIN_LOW    );
	CLCD_voidSendFallingEdge();

	//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<      4 Bits Mode       >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
	#elif   CLCD_MODE == 4

	DIO_enumSetPinValue  ( CLCD_CONTROL_PORT , CLCD_RS , DIO_PIN_LOW  );
	DIO_enumSetPinValue  ( CLCD_CONTROL_PORT , CLCD_RW , DIO_PIN_LOW  );
	DIO_voidWriteHighNibbles (CLCD_DATA_PORT ,Copy_u8Command>>4);             // send the most 4 bits of data to high nibbles
	CLCD_voidSendFallingEdge();
	DIO_voidWriteHighNibbles (CLCD_DATA_PORT ,Copy_u8Command);                // send the least 4 bits of data to high nibbles
	CLCD_voidSendFallingEdge();

	#endif

	_delay_ms(1);

}

static void CLCD_voidSendFallingEdge(void)
{
    DIO_enumSetPinValue(CLCD_Control_Port, CLCD_EN, DIO_PIN_HIGH);
    _delay_ms(1);  // Use microseconds for enable pulse
    DIO_enumSetPinValue(CLCD_Control_Port, CLCD_EN, DIO_PIN_LOW);
    _delay_ms(2); // Wait for command to be processed
}

void CLCD_voidClearScreen(void)
{
	CLCD_voidSendCommand(LCD_Clear);
	_delay_ms(10);
}

void CLCD_voidSetPosition ( u_8 Copy_u8Row , u_8 Copy_u8Col ){

	u_8 LOC_u8data ;

	/* In These cases will set at (0,0) ==> if the user enter invalid location */
	if(Copy_u8Row>2||Copy_u8Row<1||Copy_u8Col>16||Copy_u8Col<1)  //check
	{
		LOC_u8data = LCD_SetCursor ;   // first location
	}

	else if( Copy_u8Row == CLCD_ROW_1 ){

		LOC_u8data = ( ( LCD_SetCursor ) + ( Copy_u8Col - 1 ) );              //Row1 -> 0x80+col-1

	}

	else if( Copy_u8Row == CLCD_ROW_2 ){

		LOC_u8data = ( ( LCD_SetCursor ) + (64) + ( Copy_u8Col - 1 ) );       //Row2 -> 0xc0+col-1

	}
	CLCD_voidSendCommand ( LOC_u8data );
	_delay_ms(1);

}

void CLCD_voidSendExtraChar( u_8 Copy_u8Row , u_8 Copy_u8Col ){

	u_8 LOC_u8Iterator = 0 ;
	/* 1- Go To CGRAM            */
	CLCD_voidSendCommand( LCD_CGRAM );  // Make AC refers to the first Place/Address at CGRAM


	/* 2- Draw Character in CGRAM        */
	/* Hint : it will be copied to DDRAM automatically */
	for( LOC_u8Iterator = 0 ; LOC_u8Iterator < sizeof(CLCD_u8ExtraChar) / sizeof(CLCD_u8ExtraChar[0]) ; LOC_u8Iterator++){

		CLCD_voidSendData( CLCD_u8ExtraChar[LOC_u8Iterator] );

	}


	/* 3- Back (AC) To DDRAM          */
	CLCD_voidSetPosition(Copy_u8Row,Copy_u8Col);


	/* 4- Send Character Address */
	for( LOC_u8Iterator = 0 ; LOC_u8Iterator < 8 ; LOC_u8Iterator++ ){

		CLCD_voidSendData( LOC_u8Iterator );

	}

}
