//https://codeforces.com/group/MWSDmqGsZm/contest/219774/submission/315882000
#include <stdio.h>
#include <stdlib.h>

int scan(int arr[], int n, int x){
    for(int i = 0; i < n; i++){
        if(x == arr[i])
            return i;
    }
    return -1;
}

int main()
{
    int n,x;
    scanf("%d", &n);
    int arr[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    scanf("%d", &x);
    printf("%d", scan(arr, n, x));
}
