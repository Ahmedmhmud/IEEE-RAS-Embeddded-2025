#include <stdio.h>
#include <stdlib.h>

#define ASCENDINGLY //To sort decendingly, change ASCENDINGLY with any other word 

#ifdef ASCENDINGLY
    #define sort sortasc
#else
    #define sort sortdec
#endif

int *sortasc(int size){
    int *arr = malloc(sizeof(int) *size);
    for(int i = 0; i < size; i++){
        printf("Enter element no. %d: ", i+1);
        scanf("%d", &arr[i]);
    }

    for(int i = 0; i < size - 1; i++){
        for(int j = 0; j < size - i - 1; j++){
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    return arr;
}

int *sortdec(int size){
    int *arr = malloc(sizeof(int) *size);
    for(int i = 0; i < size; i++){
        printf("Enter element no. %d: ", i+1);
        scanf("%d", &arr[i]);
    }

    for(int i = 0; i < size - 1; i++){
        for(int j = 0; j < size - i - 1; j++){
            if (arr[j] < arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    return arr;
}

int main(){
    int size;
    scanf("%d", &size);
    int *ptr = sort(size);
    for(int i = 0; i < size; i++){
        printf("%d  ", ptr[i]);
    }
    free(ptr);
}