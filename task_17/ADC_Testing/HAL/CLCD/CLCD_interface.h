/*
*<<<<<<<<<<CLCD_interface.h>>>>>>>>>>
*
*   Author  :  Ahmed Mahmoud
*   Layer   :  HAL
*   SWC     :  CLCD
*
*/

#ifndef CLCD_INTERFACE_H_
#define CLCD_INTERFACE_H_

#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/DIO/DIO_interface.h"


#define EIGHT_BITS   0x38
#define FOUR_BITS    0X28

// Command Defines
#define LCD_DisplayOn_CursorOff    0x0c
#define LCD_DisplayOn_CursorOn     0x0e
#define LCD_DisplayOff_CursorOff   0x08
#define LCD_Clear                  0x01
#define LCD_EntryMode              0x06
#define LCD_Home                   0x02
#define LCD_CGRAM                  0x40
#define LCD_SetCursor              0x80
#define LCD_FunctionReset          0x30

#define CLCD_ROW_1   1
#define CLCD_ROW_2   2

#define CLCD_COL_1   1
#define CLCD_COL_2   2
#define CLCD_COL_3   3
#define CLCD_COL_4   4
#define CLCD_COL_5   5
#define CLCD_COL_6   6
#define CLCD_COL_7   7
#define CLCD_COL_8   8
#define CLCD_COL_9   9
#define CLCD_COL_10  10
#define CLCD_COL_11  11
#define CLCD_COL_12  12
#define CLCD_COL_13  13
#define CLCD_COL_14  14
#define CLCD_COL_15  15
#define CLCD_COL_16  16


void CLCD_voidInit            ( void                           );
void CLCD_voidSendData        ( u_8 Copy_u8Data                );
void CLCD_voidSendString      ( const u_8 * Copy_u8PtrString   );
void CLCD_voidSendCommand     ( u_8 Copy_u8Command             );
void CLCD_voidClearScreen     ( void                           );
void CLCD_voidSetPosition     ( u_8 Copy_u8Row, u_8 Copy_u8Col );
void CLCD_voidSendExtraChar   ( u_8 Copy_u8Row, u_8 Copy_u8Col );

#endif
