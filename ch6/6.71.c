/*6.71 凹入表打印树结构*/

#include <stdio.h>
#define MAXLEN 50

typedef struct BiTNode
{
    int elem;
    int lchild, sibling;
} BiTree;
    
int Recessed_print(BiTree *tree, int i,int level);

int main()
{
    int data;
    int count = 1;
    BiTree tree[MAXLEN];
    while ((data = getchar()) != EOF)
    {
        tree[count].elem = data;
        getchar();
        scanf("%d %d", &tree[count].lchild, &tree[count].sibling);
        getchar();
        count++;
    }
    Recessed_print(tree,1,0);
    return 0;
}

int Recessed_print(BiTree *tree, int i,int level){
    int j;
    for(j=0;j<level;j++)
        printf("-");
    printf("%c\n",tree[i].elem);
    if(tree[i].lchild!=-1)
        Recessed_print(tree,tree[i].lchild,level+1);
    if(tree[i].sibling!=-1)
        Recessed_print(tree,tree[i].sibling,level);
    return 0;
}