#include <stdio.h>

typedef struct s_info {
    unsigned int rollNum : 4;  //will be stored in the first 4 bits
    unsigned int age : 8;      //will be stored in the 8 bits after rollNum bits 
    unsigned int marks : 3;    //will be stored in the 3 bits after age bits
    char name[10];
    char address[10];
} student_info;

void print(student_info s[], int index){
    for(int i = 0; i < index; i++){
        printf("{%d ,%d ,%d ,%s ,%s}\n", s[i].rollNum, s[i].age ,s[i].marks, s[i].name, s[i].address);
    }
}

int main()
{
    student_info s[5] = {
        {1, 18, 6, "Ahmed", "Safour"},
        {2, 19, 5, "Mohamed", "Diarb"},
        {3, 20, 7, "Omar", "Zagzig"},
        {4, 21, 4, "Hanafi", "Minia"},
        {5, 22, 3, "Othman", "Sohag"}
    };
    print(s, 5);
    printf("%d", sizeof(student_info));  //20 for strings and 4 for the shared int bit field
    return 0;
}