/*10.25 链表的插入排序*/
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
void StraightInsertionSort(SqList* L);
int main()
{
    int len;
    scanf("%d\n", &len);
    SqList* L = (SqList*)malloc(sizeof(SqList));
    L->length = len;
    int tmp;
    int i = 1;
    while ((scanf("%d", &tmp)) != EOF)
    {
        L->r[i].key = tmp;
        i++;
    }
    StraightInsertionSort(L);
    for (i = 1; i < len; i++) {
        printf("%d ", L->r[i].key);
    }
    printf("%d", L->r[i].key);
    return 0;
}

void StraightInsertionSort(SqList* L)
{
    int i, j;
    for (i = 2; i <= L->length; i++)
        if (L->r[i].key < L->r[i - 1].key) {
            //仅逆序时需要将L->r[i]插入有序子表
            L->r[0] = L->r[i]; //设置哨兵
            L->r[i] = L->r[i - 1]; //记录后移
            for (j = i - 2; L->r[0].key < L->r[j].key; --j)
                L->r[j + 1] = L->r[j];//记录后移
            L->r[j + 1] = L->r[0]; //插入到相应位置
        }//if
}

