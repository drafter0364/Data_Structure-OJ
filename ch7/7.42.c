/*7.42-Dijkstra算法*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX_VERTEX_NUM 20
#define INFINITY 1000
#define TRUE 1
typedef int ElemType;
typedef enum
{
    UDG,
    DG
} GraphKind;

typedef struct
{
    int vexnum; // 顶点数，边数
    GraphKind kind;
    ElemType vexs[MAX_VERTEX_NUM];            // 存放顶点信息
    int arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM]; // 存放边的信息
} MGraph;
void CreateMGragh(MGraph *g, int vexnum, int kind);
void ShortestPath_DIJ(MGraph *g, int v0, int P[][MAX_VERTEX_NUM], int dist[]);
int main()
{
    int vexnum;
    int startvex;
    scanf("%d %d\n", &vexnum, &startvex);
    MGraph *g = (MGraph *)malloc(sizeof(MGraph));
    CreateMGragh(g, vexnum, 1);
    int P[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
    int dist[MAX_VERTEX_NUM];
    ShortestPath_DIJ(g, startvex - 1, P, dist);
    int i;
    int count = 1;
    for (i = 0; i < vexnum; i++)
        if (i != (startvex - 1))
        {
            if (count == 1)
                count = 0;
            else
                printf(",");
            printf("%d", dist[i]);
        }
    return 0;
}

// 求有向网G的v0顶点到其余顶点v的最短路径P[v0][v]及其带权长度dist[v]
void ShortestPath_DIJ(MGraph *g, int v0, int P[][MAX_VERTEX_NUM], int dist[])
{
    int i = 0, j, v, w, min;
    int final[MAX_VERTEX_NUM];
    for (v = 0; v < g->vexnum; v++)
    { // 初始化
        final[v] = 0;
        dist[v] = g->arcs[v0][v];
        for (w = 0; w < g->vexnum; w++)
            P[v][w] = 0; // 设空路径
        if (dist[v] < INFINITY)
        {
            P[v][v0] = 1;
            P[v][v] = 1;
        }
    }
    dist[v0] = 0;
    final[v0] = 1; // 初始化，v0顶点属于S集
    // 主循环：每次求得v0到某个v顶点的最短路径并加v到S集合
    for (i = 1; i < g->vexnum; i++)
    {                   // 其余g->vexnum-1个顶点
        min = INFINITY; // 当前所知离v0顶点的最近距离
        for (w = 0; w < g->vexnum; w++)
            if (!final[w])         // w顶点在V-S中
                if (dist[w] < min) // w顶点离v0顶点更近
                {
                    v = w;
                    min = dist[w];
                }
        final[v] = 1; // 离v0顶点最近的v加入S集
        // 更新当前最短路径及距离
        for (w = 0; w < g->vexnum; w++)
            if (!final[w] && (min + g->arcs[v][w] < dist[w]))
            {
                // 对w∈V-S，修改dist[w]和P[w]
                dist[w] = min + g->arcs[v][w];
                for (j = 0; j < g->vexnum; j++)
                    P[w][j] = P[v][j];
                // 第v行赋值于第w行
                P[w][w] = TRUE; // P[w] = P[v]+[w]
            }                   // if
    }                           // for
} // ShortestPath_DIJ

void CreateMGragh(MGraph *g, int vexnum, int kind)
{
    int x, y, weight;
    g->kind = (kind) ? DG : UDG;
    g->vexnum = vexnum;
    int i, j, c;

    for (i = 0; i < MAX_VERTEX_NUM; i++)
    {
        g->vexs[i] = i + 1;
        for (j = 0; j < MAX_VERTEX_NUM; j++)
            g->arcs[i][j] = INFINITY;
    }

    do
    {
        scanf("%d-%d %d", &x, &y, &weight);
        g->arcs[x - 1][y - 1] = weight;

    } while ((c = getchar()) != EOF);
}