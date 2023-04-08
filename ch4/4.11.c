/*4.11-删除字符
编写算法，求得所有包含在串s中而不包含在串t中的字符
（s中重复的字符只选一个）构成的新串r，以及r中每个字
符在s中第一次出现的位置。*/

#include <stdio.h>
#include <string.h>
#define MAXLEN 1000

int check(char ele, char t[]);
int main()
{
    char s[MAXLEN];
    char t[MAXLEN];
    char r[MAXLEN] = "";
    int location[MAXLEN];
    scanf("%s", s);
    scanf("%s", t);
    int i;
    int j = 0;
    for (i = 0; i < strlen(s); i++)
        if (!check(s[i], t) && !check(s[i], r))
        {
            r[j] = s[i];
            location[j] = i;
            j++;
        }
    if (r[0] == '\0')
        printf("-1");
    else
    {
        printf("%s ", r);
        for(i=0;i<strlen(r);i++)
            printf("%d",location[i]);
    }

    return 0;
}

int check(char ele, char t[])
{
    int i;
    for (i = 0; i < strlen(t); i++)
        if (t[i] == ele)
            return 1;
    return 0;
}