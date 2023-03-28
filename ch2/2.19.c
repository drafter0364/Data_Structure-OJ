/*2.19-链表删除指定范围的元素
已知线性表中的元素以递增有序排列，并以单链表为存储结构。试写一高效算法，删除表中所有值大于mink且小于maxk的元素（若表中存在这样的元素），同时释放被删节点的空间。

注意：mink和maxk是给定的两个参变量，他们的值可以和表中的元素相同，也可以不同。*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Lnode
{
    int data;
    struct Lnode *next;
} Lnode, LinkedList;
LinkedList *Create();
LinkedList *delete_con(LinkedList *L, int min, int max);
int main()
{
    LinkedList *L;
    L = Create();
    LinkedList *p;
    int m, n;
    scanf("%d %d", &m, &n);
    delete_con(L, m, n);
    for (p = L->next; p != NULL && p->next != NULL; p = p->next)
        printf("%d ", p->data);
    printf("%d", p->data);
    return 0;
}

LinkedList *Create()
{
    int c;
    LinkedList *L, *p, *g;

    L = (LinkedList *)malloc(sizeof(Lnode));
    L->next = NULL;
    g = L;
    do
    {
        p = (LinkedList *)malloc(sizeof(Lnode));

        scanf("%d", &(p->data));
        g->next = p;
        p->next = NULL;
        g = p;

    } while ((c = getchar()) != '\n');
    return L;
}

LinkedList *delete_con(LinkedList *L, int min, int max)
{
    LinkedList *p, *g, *f;
    for (p = L->next; p != NULL && p->data <= min; p = p->next)
        ;
    for (g = L; g != NULL && g->next != NULL && g->next != p; g = g->next)
        ;
    while (p != NULL && p->data < max)
    {
        f = p;
        p = p->next;
        free(f);
    }
    g->next = p;
    return L;
}