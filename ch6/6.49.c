/*6.49 判定完全二叉树*/

#include <stdio.h>
#include <stdlib.h>
#define MAXLEN 50
#define Status int
#define OK 1
#define ERROR 0
typedef struct BiTNode
{
    int elem;
    int lchild, rchild;
} BiTree;

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

Status GetFront(LinkedQueue *lq, int *e);
int IsQueueEmpty(LinkedQueue *lq);
Status InitQueue(LinkedQueue *lq);
Status Enqueue(LinkedQueue *lq, int e);
Status Dequeue(LinkedQueue *lq, int *e);
int main()
{
    int data;
    int state = 1;
    int twochild = 1;
    int count = 1;
    BiTree tree[MAXLEN];
    while ((data = getchar()) != EOF)
    {
        tree[count].elem = data;
        getchar();
        scanf("%d %d", &tree[count].lchild, &tree[count].rchild);
        getchar();
        count++;
    }
    LinkedQueue *lq = (LinkedQueue *)malloc(sizeof(LinkedQueue));
    InitQueue(lq);
    int head;
    if (tree[1].lchild == -1 && tree[1].rchild == -1)
    {
        printf("Yes");
        return 0;
    }
    Enqueue(lq, 1);
    int n = count;
    while (!IsQueueEmpty(lq) && state)
    {
        Dequeue(lq, &head);
        if (tree[head].lchild > 0 && tree[head].rchild > 0)
        {
            if (!twochild)
                state = 0;
            Enqueue(lq, tree[head].lchild);
            Enqueue(lq, tree[head].rchild);
        }

        else if (tree[head].lchild > 0 && tree[head].rchild == -1)
        {
            if (!twochild)
                state = 0;
            Enqueue(lq, tree[head].lchild);
            twochild = 0;
        }
        else if (tree[head].lchild == -1 && tree[head].rchild > 0)
        {
            state = 0;
        }
        else
        {
            twochild = 0;
        }
    }

    printf("%s", state ? "Yes" : "No");
    return 0;
}
Status GetFront(LinkedQueue *lq, int *e)
{
    if (lq->front == lq->rear)
        return ERROR;
    *e = lq->front->next->data;
    return OK;
}

int IsQueueEmpty(LinkedQueue *lq)
{
    if (lq->front == lq->rear)
        return 1;
    else
        return 0;
}

Status InitQueue(LinkedQueue *lq)
{
    lq->front = lq->rear = (QNode *)malloc(sizeof(QNode));
    if (!lq->front)
        return ERROR;
    lq->front->next = NULL;
    return OK;
}

Status Enqueue(LinkedQueue *lq, int e)
{
    QNode *p;
    p = (QNode *)malloc(sizeof(QNode));
    if (!p)
        return ERROR;
    p->data = e;
    p->next = NULL;
    lq->rear->next = p; // 修改尾指针
    lq->rear = p;
    return OK;
}

Status Dequeue(LinkedQueue *lq, int *e)
{
    QNode *p;
    if (lq->front == lq->rear)
        return ERROR;
    // 空队列的话，则出错
    p = lq->front->next; // p指向第一个结点
    *e = p->data;
    lq->front->next = p->next; // 修改头结点的指针
    if (lq->rear == p)         // 删仅有的一个元素时，需修改尾指针
        lq->rear = lq->front;  // 删成了空队列
    free(p);
    return OK;
}