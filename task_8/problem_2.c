#include <stdio.h>
#define ADDING  //To subtract, change ADDING with any other word

#ifdef ADDING
    #define operation add
#else
    #define operation sub
#endif

#define add(x, y) (x + y)
#define sub(x, y) (x - y)

int main(void){
    int a = 5, b =3;
    printf("%d\n", operation(a,b)); //In this case, Output is 8
}