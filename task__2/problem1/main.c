#include<stdio.h>

//int check(int a, int b);

int main(){
    int a, b;
    printf("Enter two numbers: ");
    scanf("%d %d",&a,&b);
    if(a == 0){
        printf("%d\n", a);
    }
    else if(b == 0){
        printf("Math error\n");
    }
    else if(check(a,b) == 0){
        printf("%d is not divisible by %d\n", a, b);
    }
    else if(check(a,b) != 0){
    printf("%d", check(a, b));
    }
    return 0;
}

int check(int a, int b){
    if(a % b == 0){
        return a / b;
    }
    else{
        return 0;
    }
}
