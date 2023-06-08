/*9.29-有序表查找*/
#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAXLEN 25
int main()
{
    int t = 0;
    int h = 0;
    int c;
    int elem[MAXLEN];
    int i = 0;
    do {
        scanf("%d", &elem[i]);
        i++;
    } while ((c = getchar()) != '\n');
    int lenth = i;
    int tofind[MAXLEN];
    i = 0;
    do {
        scanf("%d", &tofind[i]);
        i++;
    } while ((c = getchar()) != EOF && c!='\n');
    int max = i;
    int k ;
    for (k = 0; k < max; k++) {
        h = t;
        if (tofind[k] == elem[t])
        {
            tofind[k] = 1;
            continue;
        }
        for (h++; h < lenth; h++)
        {
            if (tofind[k] == elem[h])
            {
                tofind[k] = 1;
                break;
            }
        }
        if (h == lenth)
            tofind[k] = 0;
    }
    int first = 1;
    for (i = 0; i < max; i++) {
        
            if (first == 1)
                first = 0;
            else
                printf(" ");
            printf("%d", tofind[i]);
        
    }
    return 0;
}
