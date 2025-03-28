//https://codeforces.com/group/MWSDmqGsZm/contest/223339/submission/312816234

#include <stdio.h>
#include <stdlib.h>

void fromTo(int N){
    if(N <= 0)
        return;
    else{
        fromTo(N-1);
        printf("%d\n",N);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    fromTo(n);
}
