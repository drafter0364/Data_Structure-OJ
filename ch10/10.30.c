/*10.30-快排非递归*/
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
void QuickSort(SqList* L);
void QSort(SqList* L, int low, int high);
int Partition(SqList* L, int low, int high);
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
    QuickSort(L);
    for (i = 1; i < L->length; i++) {
        printf("%d ", L->r[i].key);
    }
    printf("%d", L->r[i].key);
    return 0;
}

void QuickSort(SqList* L) {
    //对顺序表进行快速排序
    QSort(L, 1, L->length);
}//QuickSort

void QSort(SqList* L, int low, int high) {
    //对L中的子序列L.r[low..high]进行快速排序
    int pivotloc;
    if (low < high) {
        //对L.r[low..high] 进行一次划分
        pivotloc = Partition(L, low, high);
        QSort(L, low, pivotloc - 1); //对低子序列递归排序
        QSort(L, pivotloc + 1, high); //对高子序列递归排序
    }
} // QSort

int Partition(SqList* L, int low, int high) {
    L->r[0] = L->r[low]; int pivotkey = L->r[low].key; //轴点
    while (low < high) {
        while (low < high && L->r[high].key >= pivotkey)
            --high;
        L->r[low] = L->r[high];
        while (low < high && L->r[low].key <= pivotkey)
            ++low;
        L->r[high] = L->r[low];
    }
    L->r[low] = L->r[0]; //轴点到位
    return low; // 返回轴点所在位置
} // Partition