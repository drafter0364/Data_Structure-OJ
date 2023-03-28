/*试写一个判别表达式中开,闭括号是否配对出现的算法。

比如:'(a+b(c-d))'是配对出现的,而'(d-e))'不是配对出现的。*/

#include <stdio.h>
#define MAXLEN 1000
int main()
{
    char s[MAXLEN];
    scanf("%s", s);
    int i;
    int left = 0;
    for (i = 0; s[i] != '\0'; i++)
    {
        if (s[i] == '(')
            left++;
        else if (s[i] == ')')
        {
            left--;
        }
        else
            ;
        if (left < 0)
        {
            printf("0");
            return 0;
        }
    }
    if(left==0)
        printf("1");
    else
        printf("0");
    return 0;
}