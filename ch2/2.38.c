/*2.38-双向循环链表访问
设有一双向循环链表，每个节点中除有prior,data和next三个域外，
还增设了一个访问频度域freq。在链表被启用之前，频度域freq的值均初始化为0，
而每当对链表进行一次LOCATE(L,x)的操作后，被访问的节点（即元素值等于x的节点）
中的频度域freq的值便增1，同时调整链表中节点之间的次序，使其按访问频度非递增
的次序顺序排列，以便始终保持被频繁访问的节点总是靠近表头结点。编写符合上述要
求的LOCATE操作的算法。*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *prior, *next;
    int freq;
} DoublyLinkedList;
DoublyLinkedList *CreateDoublyLinkedList(int n);
DoublyLinkedList *Locate(DoublyLinkedList *head, int e);
int sort(DoublyLinkedList *L, DoublyLinkedList *M, int order[], int len);
int lookup(int order[], int len, int e);
int main()
{
    int len;
    scanf("%d", &len);
    int order[len]; // 记录访问顺序
    int i;
    for (i = 0; i < len; i++)
        order[i] = 0;
    DoublyLinkedList *L, *RequestList;
    L = CreateDoublyLinkedList(len);
    int m, c;
    int icount = 0; // 记录访问过的元素个数（不计重复）
    DoublyLinkedList *pm;
    do
    {
        scanf("%d", &m);
        for (i = 0; i < icount; i++)
            if (m == order[i] && m != 0)
                break;
        if (i == icount)
        {
            order[icount] = m;
            icount++; // 记录下新访问的元素
        }

        if (pm = Locate(L, m))
        {
            pm->freq++;
            sort(L, pm, order, icount);
        }
    } while ((c = getchar()) != '\n');

    DoublyLinkedList *f = L->next;
    while (f->next != NULL)
    {
        printf("%d ", f->data);
        f = f->next;
    }
    printf("%d", f->data);
    return 0;
}

DoublyLinkedList *CreateDoublyLinkedList(int n)
{
    DoublyLinkedList *head, *p, *s;
    int i;
    // 创建头结点
    p = head = (DoublyLinkedList *)malloc(sizeof(DoublyLinkedList));
    for (i = 1; i <= n; i++)
    {
        s = (DoublyLinkedList *)malloc(sizeof(DoublyLinkedList));
        scanf("%d", &s->data);
        s->prior = p;
        s->freq = 0;
        p->next = s;
        p = s;
    }
    p->next = NULL;
    head->prior = NULL;
    return head;
}

DoublyLinkedList *Locate(DoublyLinkedList *head, int e)
{
    DoublyLinkedList *p;
    p = head->next; // p指向第一个结点
    while (p != NULL && p->data != e)
        p = p->next;
    return p;
}

int sort(DoublyLinkedList *L, DoublyLinkedList *pm, int order[], int len)
{
    DoublyLinkedList *p = pm->prior;
    DoublyLinkedList *q;
    while (p != L && p->freq < pm->freq && p->prior != NULL)
        p = p->prior;
    while (p->freq == pm->freq && lookup(order, len, p->data) > lookup(order, len, pm->data))
        p = p->prior;
    if (p->next != pm)
    {
        if (pm->next != NULL)
        {
            pm->prior->next = pm->next;
            pm->next->prior = pm->prior;
        }
        else
        {
            pm->prior->next = NULL;
        }
        q = p->next;
        p->next = pm;
        q->prior = pm;
        pm->next = q;
        pm->prior = p;
    }
    return 0;
}

int lookup(int order[], int len, int e)
{
    int i;
    for (i = 0; i < len; i++)
        if (order[i] == e)
            return i;
    return 0;
}
