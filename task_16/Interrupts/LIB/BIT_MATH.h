/*
*<<<<<<<<<<BIT_MATH.h>>>>>>>>>>
*
*   Author  :  Ahmed Mahmoud
*
*/

#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(VAL, BIT) ((VAL) |= (1<<(BIT)))
#define CLR_BIT(VAL, BIT) ((VAL) &= ~(1<<(BIT)))
#define TOG_BIT(VAL, BIT) ((VAL) ^= (1<<(BIT)))
#define GET_BIT(VAL, BIT) (((VAL)>>(BIT)) & 1)
#define SET_PORT(VAL) ((VAL) = 0xFF)
#define CLR_PORT(VAL) ((VAL) = 0x00)
#define TOG_PORT(VAL) ((VAL) ^= 0xFF)

#endif /* BIT_MATH_H_ */
