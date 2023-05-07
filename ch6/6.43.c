/*6.43-二叉树左右子树交换*/

#include <stdio.h>
#define MAXLEN 100
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

    int temp;
    for (i = 1; i < n; i++)
    {
        temp = left[i];
        left[i] = right[i];
        right[i] = temp;
    }

    for (i = 0; i < n - 1; i++)
        printf("%d ", left[i]);
    printf("%d\n", left[i]);
    for (i = 0; i < n - 1; i++)
        printf("%d ", right[i]);
    printf("%d\n", right[i]);
    return 0;
}