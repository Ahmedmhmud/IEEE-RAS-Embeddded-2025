#include <stdio.h>

typedef struct example1 {
    char a;
    int b;
    char c;
} Example1;
/*in example 1: Output is 12
the CPU cycle is 4 bytes at a time
then a will be stored in the first byte of the cycle
but when storing b, there will be a byte in the second cycle so this is a waste of CPU cycles
then the architecture stores empty 3 bytes and start storing b from the fifth byte that b will fit for one CPU cycle
then c is stored form the ninth byte and the rest of the cycle is empty
*/

typedef struct example2 {
    char a;
    char b;
    int c;
} Example2;
/*in example 2: Output is 8
the CPU cycle is 4 bytes at a time
then a and b will be stored in the first cycle
but when storing c in the first byte there will be 2 bytes in the second cycle
so c is all stored in the second cycle
*/

int main(void) {
    Example1 ex1;
    Example2 ex2;
    printf("Size of Example1: %lu bytes\n", sizeof(ex1));
    printf("Size of Example2: %lu bytes\n", sizeof(Example2));
}
