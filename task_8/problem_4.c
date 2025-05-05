#include <stdio.h>
#include <stdlib.h>

int main(void){
    int *ptr1 = malloc(sizeof(int)*10);
    int *ptr2 = calloc(5, sizeof(int));
    int *ptr3 = calloc(50, sizeof(int)); //If the memory is limited ,It will return NULL and the program will terminate
    int *ptr4 = calloc(5, sizeof(int));
    if(ptr1 == NULL || ptr2 == NULL || ptr3 == NULL || ptr4 == NULL){
        printf("Allocation failed\n");
        exit(1);
    }
    free(ptr2);
    for (int i = 0; i < 10; i++) {
        ptr1[i] = i + 1;
        ptr3[i] = (i + 1) * 10; 
    }
    for(int i = 0; i < 10; i++){
        printf("%d  %d\n",ptr1[i],ptr3[i]);
    }
    free(ptr1);
    free(ptr3);
    free(ptr4);
}