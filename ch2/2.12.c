/*2.12-顺序表比较
输入为两行，分别代表A和B中的元素，以逗号分开。
每个顺序表最多100个元素。
输出A和B的比较结果，0代表A=B，1代表A<B，2代表A>B*/


#include <stdio.h>
#define MAXISIZE 100
int main()
{
    char a[MAXISIZE];
    char b[MAXISIZE];
    int c;
    int i = 0;
    int result;
    // 读入A
    do
    {
        scanf("%c", &a[i]);
        if (a[i] == '\n')
        {
            a[i] = '\0';
            break;
        }
        i++;
    } while ((c = getchar()) != '\n');
    // 读入B
    i = 0;
    do
    {
        scanf("%c", &b[i]);
        if (b[i] == '\n')
        {
            b[i] = '\0';
            break;
        }
        i++;
    } while ((c = getchar()) != '\n' && c != EOF);
    if (a[0] == '\n' && b[0] != '\n')
    {
        printf("1");
        return 0;
    }
    else if (a[0] != '\n' && b[0] == '\n')
    {
        printf("2");
        return 0;
    }
    else
        ;
    for (i = 0; i < MAXISIZE && a[i] != '\0' && b[i] != '\0'; i++)
    {
        if (a[i] == b[i])
            ;
        else
        {
            result = (a[i] < b[i]) ? 1 : 2;
            break;
        }
    }
    if (a[i] == '\0' && b[i] != '\0')
        result = 1;
    else if (a[i] != '\0' && b[i] == '\0')
        result = 2;
    else if (a[i] == '\0' && b[i] == '\0')
        result = 0;
    else
        ;
    printf("%d", result);
    return 0;
}