/*8.15-可利用空间表*/
#include <stdio.h>
#define MAXLEN 20

int main()
{
    int highbound, lowbound;
    int size;
    int num;
    int tag[MAXLEN];
    scanf("%d %d %d\n", &highbound, &lowbound, &size);
    num = (lowbound - highbound) / size;
    int i;
    for (i = 0; i < num; i++)
    {
        scanf("%d", &tag[i]);
        getchar();
    }
    int count=0;
    int start;
    int space;
    int j;
    int flag=0;
    for (i = 0; i < num; i++)
    {
        if (tag[i] == 0)
        {
            flag = 1;
            start = highbound + i*size;
            for (j=i+1; j < num && tag[j] == 0; j++)
                ;
            space =  (j-i) * size;
            printf("%d %d %d\n", 0, start, space);
            i = j - 1;
        }
    }
    if (flag == 0)
    {
        printf("0 0 0");
    }
    return 0;
}