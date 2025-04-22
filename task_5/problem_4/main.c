#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b,c,d;
    printf("Enter dimensions of the 1st matrix: ");
    scanf("%d %d", &a, &b);
    printf("Enter dimensions of the 2nd matrix: ");
    scanf("%d %d", &c, &d);
    if(b != c){
        printf("Inappropriate operation!!!");
        return 0;
    }
    int mat1[a][b], mat2[c][d], prod[a][d];
    for (int i = 0; i < a; i++)
        for (int j = 0; j < d; j++)
            *(*(prod+i)+j) = 0;
    printf("Enter the 1st matrix:\n");
    for(int i = 0; i < a; i++)
        for(int j = 0; j < b; j++)
            scanf("%d", *(mat1+i)+j);
    printf("Enter the 2nd matrix:\n");
    for(int i = 0; i < c; i++)
        for(int j = 0; j < d; j++)
            scanf("%d", *(mat2+i)+j);
    printf("Product of matrices is:\n");
    for(int i = 0; i < a; i++){
        for(int j = 0; j < d; j++){
            for(int k = 0; k < c; k++)
                *(*(prod+i)+j) += (*(*(mat1+i)+k) * *(*(mat2+k)+j));
            printf("%d\t", *(*(prod+i)+j));
        }
        printf("\n");
    }
}
