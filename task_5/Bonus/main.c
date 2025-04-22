#include <stdio.h>
#include <stdlib.h>

int toInteger(char *s){//Assuming that the string containing one integer either +ve or -ve
    int integer = 0;
    if(*(s) == '-')
        s++;
    for(int i = 0; *(s+i) != '\0'; i++)
        if(*(s+i) >= '0' && *(s+i) <= '9')
        integer = (integer*10) + (*(s+i) - '0');
    return integer;
}

int main()
{
    char s[20];
    scanf("%s", s);
    int integer = toInteger(s);
    printf("%d", integer);
}
