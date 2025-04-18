//https://codeforces.com/group/MWSDmqGsZm/contest/219856/submission/315896063
#include <stdio.h>
#include <ctype.h>

int main()
{
    /*int counter = 0;
    char s[1000001];
    scanf(" %[^\n]", s);
    for (int i = 0; s[i] !='\0'; i++)
        if(isalpha(s[i]) && !isalpha(s[i + 1]))
            counter++;
    printf("%d", counter);*/

    //Another Solution
    char s[1000001];
    int counter = 0;
    scanf(" %[^\n]", s);
    /*for(int i = 0; s[i] != ' '; i++)
        if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')){
            counter++;
            break;
        }
    for(int i = 0; s[i] !='\0'; i++){
        if(s[i] == ' ')
            for(int j = i+1; s[j] != ' '; j++)
                if((s[j] >= 'a' && s[j] <= 'z') || (s[j] >= 'A' && s[j] <= 'Z')){
                    counter++;
                    break;
                }
    }
    printf("%d", counter);*/
    for(int i = 0; s[i]  != '\0'; i++)
        if(((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) && !((s[i+1] >= 'a' && s[i+1] <= 'z') || (s[i+1] >= 'A' && s[i+1] <= 'Z')))
            counter++;
    printf("%d", counter);
}
