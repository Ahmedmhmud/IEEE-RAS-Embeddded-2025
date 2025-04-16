#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//int isPrime(int a);       //function for problem 7

int main()
{
                                                      //problem 1
    /*int input[100],i = 0,n,large,small;
    while(1){
        scanf("%d", &n);
        if(n == -1)
            break;
        input[i] = n;
        i++;
    }
    large = small = input[0];
    for(int j = 1; j < i; j++){
        if(large < input[j])
            large = input[j];
        if(small > input[j])
            small = input[j];
    }
    printf("%d %d", large, small);
    return 0;*/

                                                     //problem 2: https://codeforces.com/group/MWSDmqGsZm/contest/219158/submission/311786411
    /*int input;
    scanf("%d", &input);
    int years = (input / 365);
    input -= (365 * years);
    int months = (input / 30);
    input -= (30 * months);
    int days = input;
    printf("%d years\n%d months\n%d days",years,months,days);*/

                                                     //problem 3: https://codeforces.com/group/MWSDmqGsZm/contest/219158/submission/312070776
    /*long a,b,c,d;
    scanf("%ld %ld %ld %ld",&a,&b,&c,&d);
    long result = (a%100) * (b%100);
    result = (result * (c%100)) % 100;
    result = (result * (d%100)) % 100;
    if(result <= 9)
        printf("0");
    printf("%ld", result);*/

                                                    //problem 4
    /*char input[20];
    scanf("%s", input);
    int n = strlen(input),flag = 0;
    for(int i = 0; i < n/2; i++){
        if(input[i] != input[n-i-1])
            flag = 1;
    }
    if(flag == 1)
        printf("NOT PALINDROME");
    else
        printf("PALINDROME");*/

                                                    //problem 5: https://codeforces.com/group/MWSDmqGsZm/contest/219432/submission/311959639
    /*int input[1000],counter = 0;
    for(int i = 0;; i+=2){
        scanf("%d %d",&input[i],&input[i+1]);
        if(input[i] <= 0 || input[i+1] <= 0)
            break;
        counter+=2; //to count the no. of elements in the array
    }

    int sum = 0;
    for(int j = 0; j < counter; j+=2){
        if(input[j] > input[j+1]){
           for(int k = input[j+1]; k <= input[j]; k++){
            printf("%d ", k);
            sum += k;
           }
           printf("sum =%d\n",sum);
           sum = 0;
        }
        else if(input[j] < input[j+1]){
           for(int k = input[j]; k <= input[j+1]; k++){
            printf("%d ", k);
            sum += k;
           }
           printf("sum =%d\n",sum);
           sum = 0;
        }
        else
            printf("%d sum =%d\n",input[j],input[j]);
    }*/

                                                        //problem 6: https://codeforces.com/group/MWSDmqGsZm/contest/219432/submission/311974701
    /*int input;
    scanf("%d", &input);
    for(int i = 1;i <= input; i++){
        if(input%i == 0){
            printf("%d\n", i);
        }
    }*/

                                                        //problem 7
    int input,arr[20],sum = 0;
    do
    {
        printf("Enter a positive integer: ");
        scanf("%d", &input);
    }while(input < 0);

    for(int i = 0; i < 20; i++){
        arr[i] = input % 10;
        input /= 10;
        sum += arr[i];
        if(input == 0)
            break;
    }
    if(isPrime(sum))
        printf("The sum of digits (%d) is a prime number.", sum);
    else
        printf("The sum of digits (%d) is not a prime number.", sum);

                                                        //problem 8
    /*int input,sum=0;
    do
    {
        printf("Enter a positive integer: ");
        scanf("%d", &input);
    }while(input < 0);
    int possibleDivisor = input-1;
    while(possibleDivisor > 0){
        if(input%possibleDivisor ==0)
            sum += possibleDivisor;
        possibleDivisor--;
    }
    if(sum == input)
        printf("%d is a perfect number\n", input);
    else
        printf("%d is not a perfect number\n", input);*/


}

//function for problem 7
int isPrime(int a)
{
    for(int i = 2; i < a; i++){
        if(a%i == 0)
            return 0;
    }
    return 1;
}
