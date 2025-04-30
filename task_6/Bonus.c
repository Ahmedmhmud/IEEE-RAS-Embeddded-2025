#include <stdio.h>
#include <stdlib.h>

typedef struct Employee{
    char *name;
    int id;
}Emp;

void delete(Emp *e);

int main(void){
    Emp *engineer = malloc(sizeof(Emp));
    engineer->name = malloc(sizeof(char) * 10);
    delete(engineer);
}

void delete(Emp *e){
    if(e == NULL)
    return;

    if (e->name != NULL) {
        free(e->name);
        e->name = NULL;
    }

    free(e);

}