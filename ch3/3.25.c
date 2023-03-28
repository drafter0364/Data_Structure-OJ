/*试写出求递归函数Ｆ(n)的递归算法，并消除递归:

F(n ) = n + 1 (n = 0)

F(n) = n * F(n / 2) (n > 0)*/

#include <stdio.h>

int main()
{
    int n;
    int result = 1;
    scanf("%d", &n);
    if (n < 0)
    {
        printf("wrong input");
        return 0;
    }
    while (n)
    {
        result *= n;
        n /= 2;
    }
    printf("%d", result);
    return 0;
}