/*
* main.c - Fixed Calculator Implementation
*
* Created on: ١٧‏/٠٨‏/٢٠٢٥
* Author: DELL
*/

#include <stdlib.h>
#include <util/delay.h>
#include "../LIB/STD_TYPES.h"
#include "../HAL/CLCD/CLCD_interface.h"
#include "../HAL/KPD/KPD_interface.h"

int main(void)
{
    CLCD_voidInit();
    _delay_ms(100);

    KPD_voidInit();

    CLCD_voidSendExtraChar(CLCD_ROW_1, CLCD_COL_7);
    _delay_ms(5000);
    CLCD_voidClearScreen();

    // Calculator variables - use larger types to avoid overflow
    u_8 flag1 = 0, flag2 = 0;
    u_16 firstNum = 0, secondNum = 0;  // Changed to u_16 to handle larger numbers
    u_8 op = '\0';
    u_8 error[] = "Error";
    char buffer[10];  // Increased buffer size and made it char array

    while(1)
    {
        u_8 pressed = KPD_u8GetPressed();

        if (pressed != '\0')  // Only process if a key is actually pressed
        {
            if (pressed >= '0' && pressed <= '9')
            {
                if(flag1 == 0)
                {
                    flag1 = 1;
                }

                if(op == '\0') // First number
                {
                    CLCD_voidSendData(pressed);
                    firstNum = (firstNum * 10) + (pressed - '0');
                }
                else // Second number
                {
                    if(flag2 == 0)
                    {
                        flag2 = 1;
                    }

                    if(flag1 != 0)
                    {
                        CLCD_voidSendData(pressed);
                        secondNum = (secondNum * 10) + (pressed - '0');
                    }
                    else
                    {
                        CLCD_voidClearScreen();
                        CLCD_voidSendString(error);
                        _delay_ms(1000);
                        CLCD_voidClearScreen();
                        flag1 = 0; flag2 = 0; firstNum = 0; secondNum = 0; op = '\0';
                    }
                }
            }
            else if(pressed == '+' || pressed == '-' || pressed == '*' || pressed == '/')
            {
                if(flag1 == 1 && op == '\0')
                {
                    CLCD_voidSendData(pressed);
                    op = pressed;
                }
                else
                {
                    CLCD_voidClearScreen();
                    CLCD_voidSendString(error);
                    _delay_ms(1000);
                    CLCD_voidClearScreen();
                    flag1 = 0; flag2 = 0; firstNum = 0; secondNum = 0; op = '\0';
                }
            }
            else if(pressed == '=')
            {
                if(flag1 == 1 && flag2 == 1 && op != '\0')
                {
                    s_16 result = 0;  // Use signed integer for result
                    u_8 error_flag = 0;

                    switch(op)
                    {
                        case '+':
                            result = firstNum + secondNum;
                            break;
                        case '-':
                            result = firstNum - secondNum;
                            break;
                        case '*':
                            result = firstNum * secondNum;
                            break;
                        case '/':
                            if(secondNum == 0)
                            {
                                error_flag = 1;
                                CLCD_voidClearScreen();
                                CLCD_voidSendString(error);
                                _delay_ms(1000);
                                CLCD_voidClearScreen();
                                flag1 = 0; flag2 = 0; firstNum = 0; secondNum = 0; op = '\0';
                            }
                            else
                            {
                                result = firstNum / secondNum;
                            }
                            break;
                        default:
                            error_flag = 1;
                            break;
                    }

                    if(error_flag == 0)
                    {
                        // Convert result to string
                        itoa(result, buffer, 10);

                        CLCD_voidClearScreen();
                        CLCD_voidSetPosition(CLCD_ROW_1, CLCD_COL_1);
                        CLCD_voidSendString("Result:");
                        CLCD_voidSetPosition(CLCD_ROW_2, CLCD_COL_1);
                        CLCD_voidSendString(buffer);
                        // Reset variables
                        flag1 = 0; flag2 = 0; firstNum = 0; secondNum = 0; op = '\0';
                    }
                }
                else
                {
                    CLCD_voidClearScreen();
                    CLCD_voidSendString(error);
                    _delay_ms(1000);
                    CLCD_voidClearScreen();
                    flag1 = 0; flag2 = 0; firstNum = 0; secondNum = 0; op = '\0';
                }
            }
            else if(pressed == 'C' || pressed == 'c') // Clear
            {
                flag1 = 0; flag2 = 0; firstNum = 0; secondNum = 0; op = '\0';
                CLCD_voidClearScreen();
            }

            // Add small delay to prevent key bounce
            _delay_ms(50);
        }
    }

    return 0;
}

// Alternative simple test function - call this first to test LCD
void TestLCD_Simple(void)
{
    CLCD_voidInit();
    _delay_ms(100);

    CLCD_voidSendString("LCD Test");
    CLCD_voidSetPosition(CLCD_ROW_2, CLCD_COL_1);
    CLCD_voidSendString("Working!");

    while(1)
    {
        _delay_ms(1000);
        CLCD_voidClearScreen();
        _delay_ms(1000);
        CLCD_voidSendString("Blink Test");
    }
}
