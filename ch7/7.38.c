/*7.38-有向无环图转逆波兰式*/
#include <stdio.h>
#define MAX_VEXNUM 20
typedef enum
{
    OP,
    ALP
} Nodekind;
typedef struct
{
    Nodekind kind;
    char vex;
    int next1;
    int next2;
} node;

void RPN(node g[], int vexnum, int vex);
int main()
{
    int vexnum;
    scanf("%d\n", &vexnum);
    char vex;
    int count = 0;
    node g[MAX_VEXNUM];
    int i, j;
    while (count < vexnum)
    {
        scanf("%c", &vex);
        g[count].vex = vex;
        if (vex == '+' || vex == '-' || vex == '*' || vex == '/')
        {
            g[count].kind = OP;
            getchar();
            scanf("%d %d", &i, &j);
            g[count].next1 = i;
            g[count].next2 = j;
            getchar();
        }
        else
        {
            g[count].kind = ALP;
            g[count].next1 = g[count].next1 = -1;
            g[count].next1 = g[count].next2 = -1;
            getchar();
        }
        count++;
    }
    RPN(g, vexnum, 0);
    return 0;
}

void RPN(node g[], int vexnum, int v0)
{
    if (g[v0].kind == OP)
    {
        RPN(g, vexnum, g[v0].next2);
        RPN(g, vexnum, g[v0].next1);
        printf("%c", g[v0].vex);
    }
    else
    {
        printf("%c", g[v0].vex);
    }
}