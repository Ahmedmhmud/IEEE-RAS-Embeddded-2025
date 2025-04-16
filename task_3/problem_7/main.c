//https://codeforces.com/group/MWSDmqGsZm/contest/219856/submission/315892202
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, max = 1;
    scanf("%d", &n);
    char s[n];
    scanf("%s", s);
    for (int i = 0; i < n - 1; i++)
        if (s[i] != s[i + 1])
            max++;
    printf("%d\n", max);
}
