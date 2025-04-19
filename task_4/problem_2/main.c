#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num1, num2;
    printf("num1: ");
    scanf("%d", &num1);
    printf("\nnum2: ");
    scanf("%d", &num2);
    int *ptrTo1 = &num1, *ptrTo2 = &num2;
    printf("\nSum = %d", (*ptrTo1) + (*ptrTo2));
    printf("\nDifference = %d", (*ptrTo1) - (*ptrTo2));
    printf("\nProduct = %d", (*ptrTo1) * (*ptrTo2));
    printf("\nQuotient = %f", (float)(*ptrTo1) / (*ptrTo2));
}
