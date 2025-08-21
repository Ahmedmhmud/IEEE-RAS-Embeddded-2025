/*
*<<<<<<<<<<EXTI_config.h>>>>>>>>>>
*
*   Author  :  Ahmed Mahmoud
*   Layer   :  MCAL
*   SWC     :  EXTI
*
*/

#ifndef _EXTI_CONFIG_H_
#define _EXTI_CONFIG_H_


/*
Options:
1- EXTI_LINE0
2- EXTI_LINE1
3- EXTI_LINE2
*/

#define EXTI_LINE          EXTI_LINE0

/*
Options:
1- EXTI_FALLING_EDGE
2- EXTI_RISING_EDGE
3- EXTI_LOW_LEVEL
4- EXTI_ON_CHANGE
*/

#define EXTI_SENSE_MODE    EXTI_FALLING_EDGE


#endif   /*   EXTI_config.h   */
