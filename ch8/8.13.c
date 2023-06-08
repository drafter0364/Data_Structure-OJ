/*8.13-边界标志法*/
#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAXLEN 20
typedef struct node {
    int tag;
    int startaddr;
    int size;
}node;
node s[MAXLEN];

int plugin(node s[], int startaddr, int size);
void forward(node s[],int stride, int start);

int main()
{
    int i;
    int c;

    for (i = 0; i < MAXLEN; i++) {
        if ((c = getchar()) == '0')
            getchar();
        else
            break;
        scanf("%d %d", &s[i].startaddr, &s[i].size);
        getchar();
    }
    int tag1,startaddr1,size1;
    while (scanf("%d %d %d",&tag1,&startaddr1,&size1)!=EOF)
    {
        plugin(s, startaddr1, size1);
    }
    //打印
    i = 0;
    while (s[i].size != 0)
    {
        printf("%d %d %d\n", s[i].tag, s[i].startaddr, s[i].size);
        i++;
    }

    return 0;
}

int plugin(node s[], int startaddr1, int size1) {
    int p = 0;
    while (s[p].startaddr<startaddr1)
    {
        p++;
    }
    if (startaddr1 + size1 == s[p].startaddr) {
        s[p].startaddr = startaddr1;
        s[p].size += size1;
        if (p > 0 && (s[p - 1].startaddr + s[p - 1].size) == s[p].startaddr) {
            s[p - 1].size += s[p].size;
            forward(s, 1, p );
        }
    }
    else if (p > 0 && (s[p - 1].startaddr + s[p - 1].size) == startaddr1) {
        s[p - 1].size += size1;

    }
    else {
        int i;
        for (i = MAXLEN - 1; i > p; i--) {
            s[i].size = s[i - 1].size;
            s[i].startaddr = s[i - 1].startaddr;
        }
        s[p].size = size1;
        s[p].startaddr = startaddr1;
    }
    return 0;
}

void forward(node s[], int stride,int start) {
    int i;
    for (i = start; i < MAXLEN-1; i++) {
        s[i].size = s[i + stride].size;
        s[i].startaddr = s[i+stride].startaddr;
    }
}