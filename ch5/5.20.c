/*5.20-将数组表示的多项式的形式输出*/

#include <stdio.h>

int main()
{
    int m, n;
    scanf("%d %d", &m, &n);
    int matrix[m][n];
    getchar();
    int i, j;
    i = j = 0;
    int c;
    do
    {
        scanf("%d", &c);
        matrix[i][j] = c;
        getchar();
        if (j == n - 1)
        {
            i++;
            j = -1;
        }
        j++;
    } while (i < m && j < n);
    int first = 1;
    for (i = m - 1; i >= 0; i--)
    {
        for (j = n - 1; j >= 0; j--)
        {
            if (matrix[i][j] != 0)
            {
                if (first == 1)
                {
                    first = 0;
                }
                else
                    printf("+");
                if (matrix[i][j] != 1)
                    printf("%d", matrix[i][j]);
                if (i != 0 && j != 0)
                    printf("xE%dyE%d", i, j);
                else if (i == 0 && j != 0)
                    printf("yE%d", j);
                else if (i != 0 && j == 0)
                    printf("xE%d", i);
            }
        }
    }
}