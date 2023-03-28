/*2.18-链表删除元素
试写一算法，在无头节点的动态单链表上实现线性表操作DELETE(L,i)。*/

#include <stdio.h>
#include <stdlib.h>
typedef struct Lnode
{
    int num;
    int data;
    struct Lnode *next;
} Lnode, LinkedList;
LinkedList *Create();
LinkedList *delete(LinkedList *L, int i);
int main()
{
    int c;
    LinkedList *p;
    p = Create();
    scanf("%d", &c);
    if (c == 0)
        p = p->next;
    else
        delete (p, c);
    LinkedList *g;
    if (p == NULL)
    {
        printf("NULL");
        return 0;
    }
    for (g = p; g->next != NULL; g = g->next)
        printf("%d ", g->data);
    printf("%d", g->data);
    return 0;
}

LinkedList *Create()
{
    int c;
    LinkedList *L, *p, *g;
    int i = 0;
    L = (LinkedList *)malloc(sizeof(Lnode));
    L->next = NULL;
    L->num = i++;
    scanf("%d", &(L->data));
    c = getchar();
    if (c == '\n')
        return L;
    g = L;
    do
    {
        p = (LinkedList *)malloc(sizeof(Lnode));
        p->num = i++;
        scanf("%d", &(p->data));
        g->next = p;
        p->next = NULL;
        g = p;

    } while ((c = getchar()) != '\n');
    return L;
}

LinkedList *delete(LinkedList *L, int i)
{
    LinkedList *p, *f;
    for (p = L; p->next != NULL && (p->next)->num != i; p = p->next)
        ;
    f = p->next;
    p->next = f->next;
    free(f);
    return L;
}