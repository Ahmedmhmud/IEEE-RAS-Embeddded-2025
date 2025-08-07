/*
*<<<<<<<<<<main.c>>>>>>>>>>
*
*   Author  :  Ahmed Mahmoud
*   Layer   :  APP
*   SWC     :  ATmega32
*
*/

#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include "../HAL/MOTOR/MOTOR_interface.h"
#include "../HAL/SW/SW_interface.h"

int main(void)
{
	SW_Type SW_stop  = {SW_PORTA, SW_PIN0, SW_EXT_PULL_DOWN};
	SW_Type SW_forw  = {SW_PORTA, SW_PIN1, SW_EXT_PULL_DOWN};
	SW_Type SW_back  = {SW_PORTA, SW_PIN2, SW_EXT_PULL_DOWN};
	SW_Type SW_left  = {SW_PORTA, SW_PIN3, SW_EXT_PULL_DOWN};
	SW_Type SW_right = {SW_PORTA, SW_PIN4, SW_EXT_PULL_DOWN};

	SW_voidInit(SW_stop);
	SW_voidInit(SW_forw);
	SW_voidInit(SW_back);
	SW_voidInit(SW_left);
	SW_voidInit(SW_right);

	MOTOR_Type MOTOR_forw_back  = {MOTOR_PORTC, MOTOR_PIN0, MOTOR_PIN1};
	MOTOR_Type MOTOR_left_right = {MOTOR_PORTC, MOTOR_PIN2, MOTOR_PIN3};

	MOTOR_voidInit(MOTOR_forw_back) ;
	MOTOR_voidInit(MOTOR_left_right);

	while(1)
	{
		if(SW_u8GetPressed(SW_stop))
		{
		    MOTOR_voidStop(MOTOR_forw_back);
		    MOTOR_voidStop(MOTOR_left_right);
		}
        else if(SW_u8GetPressed(SW_forw))
        {
            MOTOR_voidStop(MOTOR_left_right);
            MOTOR_voidRotateCW(MOTOR_forw_back);
        }
        else if(SW_u8GetPressed(SW_back))
        {
            MOTOR_voidStop(MOTOR_left_right);
            MOTOR_voidRotateCCW(MOTOR_forw_back);
        }
        else if(SW_u8GetPressed(SW_left))
        {
            MOTOR_voidStop(MOTOR_forw_back);
            MOTOR_voidRotateCW(MOTOR_left_right);
        }
        else if(SW_u8GetPressed(SW_right))
        {
            MOTOR_voidStop(MOTOR_forw_back);
            MOTOR_voidRotateCCW(MOTOR_left_right);
        }
	}
}
