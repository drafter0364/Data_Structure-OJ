/*7.14-构造邻接表*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX_VERTEX_NUM 30
typedef int ElemType;
typedef struct node
{
    int vindex;            // 邻接点在表头结点数组中的位置(下标)
    struct NodeLink *next; // 指向下一个表结点
} NodeLink;                // 表结点类型定义
typedef struct
{
    // 图的顶点数、边数、种类标志
    int vexnum, edgenum, kind;
    struct
    {
        ElemType vertex;
        NodeLink *first; // 指向第一个表结点
    } v[MAX_VERTEX_NUM];
} AGraph;
void CreateGraph(AGraph *g, int n, int m);
void ListGraph(AGraph *g, int start);
int main()
{
    int vexn, edgen;
    scanf("%d,%d\n", &vexn, &edgen);
    AGraph *g = (AGraph *)malloc(sizeof(AGraph));
    CreateGraph(g, vexn, 1);
    if (g->v[0].first == NULL)
        ListGraph(g, 1);
    else
        ListGraph(g, 0);
    return 0;
}

void ListGraph(AGraph *g, int start)
{
    int i;
    int k;
    int count;
    NodeLink *p;
    for (i = start; i < g->vexnum + start; i++)
    {
        int near[(g->vexnum) + 1];
        for (k = g->vexnum; k >= start; k--)
            near[k] = 0;
        printf("%d", g->v[i].vertex);
        if (g->v[i].first != NULL)
            printf(" ");
        p = g->v[i].first;
        while (p)
        {
            near[p->vindex] = 1;
            p = p->next;
        }
        count = 0;
        for (k = g->vexnum; k >= start; k--)
        {
            if (near[k])
            {
                if (count == 0)
                {
                    printf("%d", k);
                    count = 1;
                }
                else
                    printf(",%d", k);
            }
        }
        if (i != g->vexnum + start - 1)
            printf("\n");
    }
}

void CreateGraph(AGraph *g, int n, int m)
{
    int i, e = 0;
    int c;
    NodeLink *p, *q, *s;
    int x, y;
    g->vexnum = n;
    g->kind = m;
    for (i = 0; i < n + 1; i++)
    { // 初始化邻接表
        g->v[i].vertex = i;
        g->v[i].first = NULL;
    }
    do
    {
        scanf("%d-%d", &x, &y);
        e++;
        // 生成表结点并插入邻接表
        s = (NodeLink *)malloc(sizeof(NodeLink));
        s->vindex = y;
        if (g->v[x].first == NULL)
        {
            g->v[x].first = s;
            s->next = NULL;
        }
        else
        {
            p = g->v[x].first;
            q = p->next;
            while (q != NULL)
            {
                p = q;
                q = q->next;
            }
            p->next = s;
            s->next = q;
        }
        if (!g->kind)
        { // 无向图
            s = (NodeLink *)malloc(sizeof(NodeLink));
            s->vindex = x;
            if (g->v[y].first == NULL)
            {
                g->v[y].first = s;
                s->next = NULL;
            }
            else
            {
                p = g->v[y].first;
                q = p->next;
                while (q != NULL)
                {
                    p = q;
                    q = q->next;
                }
                p->next = s;
                s->next = q;
            }
        }
    } while ((c = getchar()) != '\n' && c != EOF);
    g->edgenum = e;
}