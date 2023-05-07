/*6.51-二叉树与算术表达式*/

#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define ERROR 0
#define INITSIZE 100
#define INCREMENTSIZE 10 // 栈空间分配增量

typedef int Status;
typedef char TElemType;
typedef struct BiTNode
{
    TElemType data;
    struct BiTNode *lchild, *rchild;
} BiTree;

typedef BiTree *ElemType;

BiTree *CreateBiTree();
Status Visit(TElemType e);
Status InorderTraverse(BiTree *T, Status (*Visit)(TElemType e));

int main()
{
    BiTree *t;
    t = CreateBiTree();
    InorderTraverse(t, Visit);
    return 0;
}

BiTree *CreateBiTree()
{
    BiTree *bt;
    TElemType x;
    scanf("%c", &x);
    if (x == '#')
        bt = NULL;
    else
    {
        bt = (BiTree *)malloc(sizeof(BiTree));
        if (!bt)
            return NULL;
        bt->data = x;
        bt->lchild = CreateBiTree();
        bt->rchild = CreateBiTree();
    }
    return bt;
}

Status InorderTraverse(BiTree *T, Status (*Visit)(TElemType e))
{
    int bracketsign_front = 0;
    int bracketsign_after = 0;
    if (T)
    {
        if (T->data == '*' || T->data == '/')
        {
            if (T->lchild && T->lchild->data == '+' || T->lchild && T->lchild->data == '-')
            {
                printf("(");
                bracketsign_front = 1;
            }
        }
        InorderTraverse(T->lchild, Visit);
        if (bracketsign_front == 1)
            printf(")");
        Visit(T->data);
        if (T->data == '-')
        {
            if (T->rchild && T->rchild->data == '-' || T->rchild && T->rchild->data == '+')
            {
                printf("(");
                bracketsign_after = 1;
            }
        }
        else if (T->data == '/')
        {
            if (T->rchild && T->rchild->data == '*' || T->rchild && T->rchild->data == '/' || T->rchild && T->rchild->data == '+' || T->rchild && T->rchild->data == '-')
            {
                printf("(");
                bracketsign_after = 1;
            }
        }
        else if (T->data == '*')
        {
            if (T->rchild && T->rchild->data == '+' || T->rchild && T->rchild->data == '-')
            {
                printf("(");
                bracketsign_after = 1;
            }
        }

        InorderTraverse(T->rchild, Visit);
        if (bracketsign_after == 1)
            printf(")");
    }
    return OK;
}

Status Visit(TElemType e)
{
    printf("%c", e);
    return OK;
}
