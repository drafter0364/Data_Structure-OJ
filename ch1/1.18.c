// 田径对抗赛分数统计
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include <ctype.h>
#define MAXLEN 100
int mygetline(char s[], int lim);
int main()
{
    int totalscore[5];
    int femalescore[5];
    int malescore[5];
    int c;
    char s[MAXLEN];
    int i;
    int schoolname;
    int tempscore = 0;
    // 初始化数组
    for (i = 0; i < 5; i++)
        totalscore[i] = femalescore[i] = malescore[i] = 0;
    while (mygetline(s, MAXLEN) != 0)
    {
        if (s[2] == 'M')
        {
            malescore[s[4] - 'A'] += atoi(s + 6);
        }
        else if (s[2] == 'F')
        {
            femalescore[s[4] - 'A'] += atoi(s + 6);
        }
    }
    // 计算总分
    for (i = 0; i < 5; i++)
        totalscore[i] = malescore[i] + femalescore[i];
    // 打印结果
    for (i = 0; i < 5; i++)
    {
        if (malescore[i] > 0)
            printf("%c M %d\n", i + 'A', malescore[i]);
        if (femalescore[i] > 0)
            printf("%c F %d\n", i + 'A', femalescore[i]);
        if (totalscore[i] > 0)
            printf("%c %d\n", i + 'A', totalscore[i]);
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
