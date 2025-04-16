//https://codeforces.com/group/MWSDmqGsZm/contest/219774/submission/315884785
#include <stdio.h>

int main()
{
    int n, temp;
    scanf("%d", &n);
    int arr[n];
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    for(int i = 0; i < n; i++){
        char flag = 'f';
        for(int j = 0; j < n - 1; j++)
            if(arr[j]>arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                flag = 't';
            }
        if(flag == 'f')
            break;
    }
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);
}
