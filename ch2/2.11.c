#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100

typedef struct
{
    int *elem;
    int lenth;
    int listsize;
} SqList;
int InitList(SqList *L);
int ListInsert(SqList *L, int i, int e);
int main()
{

    int c;
    SqList *va=(SqList *)malloc(sizeof(SqList));
    InitList(va);
    int i = 0;
    do
    {
        scanf("%d",(*va).elem+i++);
        (*va).lenth++;
    }while((c=getchar())!='\n');
    scanf("%d", &c);
    for (i = 0; *((*va).elem + i) < c && i < (*va).lenth; i++)
        ;
    ListInsert(va, i, c);
    for (i = 0; i < (*va).lenth - 1; i++)
        printf("%d ", *((*va).elem + i));
    printf("%d", *((*va).elem + i));
    return 0;
}

int InitList(SqList *L)
{
    (*L).elem = (int *)malloc(MAXSIZE * sizeof(int));
    if (!(*L).elem)
        return 0;
    (*L).lenth = 0;
    (*L).listsize = MAXSIZE;
    return 0;
}

int ListInsert(SqList *L, int i, int e)
{
    int *p;
    int *q = (*L).elem+i;
    for (p = (*L).elem+(*L).lenth - 1; p >= q; --p)
        *(p + 1) = *p;
    *q = e;
    (*L).lenth++;
    return 0;
}