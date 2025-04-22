#include <stdio.h>
#include <stdlib.h>

int main()
{
    char s1[20], s2[20], counter;
    printf("String to be copied: ");
    scanf(" %[^\n]s", s1);
    for(int i = 0; *(s1+i) != '\0'; i++){
        *(s2+i) = *(s1+i);
        counter++;
    }
    *(s2+counter) = '\0';
    printf("Original string: %s\n", s1);
    printf("Original string: %s", s2);
}
