#include "headerguard.h"
#include <stdio.h>
#include <math.h>

int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

int divide(int a, int b) {
    if (b == 0) {
        printf("Math Error\n");
        return 0;
    }
    return a / b;
}

int power(int base, int exponent) {
    return (int)pow(base, exponent);
}
