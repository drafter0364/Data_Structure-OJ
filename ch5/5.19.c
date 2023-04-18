/*5.19查找矩阵中的马鞍点
若矩阵A(m*n)中的某个元素a是第i行中的最小值，同时又是第j列中的最大值，
则称此元素为该矩阵中的一个马鞍点。
假设以二维数组存储矩阵Ａ(m*n)，试编写求出矩阵中所有马鞍点的算法，并分
析你的算法在最坏情况下的时间复杂度。
*/

#include <stdio.h>

int main()
{
    int m, n; // m行，n列
    scanf("%d %d", &m, &n);
    int matrix[m][n];
    int i, j;
    int c;
    int row_sign = 0;
    i = j = 0;
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
    int p, q; // p行，q列
    int first = 1;
    for (p = q = 0; p < m && q < n;)
    {
        for (i = 0; i < m && matrix[i][q] <= matrix[p][q]; i++)
            ;
        for (j = 0; j < n && matrix[p][j] >= matrix[p][q]; j++)
            ;
        if (i == m && j == n)
        {
            if (!first)
                printf(" ");
            else
                first=0;
            printf("%d", matrix[p][q]);
        }
        if(q==n-1)
        {
            p++;
            q=0;
        }
        else 
            q++;
    }
    return 0;
}