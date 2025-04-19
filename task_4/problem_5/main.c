#include <stdio.h>
#include <stdlib.h>

int main()
{
    char s[20];
    scanf(" %[^\n]c", s);
    printLength(s);
}

void printLength(char *s){
    int length = 0;
    for(int i = 0; *(s+i) != '\0'; i++)
        length++;
    printf("%d", length);
}
