/*7.22-判断路径是否存在*/
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

int visited[MAX_VERTEX_NUM];

int main()
{
    int vexn;
    scanf("%d\n", &vexn);
    AGraph *g = (AGraph *)malloc(sizeof(AGraph));
    CreateGraph(g, vexn, 1);
    int i,j;
    scanf("%d,%d",&i,&j);
    DFS(g,i);
    if(visited[j]==1)
        printf("yes");
    else
        printf("no");
}

// 从第x个顶点出发递归地深度优先遍历图g
void DFS(AGraph *g, int x)
{
    NodeLink *p;
    visited[x] = 1;
    p = g->v[x].first;
    while (p)
    {
        if (!visited[p->vindex])
            DFS(g, p->vindex);
        p = p->next;
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