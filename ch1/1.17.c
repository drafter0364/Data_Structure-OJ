//k阶斐波那契数列
#include <stdlib.h>
#include <stdio.h>
#define MAXLEN 1000

int fib_k(int k, int m);
int mygetline(char s[], int lim);
int main()
{
    char s[MAXLEN];
    mygetline(s, MAXLEN);
    int k = 0, m = 0;
    int i;
    for (i = 0; i < MAXLEN && s[i] != ' ' && s[i] != '\n'; i++)
        k = k * 10 + s[i] - '0'; // 计算k的值
    ;
    for (i++; i < MAXLEN && s[i] != ' ' && s[i] != '\n'; i++)
        m = m * 10 + s[i] - '0'; // 计算m的值
    printf("%d", fib_k(k, m));    // 打印结果
    return 0;
}

int mygetline(char s[], int lim)
{
    int c, i = 0;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
        s[i++] = c;
    if (c == '\n')
    {
        s[i++] = c;
    }
    s[i] = '\0';
    return i;
}

int fib_k(int k, int m)
{
    int *p;
    p = (int *)malloc(sizeof(int) * (k + 1)); // 申请空间指向f0元素
    int i, j;
    if (m >= 0 && m < k - 1)
        return 0;
    else if (m == k - 1 || m == k)
        return 1;
    else
    {
        // 初始化前k项
        for (i = 0; i < k - 1; i++)
            *(p + i) = 0;
        *(p + i) = 1;
        *(p + k) = 0;
        for (i = 0; i < k; i++)
            *(p + k) += *(p + i);
        for (j = 0; j < m - k; j++) // 进行m-k次递推
        {
            for (i = 0; i < k; i++) // 更新前k项的值
                *(p + i) = *(p + i + 1);
            *(p + k) = 0;
            for (i = 0; i < k; i++)
                *(p + k) += *(p + i); // 公式
        }
        return *(p + k);
    }
}