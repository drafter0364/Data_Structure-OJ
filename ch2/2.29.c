/*2.29-修改链表
已知A，B和C为三个递增有序的线性表，现要求对A表做如下操作：
删去那些既在B表中出现又在C表中出现的元素。
试对顺序表编写实现上述操作的算法*/

#include <stdio.h>
#include <stdlib.h>
typedef struct Lnode
{
    char data;
    struct Lnode *next;
} Lnode, LinkedList;
LinkedList *Create();
LinkedList *delete(LinkedList *L, char data);
int Lookup(LinkedList *L, char data);
int main()
{
    LinkedList *A, *B, *C;
    A = Create();
    B = Create();
    C = Create();
    LinkedList *pa = A->next, *pb = B->next, *pc = C->next; // 工作指针
    for (; pb != NULL && pc != NULL;)
    {
        if (pb->data == pc->data && Lookup(A, pb->data) == 0)
            delete (A, pb->data);
        else if (pb->data > pc->data)
            pc = pc->next;
        else
            pb = pb->next;
    }
    LinkedList *f = A->next;
    for (; f != NULL; f = f->next)
    {
        if (f->next == NULL)
            break;
        printf("%c,", f->data);
    }
    if (f != NULL)
        printf("%c", f->data);
    return 0;
}

// 创建链表，有头结点
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

        scanf("%c", &(p->data));
        g->next = p;
        p->next = NULL;
        g = p;

    } while ((c = getchar()) != '\n');
    return L;
}

int Lookup(LinkedList *L, char data)
{
    LinkedList *p = L->next;
    for (; p != NULL; p = p->next)
        if (p->data == data)
            return 0;
    return -1;
}

LinkedList *delete(LinkedList *L, char data)
{
    LinkedList *p = L->next;
    LinkedList *q = L;
    for (; p != NULL; p = p->next)
        if (p->data == data)
        {
            for (; q->next != p; q = q->next)
                ;
            q->next = p->next;
            free(p);
            return L;
        }
    return L;
}