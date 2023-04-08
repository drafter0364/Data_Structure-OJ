/*4.16-字符串比较
编写算法，实现串的基本操作StrCompare(S,T)*/

#include <stdio.h>
#include <string.h>
#define MAXLEN 1000

int StrCompare(char s[],char t[]);
int main()
{
    char s[MAXLEN];
    char t[MAXLEN];
    scanf("%s", s);
    scanf("%s", t);
    printf("%d", StrCompare(s,t));
    return 0;
}

int StrCompare(char s[],char t[]){
    int i;
    for(i=0;i<strlen(s)&&i<strlen(t);i++)
    {
        if(s[i]==t[i])
            ;
        else 
            return (s[i]>t[i])?1:-1;
    }
    if(s[i]=='\0'&&t[i]=='\0')
        return 0;
    else if(s[i]=='\0'&&t[i]!='\0')
        return -1;
    else
        return 1;

}