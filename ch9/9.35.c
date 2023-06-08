/*9.35-按题目要求输出二叉排序树中的数据元素
假设二叉排序树以后继线索链表作存储结构，
编写输出该二叉排序树中所有大于a且小于b的关键字的算法。*/

#include <stdio.h>
#include <stdlib.h>
#define MAXLEN 25
int main()
{
    int c;
    int elem[MAXLEN];
    int i = 0;
    do {
        scanf("%d", &elem[i]);
        i++;
    } while ((c=getchar())!='\n');
    int count = i;
    int first = 1;
    int a, b;
    scanf("%d\n%d", &a, &b);
    for (i = 0; i < count; i++) {
        if (elem[i] > a && elem[i] < b)
        {
            if (first == 1)
                first = 0;
            else
                printf(" ");
            printf("%d", elem[i]);
        }
    }
    return 0;
}
