#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#define MAXLEN 1000
int mygetline(char s[], int lim);
int power(int x, int i);
int main()
{
    int x = 0;
    int n = 0;
    int i;
    char s[MAXLEN];
    int c = 0;
    char a[MAXLEN];
    mygetline(s, MAXLEN);
    for (i = 0; s[i] != ' ' && s[i] != '\n'; i++)
        x = s[i] - '0' + x * 10;
    if (s[i] == '\n')
        printf("ERROR INPUT\n");
    else
    {
        for (++i; s[i] != '\n'&&s[i]!='\0'; i++)
            n = s[i] - '0' + n * 10;
    }
    if (n == 0)
    {
        scanf("%s", a);
        printf("%d", atoi(a));
    }
    else
    {
        int a_n[n + 1];
        int sign = 1;
        for (i = 0; i < n + 1; i++)
            a_n[i] = 0;
        i=0;
        mygetline(s,MAXLEN);
        int k=0;
        while (s[k]!=EOF&&s[k]!='\n'&&s[k]!='\0')
        {
            if (s[k] == ' ')
            {
                a_n[i] = a_n[i] * sign;
                sign = 1; // 为下一次计算a_i做准备
                i++;
            }
            else if (s[k] == '-')
            {
                sign = -1; // 标记符号
            }
            else
            {
                a_n[i] = a_n[i] * 10 + s[k] - '0';
            }
            k++;
        }
        // 计算多项式的值

        int result = 0;
        for (i = 0; i < n+1; i++)
        {
            result += (a_n[i] * power(x, i));
        }
        printf("%d",result);
    }
    return 0;
}

int mygetline(char s[], int lim)
{
    int c, i = 0;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}

int power(int x, int i)
{
    int c = i;
    int p = 1;
    while (c--)
        p = p * x;
    return p;
}