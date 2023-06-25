// 6-crime.c

#define  _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#define MAXNUM 10
int main()
{
    int flag[MAXNUM];
    int i;
    for (i = 0; i < MAXNUM; i++) {
        flag[i] = -1;
    }
    int testnum;
    scanf("%d\n", &testnum);
    int casenum, infonum;
    scanf("%d %d\n", &casenum, &infonum);
    char c;
    int a, b;
    while ((scanf("%c %d %d\n",&c,&a,&b)) != EOF)
    {
        if (c == 'D') {
            if (flag[a] == -1 && flag[b] == -1) {
                flag[a] = 1;
                flag[b] = 0;
            }
            else if (flag[a] == -1 && flag[b] != -1) {
                flag[a] = flag[b]?0:1;
            }
            else if (flag[a] != -1 && flag[b] == -1) {
                flag[b] = flag[a] ? 0 : 1;
            }
        }
        else if (c == 'A') {
            if (flag[a] != -1 && flag[b] != -1) 
                printf("%s\n", (flag[a] == flag[b]) ? "是同一个团伙所为" : "不是同一个团伙所为");
            else
                printf("不确定\n");
        }
    }
    return 0;
}