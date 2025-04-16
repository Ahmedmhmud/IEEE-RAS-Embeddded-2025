//https://codeforces.com/group/MWSDmqGsZm/contest/219774/submission/315882978
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, smallest;
    scanf("%d", &n);
    int arr[n];
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    smallest = arr[0];
    for(int i = 1; i < n; i++){
        if(smallest>arr[i])
            smallest = arr[i];
    }
    for(int i = 0; i < n; i++){
        if(smallest==arr[i]){
            printf("%d %d", smallest, i+1);
            break;
        }
    }
}
