#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define INITSTRLEN 100
typedef struct HString
{
    char *ch;    // 若是非空串，则按串长度+1分配存储区
    int strsize; // 存储空间大小，包含串的结束符
    int length;  // 串长
} HString;
void init(HString *s, int lenth);
void GetNext(HString *pattern, int next[]);
int StrIndexKMP(HString *s, HString *t, int pos);
int main()
{
    HString *s = (HString *)malloc(sizeof(HString));
    HString *t = (HString *)malloc(sizeof(HString));
    int lenth1, lenth2;
    scanf("%d %d", &lenth1, &lenth2);
    getchar();
    init(s, lenth1);
    getchar();
    init(t, lenth2);
    int result;
    result=StrIndexKMP(s,t,1);
    printf("%d",result-1);
    return 0;
}

void init(HString *s, int lenth){
    s->length=lenth;
    s->ch=(char * )malloc(sizeof(char)*(lenth+1));
    s->strsize=sizeof(char)*(lenth+1);
    scanf("%s",s->ch);
    return ;
}
int StrIndexKMP(HString *s, HString *t, int pos)
{
    int next[INITSTRLEN];
    GetNext(t, next);
    int i, j;
    i = pos - 1;
    j = 0;
    while (i < s->length && j < t->length)
        if (j == -1 || s->ch[i] == t->ch[j])
        {
            i++;
            j++;
        }
        else
            j = next[j];
    if (j >= t->length)
        return i - t->length + 1;
    // 返回s中与t匹配的子序列第一个字符的序号
    else
        return 0; // 走到主串末尾，匹配失败
}

void GetNext(HString *pattern, int next[])
{
    int j, k;
    j = 0;  // j: 模式子串的位置
    k = -1; // k: 模式自匹配指针
    next[0] = -1;
    while (j < pattern->length)
        if (k == -1 || pattern->ch[j] == pattern->ch[k])
        {
            j++;
            k++;
            next[j] = k;
        }
        else
            k = next[k]; // 失配
}