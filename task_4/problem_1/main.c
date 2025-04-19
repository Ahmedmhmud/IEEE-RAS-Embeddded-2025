#include <stdio.h>
#include <stdlib.h>

void pointer(float *ptr);

int main()
{
    int a = 0;
    int *ptrToA = &a; //Now ptrToA is the address of a
    (*ptrToA)++;      //If i want to change in the value of a using its pointer
    printf("%d", a);  //Displaying output which is 1

    float b = 1.0;
    float *ptrToB = &b;
    pointer(ptrToB);  //passing pointer to a func.
    printf("\n%f", b);
}

void pointer(float *ptr){
    (*ptr)++;
}
