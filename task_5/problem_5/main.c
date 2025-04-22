#include <stdio.h>
#include <stdlib.h>

int isOdd(int arr[], int odd[], int n){
    int counter = 0;
    for(int i = 0; i < n; i++)
        if((*(arr+i)%2) != 0){
            *(odd+counter) = *(arr+i);
            counter++;
        }
    return counter;
}

int main()
{
    int n;
    printf("Enter no. of elements: ");
    scanf("%d", &n);
    int arr[n], odd[n+1];
    printf("Enter elements: ");
    for(int i = 0; i < n; i++)
        scanf("%d", arr+i);
    int counter = isOdd(arr, odd, n);
    printf("Odd numbers are: ");
    for(int i = 0; i < counter; i++)
        printf("%d ", *(odd+i));
    printf("\nTotal of odd numbers: %d", counter);

    //There is no need to return multiple values while you can use calling by reference principle to changing the original values
    //And this achieves that required task which is returning values by changing the values using pointers
}
