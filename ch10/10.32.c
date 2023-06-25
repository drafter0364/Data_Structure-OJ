/*10.32-荷兰旗问题*/

#define  _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include<stdlib.h>
#define MAXSIZE 1000//待排顺序表最大长度
typedef int KeyType; //关键字类型为整数类型
typedef struct {
    KeyType key; //关键字项，排序码
} RcdType; // 记录类型
typedef struct {
    RcdType r[MAXSIZE + 1]; //r[0]闲置
    int length; //顺序表长度
} SqList;
void sort(L);
int main()
{
    SqList* L = (SqList*)malloc(sizeof(SqList));
    int i = 1;
    int tmp;
    while ((scanf("%d", &tmp)) != EOF)
    {
        if (tmp != 1 && tmp != 2 && tmp != 3)
            break;
        L->r[i].key = tmp;
        i++;
    }
    L->length = i - 1;
    sort(L);
    for (i = 1; i < L->length; i++) {
        printf("%d ", L->r[i].key);
    }
    printf("%d", L->r[i].key);
    return 0;
}

void sort(SqList* L) {
    int i;
    int part1,part2;
    part1 = part2 = 1;
    for (i = 1; i <= L->length; i++) {
        if (L->r[i].key == 1) {
            L->r[i].key = L->r[part2].key;
            L->r[part2].key = L->r[part1].key;
            L->r[part1].key = 1;
            part1++;
            part2++;
        }
        else if (L->r[i].key == 2) {
            L->r[i].key = L->r[part2].key;
            L->r[part2].key = 2;
            part2++;
        }
    }
}