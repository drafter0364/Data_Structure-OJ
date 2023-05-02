/*6.34-二叉树父子结点判断*/

#include <stdio.h>
#define MAXLEN 100

int if_child(int T[], int child, int parent);
int main()
{
    int t[MAXLEN];
    int left[MAXLEN];
    int right[MAXLEN];
    int elem;
    int i = 0;
    do
    {
        scanf("%d", &elem);
        t[i++] = elem;
    } while ((getchar() != '\n'));

    i = 0;

    do
    {
        scanf("%d", &elem);
        left[i++] = elem;
    } while ((getchar() != '\n'));

    i = 0;
    do
    {
        scanf("%d", &elem);
        right[i++] = elem;
    } while ((getchar() != '\n'));

    int u;
    int v;
    scanf("%d %d", &u, &v);
    int result;
    i = 1;
    while (t[i] != 0)
    {
        i = t[i];
    }
    left[0] = right[0] = i;
    if (v == i && u != v)
        printf("1");
    else if (u == v)
        printf("0");
    else
    {
        result = if_child(t, u, v);
        printf("%d", result);
    }
    return 0;
}

int if_child(int t[], int child, int parent)
{

    int i = child;
    while (t[i] != parent && t[i])
    {
        i = t[i];
    }
    if (!t[i])
        return 0;
    else
        return 1;
}
