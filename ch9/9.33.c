/*9.33-递归处理二叉排序树中关键字输出问题*/

#include <stdio.h> 
#define MAXLEN 25
int main()
{
    int c;
    int elem[MAXLEN];
    int i = 0;
    do {
        scanf("%d", &elem[i]);
        i++;
    } while ((c = getchar()) != '\n');
    int count = i;
    int first = 1;
    int a;
    scanf("%d", &a);
    for (i = count - 1; i >= 0; i--) {
        if (elem[i] >= a)
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