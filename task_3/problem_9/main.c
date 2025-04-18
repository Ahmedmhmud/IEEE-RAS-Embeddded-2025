//https://codeforces.com/group/MWSDmqGsZm/contest/219774/submission/316077493
#include <stdio.h>

int main()
{
    int n, counter = 0;
    scanf("%d", &n);
    int arr[n];
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    int minimum = arr[0];
    for(int i = 1; i < n; i++){
        if(minimum > arr[i])
            minimum = arr[i];
    }
    for(int i = 0; i < n; i++)
        if(arr[i] == minimum)
            counter++;
    if(counter%2 == 0)
        printf("Unlucky");
    else
        printf("Lucky");
}
