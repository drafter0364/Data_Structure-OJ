/*4.10-字符串求逆*/

#include <stdio.h>
#include <string.h>

#define MAXLEN 1000

void reverse(char s[]);
int main()
{
    char s[MAXLEN];
    int c;
    int i;
    while((c=getchar())!='\n')
        s[i++]=c;
    s[i]='\0';
    reverse(s);
    printf("%s", s);
    return 0;
}

void reverse(char s[])
{
    int c, i, j;
    for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
    {
        c = s[i],
        s[i] = s[j],
        s[j] = c;
    }
}