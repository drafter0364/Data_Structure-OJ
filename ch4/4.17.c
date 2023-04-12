/*4-17 字符串替换
编写算法，实现串的基本操作Replace(&S, T, V)，替换*/

#include <stdio.h>
#include <string.h>
#define MAXLEN 1000
void replace(char s[], char t[], char v[]);
int main()
{
    char s[MAXLEN];
    char t[MAXLEN];
    char v[MAXLEN];
    scanf("%s", s);
    scanf("%s", t);
    scanf("%s", v);
    replace(s, t, v);
    printf("%s", s);
    return 0;
}

void replace(char s[], char t[], char v[])
{
    int i, j, p,k;
    for (i = 0; i < strlen(s); i++)
    {
        p=i;
        for (j = 0; j < strlen(t) && s[p] == t[j];p++,j++)
            ;
        if (j==strlen(t))
        {
            for (k = i + strlen(t); k < strlen(s) + 1; k++)
                s[k + strlen(v) - strlen(t)] = s[k];
            p=i;
            for(k=0;k<strlen(v);p++,k++)
                s[p]=v[k];
        }
    }
    return;
}
