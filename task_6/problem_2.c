#include <stdio.h>

typedef struct employee{
    char *name;
    int id;
}Employee;

void initialize(Employee *engineer);
void print(Employee *engineer);

int main(){
    Employee engineer;
    initialize(&engineer);
    print(&engineer);
    return 0;
}

void initialize(Employee *engineer){
    engineer->name = "Hossam";
    engineer->id = 1;
}

void print(Employee *engineer){
    printf("Name: %s\nId:  %d", engineer->name, engineer->id);
}