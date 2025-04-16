//https://codeforces.com/group/MWSDmqGsZm/contest/219774/submission/315890512
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,m;
    scanf("%d %d", &n, &m);
    int arr1[n][m],arr2[n][m];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++){
            scanf("%d", &arr1[i][j]);
            //temp = arr[i][j];
            arr2[i][m-j-1] = arr1[i][j];
            //arr[i][m-j-1] = temp;
        }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++)
            printf("%d ", arr2[i][j]);
        printf("\n");
    }
}
