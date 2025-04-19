#include <stdio.h>
#include <stdlib.h>

int main()
{
    int address;
    scanf("%x", &address); //%x is the format specifier of hexadecimal values
    int *ptr = (int *)address; //Casting
    //Now we have ptr that has the value of 0x600000(If it is the input)
}
