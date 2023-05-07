/*求距离两个二叉树节点最近的共同祖先*/

#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define ERROR 0

typedef int Status;
typedef char TElemType;
typedef struct BiTNode
{
    TElemType data;
    struct BiTNode *lchild, *rchild;
    struct BiTNode *parent;
} BiTree;

typedef BiTree *ElemType;

BiTree *CreateBiTree(BiTree *p);
BiTree *Find_node(BiTree *tree, char x);
BiTree *Ancestor(BiTree *a, BiTree *b);
int main()
{
    BiTree *t;
    t = CreateBiTree(NULL);
    getchar();
    char x, y;
    scanf("%c %c", &x, &y);
    BiTree *node_x;
    BiTree *node_y;
    node_x = Find_node(t, x);
    node_y = Find_node(t, y);
    // Ancestor(node_x,node_y);
    printf("%c", node_x->data);
    printf("%c", node_y->data);

    return 0;
}

BiTree *CreateBiTree(BiTree *p)
{
    BiTree *bt;
    TElemType x;
    scanf("%c", &x);
    if (x == '^')
        bt = NULL;
    else
    {
        bt = (BiTree *)malloc(sizeof(BiTree));
        if (!bt)
            return NULL;
        bt->data = x;
        bt->parent = p;
        bt->lchild = CreateBiTree(bt);
        bt->rchild = CreateBiTree(bt);
    }
    return bt;
}

BiTree *Find_node(BiTree *tree, char x)
{
    BiTree *node = NULL;
    if (tree == NULL)
        return NULL;
    if (tree->data == x)
    {
        return tree;
    }
    else
    {
        if (tree->data != x && tree->lchild)
        {
            node = Find_node(tree->lchild, x);
            if (node != NULL)
                return node;
        }
        if (tree->data != x && tree->rchild)
            node = Find_node(tree->rchild, x);
    }
    return node;
}

BiTree *Ancestor(BiTree *a, BiTree *b)
{
    BiTree *common_ancestor = NULL;
    BiTree *p = a->parent;
    BiTree *q = b->parent;
    while (p != NULL)
    {
        if (p->lchild && p->lchild == b || p->rchild && p->rchild == b)
        {
            common_ancestor = p;
            break;
        }
        else
        {
            p = p->parent;
        }
    }
    if (common_ancestor == NULL)
    {
        while (q != NULL)
        {
            if (q->lchild && q->lchild == a || q->rchild && q->rchild == a)
            {
                common_ancestor = q;
                break;
            }
            else
            {
                q = q->parent;
            }
        }
    }
    return common_ancestor;
}