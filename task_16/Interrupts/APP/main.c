/*
 * main.c
 *
 *  Created on: ٢١‏/٠٨‏/٢٠٢٥
 *      Author: DELL
 */

#define F_CPU 8000000UL

#include "../LIB/STD_TYPES.h"
#include "../MCAL/EXTI/EXTI_interface.h"
#include "../HAL/CLCD/CLCD_interface.h"
#include "../HAL/SSD/SSD_interface.h"
#include "../HAL/SW/SW_interface.h"
#include "../HAL/LED/LED_interface.h"
#include <util/delay.h>

u_8 counter = 0;
LED_Type led = { LED_PORTD, LED_PIN0, ACTIVE_HIGH };

void EXTI0_ISR(void)
{
	counter = 0;
	LED_voidToggle(led);
}

int main(void)
{
	SW_Type sw = { SW_PORTD, SW_PIN2, SW_EXT_PULL_UP };
	SSD_Type ssd = { SSD_COMMON_ANODE, SSD_PORTB, SSD_PORTD, SSD_PIN1 };
	SSD_voidInitialDataPort(ssd);
	SSD_voidEnable(ssd);
	LED_voidInit(led);
	SW_voidInit(sw);
	CLCD_voidInit();
	_delay_ms(100);
	EXTI_voidInit();
	EXTI_voidSetCallBack(EXTI0_ISR, EXTI_LINE0);
	GIE_voidEnable();
	EXTI_voidEnableInterrupt(EXTI_LINE0);

	while(1)
	{
		if(counter != 9)
		{
			_delay_ms(1000);
			counter++;
		}
		else
		{
			counter = 0;
		}
		CLCD_voidSetPosition(CLCD_ROW_1, CLCD_COL_1);
		CLCD_voidSendData(counter + '0');
		SSD_voidSendNumber(ssd, counter);
	}
}
