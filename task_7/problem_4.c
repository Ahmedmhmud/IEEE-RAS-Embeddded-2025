#include <stdio.h>

typedef enum day{
    SATURDAT,  //weekend
    SUNDAY,
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY    //weekend
}weekDay;

void dayStatus(weekDay day){
    if(day > 0 && day < 6)
        printf("Working day");
    else
        printf("Weekend");
}

int main(){
    weekDay day = SATURDAT;
    dayStatus(day);
}