#include <stdio.h>

typedef union {
    int a;
    float b;
    char c;
} Data;

int main() {
    Data data;
    data.a = 65;
    printf("a = %d\n", data.a);
    printf("b = %f\n", data.b);
    printf("c = %c\n", data.c);
    data.b = 2.9;
    printf("a = %d\n", data.a);
    printf("b = %f\n", data.b);
    printf("c = %c\n", data.c);
    data.c = 'Z';
    printf("After assigning data.c = 'Z':\n");
    printf("a = %d\n", data.a);
    printf("b = %f\n", data.b);
    printf("c = %c\n", data.c);
    return 0;
} //Every time a and b have different values, that is because int and float have different binary format and representation
  //But a and c are the same values, actually c will be a character that has the same ASCII code of a