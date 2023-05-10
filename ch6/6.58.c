/*6.58-线索二叉树插入
描述
试写一个算法，在中序全线索二叉树的节点*p之下，
插入一棵以节点*x为根，只有左子树的中序全线索二叉树，
使*x为根的二叉树成为*p的左子树。若*p原来有左子树，则令它为*x的右子树。
完成插入之后的二叉树应保持全线索化的特性。*/

#include <stdio.h>
#define MAXLEN 100
typedef struct BiTNode
{
    char elem;
    int lchild, rchild;
} BiTree;

void InorderTraverse(BiTree *tree, int root);
void plugin(BiTree *tree, int root, char p, BiTree *x);

char output[MAXLEN];
int point = 1;
int main()
{
    char data;
    int count;
    BiTree tree[MAXLEN];
    BiTree x[MAXLEN];
    for (count = 0; count < MAXLEN; count++)
    {
        tree[count].elem = x[count].elem = count + '0';
        tree[count].lchild = x[count].lchild = tree[count].rchild = x[count].rchild = 0;
    }
    count = 1;
    getchar();
    getchar();
    do
    {
        scanf("%c", &data);
        tree[count++].lchild = data - '0';
    } while ((getchar() != '\n'));
    count = 1;
    getchar();
    getchar();
    do
    {
        scanf("%c", &data);
        tree[count++].rchild = data - '0';
    } while ((getchar() != '\n'));
    char p;

    scanf("%c", &p);

    // 读入x
    char x_root;
    getchar();
    scanf("%c", &x_root);
    getchar();
    count = 1;
    do
    {
        scanf("%c", &data);
        x[count].elem = count + x_root - 1;
        if (data != '0')
            x[count].lchild = data - x_root + 1;
        else
            x[count].lchild = 0;
        count++;
    } while ((getchar() != '\n'));
    count = 1;
    getchar();
    getchar();
    do
    {
        scanf("%c", &data);
        if (data != '0')
            x[count].rchild = data - x_root + 1;
        else
            x[count].rchild = 0;
        count++;
    } while (getchar() != EOF);
    plugin(tree, 1, p, x);
    printf("%c", output[1]);
    int i;
    for (i = 2; i < point; i++)
        printf(" %c", output[i]);
    return 0;
}

void InorderTraverse(BiTree *tree, int root)
{

    if (tree[root].lchild != 0)
        InorderTraverse(tree, tree[root].lchild);
    // printf("%c ", tree[root].elem);
    output[point++] = tree[root].elem;
    if (tree[root].rchild != 0)
        InorderTraverse(tree, tree[root].rchild);
}

void plugin(BiTree *tree, int root, char p, BiTree *x)
{
    if (tree[root].elem == p)
    {
        InorderTraverse(x, 1);
        if (tree[root].lchild != 0)
            InorderTraverse(tree, tree[root].lchild);
        // printf("%c ", tree[root].elem);
        output[point++] = tree[root].elem;

        if (tree[root].rchild != 0)
            InorderTraverse(tree, tree[root].rchild);
    }
    else
    {
        if (tree[root].lchild != 0)
            plugin(tree, tree[root].lchild, p, x);

        // printf("%c ", tree[root].elem);
        output[point++] = tree[root].elem;

        if (tree[root].rchild != 0)
            plugin(tree, tree[root].rchild, p, x);
    }
}