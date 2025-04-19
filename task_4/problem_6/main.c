#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a = 5, *ptr = &a;
    printf("%p\t%p",ptr,&a);
    /*
    %p is the format specifier if you want to tell the compiler that the variable is pointer type of data to print its actual value
    ptr: without the "*" you can get the value of the pointer itself
    &a : to access the address of a
    SO the output is the address of a
    */
    printf("\n%p\t%p",&*ptr,*&ptr);
    /*
    Let's analyze each parameter
    %p : the format specifier of the pointers

    &*ptr: First --> *ptr is the value of the variable that the pointer points to
    SO when we add & to *ptr, it means that we want to access the address of the variable

    *&ptr: &ptr is the address of the pointer, At the end of the day Pointer is a variable
    SO when we add * to &ptr, it means that we want the value of the variable that has this address which is the pointer itself

    SO finally the output like the first line: the address of a
    */

}
