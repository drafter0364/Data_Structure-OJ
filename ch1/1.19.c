#include <stdio.h>
#include <math.h>
int factorial(int x);
int main()
{
    int n;
    int arrsize;
    scanf("%d %d", &n, &arrsize);
    if (n <= 0 || arrsize <= 0 || n > 11 || arrsize > 20 || n > arrsize)
    {
        printf("-1");
        return 0;
    }
    long int a[arrsize];
    long int temp;
    int i;
    for (i = 0; i < n; i++)
    {
        temp =(long int) factorial(i) * (long int)pow(2, i);
        a[i] = temp;
    }
    for (; i < arrsize; i++)
        a[i] = 0;
    for (i = 0; i < n-1; i++)
        printf("%lld ", a[i]);
    printf("%lld",a[i]);
    return 0;
}

int factorial(int x)
{
    int temp = x;
    int result = x;
    if (x == 0)
        return 1;
    else
    {
        while (--temp)
            result *= temp;
        return result;
    }
}
