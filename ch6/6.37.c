/*6.37 先序遍历的非递归形式*/

#include <stdio.h>
#define MAXLEN 50
typedef struct BiTNode
{
    char elem;
    int lchild, rchild;
} BiTree;


void PreorderTraverse(BiTree *tree, int root);

int main()
{
    char data;
    int count = 1;
    BiTree tree[MAXLEN];
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
    if (tree[root].lchild != -1)
        PreorderTraverse(tree, tree[root].lchild);
    if (tree[root].rchild != -1)
        PreorderTraverse(tree, tree[root].rchild);
}