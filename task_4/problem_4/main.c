#include <stdio.h>
#include <stdlib.h>

void printEven(char *s);

int main()
{
    char s[10];
    scanf("%s", s);
    printEven(s);
}

void printEven(char *s){
    for(int i = 0; *(s+i) != '\0'; i++){
        int digit = *(s+i) - '0';
        if(digit%2 == 0)
            printf("%d", digit);
    }
}
