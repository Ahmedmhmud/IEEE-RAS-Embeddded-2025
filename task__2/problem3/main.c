//https://codeforces.com/group/MWSDmqGsZm/contest/223205/submission/312834573

#include <stdio.h>

int isOdd(int num);
int isPalindrome(int num);

int main() {
    int N;
    if(scanf("%d", &N) != 1 || N <= 0) {
        printf("NO");
        return 0;
    }
    printf(isOdd(N) && isPalindrome(N) ? "YES" : "NO");
    return 0;
}

int isOdd(int num) {
    return num & 1;
}

int isPalindrome(int num) {
    if(num == 0) return 0;

    int total_bits = sizeof(num) * 8;
    int msb_pos = total_bits - 1;

    while(msb_pos >= 0 && !(num & (1 << msb_pos)))
        msb_pos--;

    if(msb_pos < 0) return 0;

    for(int i = 0; i <= msb_pos/2; i++) {
        int left_bit = (num >> (msb_pos - i)) & 1;
        int right_bit = (num >> i) & 1;
        if(left_bit != right_bit)
            return 0;
    }
    return 1;
}
//Another solution
/*#include <stdio.h>
#include <stdlib.h>

int isOdd(int num);
int isPalindrome(int num);

int main()
{
    int N;
    scanf("%d", &N);
    if(N < 0){
        printf("NO");
        return 0;
    }
    if(isOdd(N) && isPalindrome(N))
        printf("YES");
    else
        printf("NO");
}

int isOdd(int num){
    if(num & 1)
        return 1;
    return 0;
}

int isPalindrome(int num){
    if(num == 0)
        return 0;
    int counter = 0;
    while(1){
        if((num<<counter) & (1<<31))
            break;
        counter++;
    }
    if(counter == 0) return 0;
    for(int i = counter; i < 32-counter; i++){
        if(((num<<i) & (1<<i)) != (num<<(32-i)) & (1<<32-i))
            return 0;
    }
    return 1;
}*/
