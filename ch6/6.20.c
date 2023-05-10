/*6.20-二叉树的线索化*/

#include <stdio.h>

typedef struct BiTNode
{
    int elem;
    int lchild, rchild;
} BiTree;

void PreorderTraverse(BiTree *tree, int root, int preorder[]);
void InorderTraverse(BiTree *tree, int root, int inorder[]);
void PostorderTraverse(BiTree *tree, int root, int postorder[]);
int pre__preorder(int preorder[], int i, int n);
int pre__inorder(int inorder[], int i, int n);
int post__inorder(int inorder[], int i, int n);
int post__postorder(int postorder[], int i, int n);

int k = 0;
int main()
{
    int data;
    int count = 1;
    int n;
    scanf("%d", &n);
    int PreSequence[n];
    int InSequence[n];
    int PostSequence[n];
    BiTree tree[n + 1];
    int curr_root = 1; // 当前记录树的树根
    int appear[n];     // 记录是否在之前的输入出现
    int i;
    for (i = 0; i < n; i++)
        appear[i] = 0;

    do
    {
        scanf("%d", &data);
        tree[count].elem = data;
        if (appear[count - 1] == 0)
        {
            tree[curr_root].rchild = data;
            curr_root = data; // 更新当前树根
        }
        scanf("%d %d", &tree[count].lchild, &tree[count].rchild);
        // 记录下出现信息
        if (tree[count].lchild != 0)
            appear[tree[count].lchild - 1] = 1;
        if (tree[count].rchild != 0)
            appear[tree[count].rchild - 1] = 1;

        count++;
    } while ((getchar()) != EOF);
    PreorderTraverse(tree, 1, PreSequence);
    k = 0;
    InorderTraverse(tree, 1, InSequence);
    k = 0;
    PostorderTraverse(tree, 1, PostSequence);
    // 打印先序前驱线索化后的L数组
    printf("1");
    for (i = 1; i <= n; i++)
        printf(" %d", tree[i].lchild ? tree[i].lchild : pre__preorder(PreSequence, i, n));
    printf("\n");
    // 打印先序前驱线索化后的R数组
    printf("1");
    for (i = 1; i <= n; i++)
        printf(" %d", tree[i].rchild);
    printf("\n");

    // 打印中序全线索化前驱线索和后及线索后的L数组
    printf("1");
    for (i = 1; i <= n; i++)
        printf(" %d", tree[i].lchild ? tree[i].lchild : pre__inorder(InSequence, i, n));
    printf("\n");
    // 打印中序全线索化前驱线索和后及线索后的R数组
    printf("1");
    for (i = 1; i <= n; i++)
        printf(" %d", tree[i].rchild ? tree[i].rchild : post__inorder(InSequence, i, n));
    printf("\n");
    // 打印后序后驱线索化后的L数组
    printf("1");
    for (i = 1; i <= n; i++)
        printf(" %d", tree[i].lchild);
    printf("\n");
    // 打印后序后驱线索化后的R数组
    printf("1");
    for (i = 1; i <= n; i++)
        printf(" %d", tree[i].rchild ? tree[i].rchild : post__postorder(PostSequence, i, n));
    printf("\n");
    return 0;
}
void PreorderTraverse(BiTree *tree, int root, int preorder[])
{
    // printf("%d ", tree[root].elem);
    preorder[k++] = tree[root].elem;
    if (tree[root].lchild != 0)
        PreorderTraverse(tree, tree[root].lchild, preorder);
    if (tree[root].rchild != 0)
        PreorderTraverse(tree, tree[root].rchild, preorder);
}

void InorderTraverse(BiTree *tree, int root, int inorder[])
{

    if (tree[root].lchild != 0)
        InorderTraverse(tree, tree[root].lchild, inorder);
    inorder[k++] = tree[root].elem;
    if (tree[root].rchild != 0)
        InorderTraverse(tree, tree[root].rchild, inorder);
}
void PostorderTraverse(BiTree *tree, int root, int postorder[])
{

    if (tree[root].lchild != 0)
        PostorderTraverse(tree, tree[root].lchild, postorder);
    if (tree[root].rchild != 0)
        PostorderTraverse(tree, tree[root].rchild, postorder);
    postorder[k++] = tree[root].elem;
}

int pre__preorder(int preorder[], int i, int n)
{
    int j;
    for (j = 0; j < n; j++)
        if (preorder[j] == i)
            break;
    return preorder[j - 1];
}
int pre__inorder(int inorder[], int i, int n)
{
    int j;
    for (j = 0; j < n; j++)
        if (inorder[j] == i)
            break;
    return inorder[j - 1];
}

int post__inorder(int inorder[], int i, int n)
{
    int j;
    for (j = 0; j < n; j++)
        if (inorder[j] == i)
            break;
    return (j == n - 1) ? 0 : inorder[j + 1];
}
int post__postorder(int postorder[], int i, int n)
{
    int j;
    for (j = 0; j < n; j++)
        if (postorder[j] == i)
            break;
    return (j == n - 1) ? 0 : postorder[j + 1];
}
