#include <stdio.h>
#include <stdlib.h>

int add(int a, int b){
    return a + b;
}

int subtract(int a, int b){
    return a - b;
}

int multiply(int a, int b){
    return a * b;
}

int divide(int a, int b){//To solve problem of missing fractions we must define another pointer with return type of float or double
    return a / b;
}

int calc(int a, int b, int (*fptr)(int,int)){
    printf("%d\n", fptr(a,b));
}

int main()
{
    int option;
    while(1){
        printf("Select an option:\n1. Add\n2. Subtract\n3. Multiply\n4. Divide\n5. Exit\nYour option: ");
        scanf("%d", &option);
        int (*fptr)(int, int), a, b;
        switch(option){
        case 1:
            printf("Enter two numbers: ");
            scanf("%d %d", &a, &b);
            calc(a,b,add);
            break;
        case 2:
            printf("Enter two numbers: ");
            scanf("%d %d", &a, &b);
            calc(a,b, subtract);
            break;
        case 3:
            printf("Enter two numbers: ");
            scanf("%d %d", &a, &b);
            calc(a,b, multiply);
            break;
        case 4:
            printf("Enter two numbers: ");
            scanf("%d %d", &a, &b);
            calc(a,b,divide);
        case 5:
            exit(0);
            break;
        default:
            printf("Invalid option!!!\n");
            break;
        }
    }
}
