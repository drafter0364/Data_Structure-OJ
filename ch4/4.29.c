/*4.29-串匹配的改进算法*/
/*假设以结点大小为1（带头结点）的链表结构表示串，则在利用next函数值进行
串匹配时，在每个结点中需设三个域：数据域chdata、指针域succ和指针域next。
其中chdata域存放一个字符；succ域存放指向同一链表中后继结点的指针；next
域在主串中存放指向同一链表中前驱结点的指针；在模式串中，存放指向当该结点
的字符与主串中的字符不等时，在模式串中下一个应进行比较的字符结点（即与该
字符的next函数值相对应的字符结点）的指针，若该节点字符的next函数值为0，
则其next域的值应指向头结点。试按上述定义的结构改写串匹配的改进算法（KMP
算法）*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define CHUNKSIZE 1
#define INITSTRLEN 100
typedef struct Chunk
{
    char ch[CHUNKSIZE];
    struct Chunk *succ; // 后继
    struct Chunk *next; // 前驱
} Chunk;

typedef struct
{
    Chunk *head, *tail; // 头尾指针
    int length;         // 当前长度
} LString;

void init(LString *s, int lenth);
Chunk *Getchunk(LString *s, int i);
int StrIndexKMP(LString *s, LString *t, int pos);
void GetNext(LString *pattern, int next[]);

int main()
{
    int lenth1,lenth2;
    scanf("%d %d",&lenth1,&lenth2);
    getchar();
    LString *s = (LString *)malloc(sizeof(LString));
    LString *pattern = (LString *)malloc(sizeof(LString));
    init(s,lenth1);
    getchar();
    init(pattern,lenth2);
    int result;
    result=StrIndexKMP(s,pattern,1);
    printf("%d",result);
    return 0;
}

void init(LString *s, int lenth)
{
    s->length=lenth;
    s->tail = s->head = (Chunk *)malloc(sizeof(Chunk));
    s->head->succ = s->tail->succ = s->head->next = s->tail->next = NULL;
    Chunk *p, *q;
    p = s->head;
    int i;
    int count = 0;
    char c;
    for (i = 0; i < lenth; i++)
    {

        q = (Chunk *)malloc(sizeof(Chunk));
        q->next = p;
        q->succ = NULL;
        p->succ = q;
        p = q;
        s->tail = p;
        scanf("%c", &c);
        p->ch[0] = c;
    }
}

int StrIndexKMP(LString *s, LString *t, int pos)
{
    int next[INITSTRLEN];
    GetNext(t, next);
    int i, j;
    Chunk *p = s->head->succ, *q = t->head->succ;
    i = pos - 1;
    j = 0;
    while (p->succ != NULL && q->succ != NULL)
        if (q == s->head || p->ch[0] == q->ch[0])
        {
            p = p->succ;
            q = q->succ;
            i++;
            j++;
        }
        else
            q = Getchunk(t, next[j]);
    if (q->succ == NULL)
        return i - t->length + 1;
    // 返回s中与t匹配的子序列第一个字符的序号
    else
        return -1; // 走到主串末尾，匹配失败
}

void GetNext(LString *pattern, int next[])
{
    int j, k;
    Chunk *p = pattern->head->succ;//j
    if (p == NULL)
        return;
    j = 0;  // j: 模式子串的位置
    k = -1; // k: 模式自匹配指针
    Chunk *q = pattern->head;//k
    next[0] = -1;
    while (j < pattern->length)
        if (k==-1 || p->ch[0] == q->ch[0])
        {
            j++;
            k++;
            p = p->succ;
            q = q->succ;
            next[j] = k;
        }
        else
            k = next[k]; // 失配
}

Chunk *Getchunk(LString *s, int i)
{
    Chunk *p = s->head->succ;
    while (i--)
    {
        p = p->succ;
    }
    return p;
}