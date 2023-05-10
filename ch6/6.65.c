/*6.65-建立二叉树链表
已知一棵二叉树的前序序列和中序序列分别存于两个一维数组中，
试编写算法建立该二叉树的二叉链表，然后输出该二叉链表的后序序列。*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXLEN 50
typedef struct BiTNode
{
    char elem;
    struct BiTNode *lchild, *rchild;
} BiTree;

BiTree *buildbtree(char *pre, char *in, int n);
void PostOrderTranverse(BiTree *T);
int main()
{
    char preoder[MAXLEN];
    char inoder[MAXLEN];
    scanf("%s", preoder);
    scanf("%s", inoder);
    BiTree *btree = (BiTree *)malloc(sizeof(BiTree));
    btree = buildbtree(preoder, inoder, strlen(preoder));
    PostOrderTranverse(btree);
    return 0;
}

BiTree *buildbtree(char *pre, char *in, int n)
{
    BiTree *node;
    char *p;
    if (n <= 0)
        return NULL;
    node = (BiTree *)malloc(sizeof(BiTree));
    node->elem = *pre;
    // 在in中找 *pre
    for (p = in; p < in + n; p++)
    {
        if (*p == *pre)
            break;
    }
    int leftnum;
    leftnum = p - in; // b节点的左子树节点数
    node->lchild = buildbtree(pre + 1, in, leftnum);
    node->rchild = buildbtree(pre + leftnum + 1, p + 1, n - leftnum - 1);
    return node;
}

void PostOrderTranverse(BiTree *T) // 后序遍历
{
    if (T == NULL)
        return;
    else
    {
        PostOrderTranverse(T->lchild);
        PostOrderTranverse(T->rchild);
        printf("%c", T->elem);
    }
}
