/*5.25. 稀疏矩阵加法
 */

#include <stdio.h>
#include <stdlib.h>
int main()
{
    int m, n;
    scanf("%d %d", &m, &n);
    int B1[m][n];
    int B2[m][n];
    int c;
    int v1[m * n];
    int v2[m * n];
    int v3[m * n];
    int i;
    int vp = 0;
    for (i = 0; i < m * n; i++)
        v1[i] = v2[i] = v3[i] = 0;
    getchar();
    if ((c = getchar()) != '\n')
    {
        ungetc(c, stdin);
        do
        {
            scanf("%d", v1 + vp);
            vp++;
        } while ((c = getchar()) != '\n'); // 扫描V1数组
    }
    int j;
    i = j = 0;
    do
    {
        scanf("%d", &c);
        B1[i][j] = c;
        getchar();
        if (j == n - 1)
        {
            i++;
            j = -1;
        }
        j++;
    } while (i < m && j < n); // 扫描B1矩阵
    vp = 0;
    if ((c = getchar()) != '\n')
    {
        ungetc(c, stdin);
        do
        {
            scanf("%d", v2 + vp);
            vp++;
        } while ((c = getchar()) != '\n');
    } // 扫描V2数组
    i = j = 0;
    do
    {
        scanf("%d", &c);
        B2[i][j] = c;
        if (i != m - 1 || j != n - 1)
            getchar();
        if (j == n - 1)
        {
            i++;
            j = -1;
        }
        j++;
    } while (i < m && j < n);   // 扫描B2矩阵
    int count1, count2, count3; //
    count1 = count2 = count3 = 0;

    for (i = 0, j = 0; i < m && j < n;)
    {
        if (B1[i][j] && B2[i][j])
        {
            v3[count3] = v1[count1] + v2[count2];
            count1++;
            count2++;
            if (v3[count3] != 0)
                count3++;
            else
                B1[i][j] = 0;
        }
        else if (B1[i][j] && !B2[i][j])
        {
            v3[count3] = v1[count1];
            count1++;
            count3++;
        }
        else if (!B1[i][j] && B2[i][j])
        {
            v3[count3] = v2[count2];
            count2++;
            count3++;
            B1[i][j] = 1;
        }
        // 循环迭代
        if (j == n - 1)
        {
            i++;
            j = -1;
        }
        j++; 
    }
    for (i = 0; v3[i] != 0&&i<m*n; i++)
    {
        if (i != 0)
            printf(" ");
        printf("%d", v3[i]);
    }
    printf("\n");
    for (i = j = 0; i < m && j < n;)
    {
        if (j != 0)
            printf(" ");
        printf("%d", B1[i][j]);
        if (i != m - 1 && j == n - 1)
            printf("\n");
        // 循环迭代
        if (j == n - 1)
        {
            i++;
            j = -1;
        }
        j++;
    }

    return 0;
}