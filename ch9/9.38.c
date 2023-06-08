/*9.38 合并二叉排序树*/
#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
typedef int Status;
typedef int  TElemType;
typedef struct BiTNode {
    TElemType data;
    struct BiTNode* lchild, * rchild;
}BiTree,BiTNode;

BiTree* CreateBiTree();
void Bitree_merge(BiTree* s, BiTree* t);
void insert(BiTree* s, BiTNode *node);
Status InorderTraverse(BiTree* T, Status(*Visit)(TElemType e));
Status Visit(TElemType e);
int count = 1;
int main()
{
    BiTree* tree1;
    tree1=CreateBiTree();
    BiTree* tree2;
    tree2 = CreateBiTree();
    Bitree_merge(tree1, tree2);
    InorderTraverse(tree1,Visit);
    return 0;
}

BiTree* CreateBiTree() {
    BiTree* bt;
    TElemType x;
    scanf("%d", &x);
    if (x == -1) bt = NULL;
    else {
        bt = (BiTree*)malloc(sizeof(BiTree));
        if (!bt) return NULL;
        bt->data = x;
        bt->lchild = CreateBiTree();
        bt->rchild = CreateBiTree();
    }
    return bt;
}

void Bitree_merge(BiTree* s, BiTree* t) {
    if (t->lchild) {
        Bitree_merge(s, t->lchild);
    }
    if (t->rchild) {
        Bitree_merge(s, t->rchild);
    }
    insert(s, t);
}

void insert(BiTree* s, BiTNode* node) {
    if (node->data > s->data) {
        if (!s->rchild) {
            s->rchild = node;
        }
        else 
            insert(s->rchild, node);
    }
    else if (node->data < s->data) {
        if (!s->lchild) {
            s->lchild = node;
        }
        else
            insert(s->lchild, node);
    }
        node->lchild = node->rchild = NULL;
}

Status Visit(TElemType e) {
    if (count != 1)
        printf(" ");
    else
        count = 0;
    printf("%d", e);
    return 0;
}

Status InorderTraverse(BiTree* T, Status(*Visit)(TElemType e))
{
    if (T) {
        InorderTraverse(T->lchild, Visit);
        Visit(T->data);
        InorderTraverse(T->rchild, Visit);
    }
    return 0;
}