#include <stdio.h>
#include <stdlib.h>

int main()
{
    char s1[20], s2[20],flag = 1, counter = 0;
    printf("String 1: ");
    scanf(" %[^\n]c", s1);
    printf("String 2: ");
    scanf(" %[^\n]c", s2);
    for(int i = 0; *(s1+i) != '\0'; i++){
        if(*(s1+i) != *(s2+i)) {flag = 0; break;}
        counter++;
    }
    if(!flag || (*(s1+counter) != *(s2+counter)))
        printf("NOT Same");
    else
        printf("Same");
}
