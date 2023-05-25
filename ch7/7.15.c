/*7.15-图的基本操作
试在邻接矩阵存储结构上实现图的基本操作：
InsertVex(G, v), InsertArc(G, v, w),
DeleteVex(G,v)和DeleteArc(G,v,w)*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX_VERTEX_NUM 20
#define MAX_WEIGHT 1000
typedef char ElemType;
typedef enum
{
    UDG,
    DG
} GraphKind;

typedef struct
{
    int vexnum; // 顶点数，边数
    GraphKind kind;
    ElemType vexs[MAX_VERTEX_NUM];         // 存放顶点信息
    int A[MAX_VERTEX_NUM][MAX_VERTEX_NUM]; // 存放边的信息
} MGraph;

int main()
{
    MGraph *g = (MGraph *)malloc(sizeof(MGraph));
    CreateGraph(g);
    int c;
    int a, b;
    int k, l;
    char operator[2];
    int addedvex;
    int deletedvex;

    do
    {
        scanf("%s", operator);
        if (strcmp(operator, "DA") == 0)
        {
            scanf("%d %d", &a, &b);
            g->A[a][b] = g->A[b][a] = 0;
        }
        else if (strcmp(operator, "DV") == 0)
        {
            scanf("%d", &deletedvex);
            for (k = 0; k < g->vexnum; k++)
                g->A[k][deletedvex] = -1;
            for (l = 0; l < g->vexnum; l++)
                g->A[deletedvex][l] = -1;
        }
        else if (strcmp(operator, "IV") == 0)
        {
            scanf("%d", &addedvex);
            for (k = g->vexnum - 1; k >= 0; k--)
            {
                for (l = g->vexnum - 1; l >= 0; l--)
                {
                    g->A[k + 1][l + 1] = g->A[k][l];
                    g->A[k][l] = 0;
                }
            }
            g->vexnum++;
        }
        else if (strcmp(operator, "IA") == 0)
        {
            scanf("%d %d", &a, &b);
            g->A[a][b] = g->A[b][a] = 1;
        }
    } while ((c = getchar()) != EOF);
    int count;
    for (k = 0; k < g->vexnum; k++)
    {
        count = 0;
        for (l = 0; l < g->vexnum; l++)
        {
            if (count != 0)
                printf(" ");
            if (g->A[k][l] != -1)
            {
                printf("%d", g->A[k][l]);
                count = 1;
            }
        }
        if (k != g->vexnum - 1 && count != 0)
            printf("\n");
    }

    return 0;
}

void CreateGraph(MGraph *g)
{
    int i, j, k, l;

    scanf("%d\n", &g->vexnum);
    for (k = 0; k < g->vexnum; k++)
        g->vexs[k] = '0' + k;
    for (i = 0; i < g->vexnum; i++)
        for (j = 0; j < g->vexnum; j++)
            g->A[i][j] = 0; // 初始化邻接矩阵

    for (k = 0; k < g->vexnum; k++)
    {
        for (l = 0; l < g->vexnum; l++)
        {
            scanf("%d", &(g->A[k][l]));
            getchar();
        }
    }
}
