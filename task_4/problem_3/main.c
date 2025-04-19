#include <stdio.h>
#include <stdlib.h>

void swap(int *ptr1, int *ptr2);

int main()
{
    int a = 5, b = 10;
    printf("Before swapping\na = %d\nb = %d", a, b);
    int *ptra = &a, *ptrb = &b;
    swap(ptra, ptrb);
    printf("\nAfter swapping\na = %d\nb = %d", a, b);
}

void swap(int *ptr1, int *ptr2){
    int temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}
