#include <stdio.h>
#include <string.h>

typedef struct date{
    char day[3], month[3], year[5];
}Date;

int main(void){
    Date dates[2];
    for(int i = 0; i < 2; i++){
        printf("Enter the day of date %d: ", i+1);
        scanf("%2s", dates[i].day);
        printf("Enter the month of date %d: ", i+1);
        scanf("%2s", dates[i].month);
        printf("Enter the year of date %d: ", i+1);
        scanf("%4s", dates[i].year);
    }

    if(strcmp(dates[0].year,dates[1].year) == 0 && strcmp(dates[0].day,dates[1].day) == 0 && strcmp(dates[0].month,dates[1].month) == 0)
    printf("Dates are Equal");
    else
    printf("Dates are NOT Equal");
}