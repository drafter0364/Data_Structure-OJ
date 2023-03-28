/*2.15-链表合并
已知指针ha和hb分别指向两个单链表的头结点，
并且已知两个链表的长度分别为m和n。
试写一算法将这两个链表连接在一起（
即令其中一个表的首元节点连在另一个表的最后一个节点之后），
假设指针hc指向连接后的链表的头结点，并要求算法以尽可能短
的时间完成链接运算。*/

#include <stdio.h>
#include <stdlib.h>
typedef struct Lnode
{
    int data;
    struct Lnode *next;
} Lnode, LinkedList;

LinkedList *CreateList_L(int n);
LinkedList *MergeList_L(LinkedList *La, LinkedList *Lb);
int main()
{
    int m, n;
    scanf("%d %d", &m, &n);
    LinkedList *a;
    LinkedList *b;
    a = CreateList_L(m);
    b = CreateList_L(n);
    int c;
    LinkedList *g = a->next;
    do
    {
        scanf("%d", &(g->data));
        g = g->next;
    } while ((c = getchar()) != '\n');

    g = b->next;
    do
    {
        scanf("%d", &(g->data));
        g = g->next;
    } while ((c = getchar()) != '\n' && c != EOF);
    LinkedList *p;
    if (m < n)
        p = MergeList_L(a, b);
    else
        p = MergeList_L(b, a);
    for (p = p->next; (p->next) != NULL; p = p->next)
        printf("%d ", p->data);
    printf("%d", p->data);
    return 0;
}

LinkedList *CreateList_L(int n)
{
    LinkedList *L, *p;
    int i;
    L = (LinkedList *)malloc(sizeof(Lnode));
    L->next = NULL;
    for (i = n; i > 0; i--)
    {
        p = (LinkedList *)malloc(sizeof(Lnode));
        p->data = 0;
        p->next = L->next;
        L->next = p;
    }
    return L;
}

LinkedList *MergeList_L(LinkedList *La, LinkedList *Lb)
{
    LinkedList *Lc, *pa, *pb, *pc;
    pb = Lb->next;
    free(Lb);
    for (pa = La; pa->next != NULL; pa = pa->next)
        ;
    pa->next = pb;
    return La;
}