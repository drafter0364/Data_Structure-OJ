/*
试写一算法，识别依次读入的一个以@为结束符的字符序列是否为形如
“序列1&序列2”模式的字符序列。其中序列1和序列2中都不包含字符“&”，
且序列2是序列1的逆序列。例如，“a+b&b+a”是属于该模式的字符序列，
而“1+3&3-1”则不是
*/

#include <stdio.h>
#include <string.h>
#define MAXLEN 1000
int main()
{
    char s[MAXLEN];
    scanf("%s", s);
    int len = strlen(s);
    if (s[len-1] != '@'||len<2)
        printf("wrong input");
    else
    {
        if (s[len / 2 - 1] != '&')
        {
            printf("0");
            return 0;
        }
        int i;
        for (i = 0; i < len / 2 - 1; i++)
        {
            if (s[i] == s[len - i - 2] && s[i] != '&')
                ;
            else
            {
                printf("0");
                return 0;
            }
        }
        printf("1");
        return 0;
    }
}