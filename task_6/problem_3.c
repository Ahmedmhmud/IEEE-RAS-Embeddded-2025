#include <stdio.h>

typedef struct cat{
    char *name, *kind;
}Cat;

void createCat(Cat *newCat, char *name, char *kind);

int main(void){
    Cat newCat;
    createCat(&newCat, "Fathy", "AUDI");
    printf("Name: %s\nKind: %s", newCat.name, newCat.kind);
}

void createCat(Cat *newCat, char *name, char *kind){
    newCat->name = name;
    newCat->kind = kind;
}