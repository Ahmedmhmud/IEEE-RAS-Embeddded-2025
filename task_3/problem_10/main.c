#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("Enter the size of the square: ");
    scanf("%d", &n);
    int arr[n][n], compare[2 * n + 2];
    for (int i = 0; i < 2 * n + 2; i++)
        compare[i] = 0;
    printf("Enter the elements of the square:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &arr[i][j]);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++){
            compare[i] += arr[i][j];
            compare[n+i] += arr[j][i];
            if(i == j)
                compare[2*n] += arr[i][j];
            if((i+j) == n-1)
                compare[2*n+1] += arr[i][j];
        }
    char flag = 0;
    for(int i = 1; i < (2*n+2); i++)
        if(compare[0] != compare[i]){
            flag = 1;
            break;
        }
    if(flag)
        printf("The square is not a magic square.");
    else
        printf("The square is a magic square.");
}
