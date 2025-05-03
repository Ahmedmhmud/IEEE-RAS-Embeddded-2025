#include <stdio.h>

typedef int real;
typedef int imaginary;
typedef struct Complex{
    real r;
    imaginary i;
} complex;

complex add(complex c1, complex c2){
    complex sum;
    sum.r = c1.r + c2.r;
    sum.i = c1.i + c2.i;
    return sum;
}

int main(){
    complex c1 = {1, 2};
    complex c2 = {2, 1};
    complex sum = add(c1, c2);
    printf("%d + %di", sum.r, sum.i);
}