/*3.28-队列实现
假设以带头结点的循环链表表示队列，
并且只设一个指针指向队尾元素结点(注意不设斗指针)，
试编写相应的队列初始化、入队列和出队列的算法*/

#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    struct Node *next;
} QNode;
typedef struct
{
    QNode *front;
    QNode *rear;
} LinkedQueue;
int CreateQueue(LinkedQueue *lq, int len);
int Enqueue(LinkedQueue *lq, int e);

int main()
{
    int m;
    scanf("%d", &m);
    LinkedQueue *lq = (LinkedQueue *)malloc(sizeof(LinkedQueue));
    CreateQueue(lq, m);
    QNode *f = lq->front->next;
    while (f != NULL)
    {
        if (f->next != NULL)
            printf("%d,", f->data);
        else
            printf("%d", f->data);
        f = f->next;
    }

    return 0;
}

int CreateQueue(LinkedQueue *lq, int len)
{
    lq->front = lq->rear = (QNode *)malloc(sizeof(QNode));
    if (!lq->front)
        return -1;

    int c;
    int e;
    do
    {
        scanf("%d", &e);
        Enqueue(lq, e);
    } while ((c = getchar()) != '\n');
    return 0;
}

int Enqueue(LinkedQueue *lq, int e)
{
    QNode *p;
    p = (QNode *)malloc(sizeof(QNode));
    if (!p)
        return -1;
    p->data = e;
    p->next = NULL;
    lq->rear->next = p; // 修改尾指针
    lq->rear = p;
    return 0;
}