#include <stdio.h>
#include <stdlib.h>

int main(){
    int size, sum = 0;
    scanf("%d",&size);
    int *ptr = malloc(sizeof(int)*size);
    if(ptr == NULL)
        exit(1);
    for(int i = 0; i < size; i++){
        printf("Enter element no. %d: ", i+1);
        scanf("%d", &ptr[i]);
        sum += ptr[i];
    }
    printf("%d\n", sum);
    free(ptr);
}