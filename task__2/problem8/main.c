//https://codeforces.com/group/MWSDmqGsZm/contest/223339/submission/312855045

#include <stdio.h>

int seq(int n) {
    if (n == 1) {
        return 1;
    } else if (n % 2 == 0) {
        return 1 + seq(n / 2);
    } else {
        return 1 + seq(3 * n + 1);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%d\n", seq(n));
    return 0;
}
