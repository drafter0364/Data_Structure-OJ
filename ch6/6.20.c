/*6.20-二叉树的线索化*/

#include <stdio.h>

typedef struct BiTNode
{
    int elem;
    int lchild, rchild;
} BiTree;

void PreorderTraverse(BiTree *tree, int root);

int main()
{
    int data;
    int count = 1;
    int n;

    scanf("%d", &n);
    int PreSequence[n];
    BiTree tree[n];
    while ((data = getchar()) != EOF)
    {
        tree[count].elem = data;
        scanf("%d %d\n", &tree[count].lchild, &tree[count].rchild);
        count++;
    }
    PreorderTraverse(tree, 1);
    return 0;
}

void PreorderTraverse(BiTree *tree, int root)
{
    printf("%c ", tree[root].elem);
    if (tree[root].lchild != 0)
        PreorderTraverse(tree, tree[root].lchild);
    if (tree[root].rchild != 0)
        PreorderTraverse(tree, tree[root].rchild);
}