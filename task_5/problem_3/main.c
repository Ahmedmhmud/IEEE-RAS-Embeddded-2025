#include <stdio.h>
#include <stdlib.h>

int main()
{
    int temp, n;
    printf("No. of elements: ");
    scanf("%d", &n);
    int arr[n];
    for(int i = 0; *(s+i) != '\0'; i++)
        for(int j = 0; i )
    for(int i = 0; i < n; i++)
        scanf("%d", arr+i);
    for(int i = 0; i < n; i++)
        for(int j = i + 1; j < n; j++)
            if(*(arr+j) < *(arr+i)){
                temp = *(arr+i);
                *(arr+i) = *(arr+j);
                *(arr+j) = temp;
            }
    printf("Array in ascending order: ");
    for(int i = 0; i < n; i++)
        printf("%d ", *(arr+i));
    printf("\nArray in descending order: ");
    for(int i = 0; i < n; i++)
        printf("%d ", *(arr+n-i-1));
}
