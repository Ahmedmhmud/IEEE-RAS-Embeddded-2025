#include <stdio.h>

typedef int Integer;
typedef float Fraction;
typedef char letter;

int main(){
    printf("%d\n%d\n%d\n", sizeof(Integer), sizeof(Fraction), sizeof(letter));
}