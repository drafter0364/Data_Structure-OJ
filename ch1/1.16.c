// 三整数排序

#include <stdio.h>
#define MAXLEN 1000
int main()
{
    char s[MAXLEN];
    gets(s);
    int i = 0;
    int a, b, c;
    a = b = c = 0;
    int sign = 1;
    if (s[i] == '-')
    {
        sign = -1;
        i++;
    }
    for (; (s[i]) != ' ' && s[i] != '-' && s[i] != '\0'; i++)
        a = a * 10 + s[i] - '0';
    a = a * sign;
    i++;
    if (s[i] == '-')
        sign = -1;
    else
        sign = 1;
    for (; (s[i]) != ' ' && s[i] != '-' && s[i] != '\0'; i++)
        b = b * 10 + s[i] - '0';
    b = b * sign;
    i++;
    if (s[i] == '-')
        sign = -1;
    else
        sign = 1;
    for (; (s[i]) != ' ' && s[i] != '-' && s[i] != '\0'; i++)
        c = c * 10 + s[i] - '0';
    c = c * sign;
    int max = 0;
    max = (a > b) ? a : b;
    max = (max > c) ? max : c;
    if(max==a){
        if(b>c)
            printf("%d %d %d",a,b,c);
        else
            printf("%d %d %d",a,c,b);
    }
    else if(max==b){
        if(a>c)
            printf("%d %d %d",b,a,c);
        else
            printf("%d %d %d",b,c,a);
    }
    else{
        if(a>b)
            printf("%d %d %d",c,a,b);
        else
            printf("%d %d %d",c,b,a);
    }
    return 0;

}