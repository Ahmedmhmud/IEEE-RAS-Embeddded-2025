//https://codeforces.com/group/MWSDmqGsZm/contest/223339/submission/312850231

#include <stdio.h>
#include <stdlib.h>

int fib(int n){
    if(n == 1 || n == 2){
        return n - 1;
    }
    else
        return fib(n - 1) + fib(n - 2);
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d",fib(n));
}
