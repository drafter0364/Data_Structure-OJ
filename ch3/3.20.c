/*3.20-图像区域颜色置换
 */

#include <stdio.h>

int main()
{
    int m, n, start_row, start_col, start_dirc;
    scanf("%d %d %d %d %d\n", &m, &n, &start_row, &start_col, &start_dirc);
    int g[m][n];
    int i, j;
    int c;
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
        {
            scanf("%d", &c);
            if (c == 0)
                g[i][j] = 0;
            else if (c == 1)
                g[i][j] = 2;
            getchar();
        }
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
            printf("%d", g[i][j]);
        printf("\n");
    }
    return 0;
}