/*10.39 有序序列归并*/
#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAXNUM 20
/*int main()
{
    int a[MAXNUM];
    int b[MAXNUM];
    char c;
    int i = 0;
    int max_a;
    int max_b;
    do {
        scanf("%d", &a[i]);
        i++;
    } while ((c = getchar()) != '\n');
    max_a = i;
    i = 0;
    do {
        scanf("%d", &b[i]);
        i++;
    } while ((c = getchar()) !=EOF);
    max_b = i;

    int p, q;
    p = q = 0;
    int first = 1;
    while (p < max_a && q < max_b) {
        if (!first)
            printf(" ");
        else
            first = 0;
        if (a[p] < b[q])
        {
            printf("%d", a[p]);
            p++;
        }
        else if (a[p] > b[q])
        {
            printf("%d", b[q]);
            q++;
        }
        else if (a[p] == b[q]) {
            printf("%d", a[p]);
            p++;
        }
    }

    if (p == max_a) {
        while (q<max_b)
        {
            if (!first)
                printf(" ");
            else
                first = 0;
            printf("%d", b[q]);
            q++;
        }
    }
    if (q == max_b) {
        while (p < max_a)
        {
            if (!first)
                printf(" ");
            else
                first = 0;
            printf("%d", a[p]);
            p++;
        }
    }
    return 0;
}*/


int a[10], b[10], c[10];
void main() {
    int i = 0, j = 0;
    char tempchar;
    scanf("%d", &a[i++]);
    tempchar = getchar();
    while (tempchar != '\n') {
        scanf("%d", &a[i++]);
        tempchar = getchar();
    }
    a[i] = -1;

    scanf("%d", &b[j++]);
    tempchar = getchar();
    while (tempchar != '\n') {
        scanf("%d", &b[j++]);
        tempchar = getchar();
    }
    b[j] = -1;

    int m = 0, n = 0, k = 0;
    for (; m < i && n < j; ) {
        if (a[m] <= b[n])c[k++] = a[m++];
        else c[k++] = b[n++];
    }
    if (m == i) {
        while (n < j)c[k++] = b[n++];
    }
    else if (n == j) {
        while (m < i)c[k++] = a[m++];
    }
    int t;
    for (t = 0; t < k - 1; t++) {
        printf("%d ", c[t]);
    }
    printf("%d", c[t]);
}

