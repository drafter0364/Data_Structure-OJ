/*7.36-求最长路径长度*/

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
        int MPL;
        int number;
    } v[MAX_VERTEX_NUM];
} AGraph;

void CreateGraph(AGraph *g, int n, int m);
void SL(AGraph *g, int x);
int FirstAdjVex(AGraph *g, int x);
int NextAdjVex(AGraph *g, int x, int y);
int visited[MAX_VERTEX_NUM];
int order[MAX_VERTEX_NUM];
int output = 0;

int main()
{
    int vexn;
    scanf("%d\n", &vexn);
    AGraph *g = (AGraph *)malloc(sizeof(AGraph));
    CreateGraph(g, vexn, 1);
    int count = vexn;
    int i;
    while (count)
    {
        for (i = 0; i < MAX_VERTEX_NUM; i++)
            visited[i] = order[i] = g->v[i].number = 0;
        SL(g, count);
        count--;
    }
    count = 1;
    while (count <= vexn)
    {
        if (count != 1)
            printf(",");
        printf("%d", g->v[count].MPL);
        count++;
    }

    return 0;
}

// 从第x个顶点出发找最长路径
void SL(AGraph *g, int x)
{
    // 设置辅助队列q,保存访问vi的相邻接的顶点
    int q[MAX_VERTEX_NUM], front, rear;
    int v1;
    int position = 1;
    front = rear = 0;
    q[rear++] = x;
    int vex;
    int k = 0;
    while (front != rear)
    {
        // 顶点出队列，并访问它
        vex = q[front++];
        int count = 0;
        for (v1 = FirstAdjVex(g, vex); v1 >= 0; v1 = NextAdjVex(g, vex, v1))
        {
            q[rear++] = v1;
            if (count == 0 && (g->v[vex].number + 1) > g->v[x].MPL)
                g->v[x].MPL++;
            else
                count = 1;
            g->v[v1].number = g->v[x].MPL;
        }
    }
}
// 返回顶点x的第一个邻接顶点
int FirstAdjVex(AGraph *g, int x)
{
    NodeLink *p;
    p = g->v[x].first;
    if (p)
        return p->vindex;
    else
        return -1;
}

// 返回顶点x的(相对于y的)下一个邻接顶点
int NextAdjVex(AGraph *g, int x, int y)
{
    if (x == -1)
        return -1;
    NodeLink *p = g->v[x].first;
    NodeLink *q = NULL;
    while (p != NULL && p->vindex != y)
        p = p->next;
    if (p != NULL && p->next != NULL)
    {
        q = p->next;
        return q->vindex;
    }
    return -1;
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
        g->v[i].MPL = 0;
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