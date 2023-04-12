/*4.23-串的对称性判断
假设以块链结构作串的存储结构。
试编写判别给定串是否具有对称性的算法，
并要求算法的时间复杂度为O(StrLength(S))。*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define CHUNKSIZE 1

typedef struct Chunk
{
    char ch[CHUNKSIZE];
    struct Chunk *next;

} Chunk;

typedef struct
{
    Chunk *head, *tail; // 头尾指针
    int curlen;         // 当前长度
} LString;

int check(LString *s, int lenth);
Chunk *pre(LString *s, Chunk *p);
int main()
{
    LString *s = (LString *)malloc(sizeof(LString));
    s->tail = s->head = (Chunk *)malloc(sizeof(Chunk));
    s->head->next = s->tail->next = NULL;
    Chunk *p, *q;
    p = s->head;
    int lenth;
    scanf("%d", &lenth);
    getchar();
    int i;
    int count = 0;
    char c;
    for (i = 0; i < lenth; i++)
    {
        if (count > CHUNKSIZE-1)
        {
            q = (Chunk *)malloc(sizeof(Chunk));
            q->next = NULL;
            p->next = q;
            p = q;
            count = 0;
            s->tail = p;
        }
        scanf("%c", &c);
        p->ch[count++] = c;
    }
    check(s, lenth);
    return 0;
}

int check(LString *s, int lenth)
{
    Chunk *p = s->head;
    Chunk *q = s->tail;
    int count1, count2;
    count1 = 0, count2 = (lenth%CHUNKSIZE)?lenth%CHUNKSIZE-1:CHUNKSIZE-1;
    int time=lenth/2;
    while (time--)
    {
        if (p->ch[count1] == q->ch[count2])
        {
            count1++;count2--;
            if(count1==CHUNKSIZE)
                p=p->next;
            if(count2<0)
                q=pre(s,q);
            count1=0;
            count2=CHUNKSIZE-1;
        }
        else
        {
            printf("0");
            return 0;
        }
    }
    printf("1");
    return 0;
}

Chunk *pre(LString *s, Chunk *p)
{
    Chunk *q;
    for (q = s->head; q->next != p; q = q->next)
        ;
    return q;
}