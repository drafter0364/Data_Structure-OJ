/*6.33-二叉树子孙判断*/

#include <stdio.h>
#define MAXLEN 100

int if_child(int n, int L[], int R[], int child, int parent);
int main()
{
    int left[MAXLEN];
    int right[MAXLEN];
    int elem;
    int i = 0;
    do
    {
        scanf("%d", &elem);
        left[i++] = elem;
    } while ((getchar() != '\n'));
    int n = i;

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
    result = if_child(n, left, right, u, v);
    printf("%d", result);
    return 0;
}

int if_child(int n, int L[], int R[], int child, int parent)
{
    if (parent == L[0] && child != L[0])
        return 1;
    if (L[parent] == child || R[parent] == child)
        return 1;
    else if (L[parent] || R[parent])
    {
        if (!L[parent])
            if_child(n, L, R, child, L[parent]);
        if (!R[parent])
            if_child(n, L, R, child, R[parent]);
    }
    else
        return 0;
}