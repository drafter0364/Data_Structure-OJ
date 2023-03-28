/*2.22-链表就地逆置*/
#include <stdio.h>
#include <stdlib.h>
typedef struct Lnode
{
    char data;
    struct Lnode *next;
} Lnode, LinkedList;
LinkedList *Create();
int main()
{
    LinkedList *L;
    L = Create();
    int i = 0;
    LinkedList *bottom, *head,*p;
    bottom = L->next;
    for (head= L->next;head->next != NULL; head = head->next)
        i++;
    L->next=head;
    while (i--)
    {
        for(p=bottom;p!=NULL&&p->next!=head;p=p->next)
            ;
        head->next=p;
        head=p;   
    }
    head->next=NULL;

    LinkedList *f = L->next;
    while (f->next != NULL)
    {
        printf("%c,", f->data);
        f = f->next;
    }
    printf("%c", f->data);
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

        scanf("%c", &(p->data));
        g->next = p;
        p->next = NULL;
        g = p;

    } while ((c = getchar()) != '\n');
    return L;
}