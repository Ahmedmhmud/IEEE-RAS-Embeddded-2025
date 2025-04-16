#include <stdio.h>
#include <stdlib.h>

int main()
{
    //variables for checking if addition is an appropriate operation or not
    int a,b,c,d;
    printf("Enter the indecies of 1st matrix: ");
    scanf("%d %d", &a, &b);
    printf("\nEnter the indecies of 2nd matrix: ");
    scanf("%d %d", &c, &d);
    if(a != c || b != d){
        printf("\nInappropriate Operation");
        return 0;
    }
    int mat1[a][b], mat2[c][d];
    printf("\nEnter the elements of 1st matrix:\n");
    for(int i = 0; i < a; i++)
        for(int j = 0; j < b; j++)
            scanf("%d", &mat1[i][j]);
    printf("\nEnter the elements of 2nd matrix:\n");
    for(int i = 0; i < c; i++)
        for(int j = 0; j < d; j++)
            scanf("%d", &mat2[i][j]);
    printf("Output:\n");
    for(int i = 0; i < c; i++){
        for(int j = 0; j < d; j++){
            printf("%d ", (mat1[i][j]+mat2[i][j]));
        }
        printf("\n");
    }

}
