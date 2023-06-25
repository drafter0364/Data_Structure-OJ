/*10.33-单链表实现简单选择排序*/
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
void SelectSort(SqList* L);
void swap(RcdType* x, RcdType* y);

int main()
{
    SqList* L = (SqList*)malloc(sizeof(SqList));
    int i = 1;
    int tmp;
    while ((scanf("%d", &tmp)) != EOF)
    {
        L->r[i].key = tmp;
        i++;
    }
    L->length = i - 1;
    SelectSort(L);
    for (i = 1; i < L->length; i++) {
        printf("%d ", L->r[i].key);
    }
    printf("%d", L->r[i].key);
    return 0;
}

void SelectSort(SqList* L) {
    //对顺序表L作简单选择排序
    int i, j;
    for (i = 1; i <= L->length; ++i) {
        //选择第 i 小的记录，并交换到位
        j = SelectMinKey(L, i);
        //与第 i 个记录交换
        if (i != j) swap(&L->r[i], &L->r[j]);
    }
} // SelectSort

int SelectMinKey(SqList* L, int i) {
    int min = i;
    int j;
    for (j = i; j <= L->length; j++) {
        if (L->r[j].key < L->r[min].key)
            min = j;
    }
    return min;
}

void swap(RcdType* x, RcdType* y) {
    int temp;
    temp = x->key;
    x->key = y->key;
    y->key = temp;
}