/*
*<<<<<<<<<<DIO_private.h>>>>>>>>>>
*
*   Author  :  Ahmed Mahmoud
*   Layer   :  MCAL
*   SWC     :  DIO/GPIO
*
*/

#ifndef _DIO_PRIVATE_H_
#define _DIO_PRIVATE_H_

/*   Group A   */
#define PORTA  *((v_u_8*) 0x3B)
#define DDRA   *((v_u_8*) 0x3A)
#define PINA   *((v_u_8*) 0x39)

/*   Group B   */
#define PORTB  *((v_u_8*) 0x38)
#define DDRB   *((v_u_8*) 0x37)
#define PINB   *((v_u_8*) 0x36)

/*   Group C   */
#define PORTC  *((v_u_8*) 0x35)
#define DDRC   *((v_u_8*) 0x34)
#define PINC   *((v_u_8*) 0x33)

/*   Group D   */
#define PORTD  *((v_u_8*) 0x32)
#define DDRD   *((v_u_8*) 0x31)
#define PIND   *((v_u_8*) 0x30)

#endif
