#include <stdio.h>
#include <math.h>

void armstrong(int a, int b);

int main()
{
    int lowerLimit, upperLimit;
    printf("lower limit: ");
    scanf("%d", &lowerLimit);
    printf("\nupper limit: ");
    scanf("%d", &upperLimit);
    printf("\nArmstrong numbers between %d to %d are: ", lowerLimit, upperLimit);
    armstrong(lowerLimit, upperLimit);
}

void armstrong(int a, int b){
    for(int i = a; i <= b; i++){
        int operation = i, testArm = 0;
        for(int j = 0; j < 10; j++){
            int currentDigit = operation % 10;
            testArm += currentDigit * currentDigit * currentDigit;
            operation /= 10;
            if(operation == 0)
                break;
        }
        if(testArm == i)
            printf("%d, ", i);
    }
    printf("\b\b.");
}
