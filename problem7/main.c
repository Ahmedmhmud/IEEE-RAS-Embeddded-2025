#include <stdio.h>
#include <stdlib.h>

int GCD(int a, int b) {
    if (b == 0)
        return a;
    return GCD(b, a % b);
}

int main()
{
    int first, second;
    printf("first number: ");
    scanf("%d", &first);
    printf("\nsecond number: ");
    scanf("%d", &second);
    printf("%d", GCD(first, second));
}
