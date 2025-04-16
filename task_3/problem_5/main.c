//https://codeforces.com/group/MWSDmqGsZm/contest/219774/submission/315888388
#include <stdio.h>

int main()
{
    int n, pd = 0, sd = 0;
    scanf("%d", &n);
    int arr[n][n];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++){
            scanf("%d", &arr[i][j]);
            if(i == j)
                pd += arr[i][j];
            if((i+j) == (n-1))
                sd += arr[i][j];
        }
    printf("%d", abs(pd - sd));
}
