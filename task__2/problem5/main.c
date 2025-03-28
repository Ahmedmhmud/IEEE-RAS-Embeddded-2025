//https://codeforces.com/group/MWSDmqGsZm/contest/223339/submission/312815789

#include <stdio.h>
#include <stdlib.h>

void print(int num){
    if(num == 0){
        return;
    }
    else{
        print(num/10);
        printf("%d ", num % 10);
    }
}

void isZero(int num){
    if(num == 0)
    {
        printf("0");
    }
    else
        print(num);
}

int main()
{
    int T, input[10];
    scanf("%d", &T);
    for(int i = 0; i < T; i++){
        scanf("%d", &input[i]);
    }
    for(int i = 0; i < T; i++){
        isZero(input[i]);
        printf("\n");
    }
}
