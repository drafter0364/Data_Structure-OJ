/*2.41-稀疏多项式求导
试以循环链表作稀疏多项式的存储结构，编写求其导函数的算法，
要求利用原多项式中的节点空间存放其导函数（多项式），同时
释放所有无用（被删）节点。*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAXLEN 100
typedef struct PolyNode
{
    int data;//系数
    int power;//阶数
    struct PolyNode *next;
} PolyNode, *PolyLink;

typedef PolyLink LinkedPoly; // LinkedPoly指向node的指针
PolyNode *InitPolylink(LinkedPoly L);//初始化循环链表
PolyNode *Insert(LinkedPoly L, int coefficient, int xpower);//把coefficientx^xpower插入L中
PolyNode *findpre(LinkedPoly L, PolyNode *p);//找p的前驱
void writein(LinkedPoly L);//将输入写进L中
void derivate(LinkedPoly L);//求导
int main()
{
    LinkedPoly poly = NULL;
    poly = InitPolylink(poly);
    writein(poly);
    derivate(poly);
    PolyNode *f = poly->next;
    if (f == poly) // 空链表
    {
        printf("0");
        return 0;
    }
    //打印结果
    else
    {
        if ((f->data) > 0)
            printf("%d", f->data);
        else
            printf("- %d", -f->data);
        if (f->power == 0)
            ;
        else if (f->power == 1)
        {
            printf("x");
        }
        else
            printf("x^%d", f->power);
        if (f->next != poly)
            printf(" ");
        f = f->next;
        if (f == poly)
            return 0;
    }
    while (f->next != poly)
    {
        if ((f->data) > 0)
            printf("+ %d", f->data);
        else
            printf("- %d", -f->data);
        if (f->power == 0)
            printf(" ");
        else if (f->power == 1)
            printf("x ");
        else
            printf("x^%d ", f->power);
        f = f->next;
    }
    if ((f->data > 0))
        printf("+ %d", f->data);
    else
        printf("- %d", -f->data);
    if (f->power == 1)
        printf("x");
    else if (f->power == 0)
        ;
    else
        printf("x^%d", f->power);
    return 0;
}

PolyNode *InitPolylink(LinkedPoly L)
{
    L = (PolyNode *)malloc(sizeof(PolyNode));
    if (L != NULL)
    {
        L->next = L;
    }
    return L;
}

void writein(LinkedPoly L)
{
    int c;
    int sign = 1;
    int coefficient = 0; // 系数
    int xpower = 0;      // 幂
    char s[MAXLEN];
    gets(s);//输入读到s中，使用gets()是因为输入有空格
    int i = 0;
    while (s[i] != '\0') // 没有到多项式结尾
    {
        if (isdigit(s[i]))
        {
            while (s[i] != 'x' && s[i] != ' ' && s[i])
            {
                coefficient = coefficient * 10 + s[i] - '0';
                i++;
            } // 读取系数值
            coefficient *= sign;
            if (s[i] == 'x')//该项含x
            {
                if (s[++i] == '^')//该项x指数大于1
                    while (s[++i] != ' ' && s[i] != '\0')
                    {
                        xpower = xpower * 10 + s[i] - '0';
                    }
                else//一次项
                {
                    xpower = 1;
                }
            }
            else if (s[i] == ' ')//不含x，常数项
                xpower = 0;
            else if (s[i] == '\0')//到字符串结尾
            {
                Insert(L, coefficient, xpower);
                break;//结束循环
            }
            Insert(L, coefficient, xpower);//插入
        }
        // 读到符号，记录sign,系数和幂的变量清0，为下一次做准备
        else if (s[i] == '+' || s[i] == '-')//读到符号
        {
            sign = (s[i] == '+') ? 1 : -1;
            coefficient = 0;
            xpower = 0;
        }
        else if (s[i] == ' ')
            ;
        i++;
    }
    return;
}

void derivate(LinkedPoly L)
{
    PolyNode *p = L->next;
    PolyNode *pre;
    if (p == L)
        return;
    while (p != L)
    {
        if (p->power >= 1)//非 常数项
        {
            p->data *= (p->power);
            p->power -= 1;
        }
        else//常数项
        {
            pre = findpre(L, p);
            pre->next = p->next;
            free(p);
            p = NULL;
            return;
        }
        p = p->next;
    }
}

PolyNode *Insert(LinkedPoly L, int coefficient, int xpower)
{
    PolyNode *p = L->next;
    PolyNode *pre = L;
    PolyNode *restore = (PolyNode *)malloc(sizeof(PolyNode));
    if (L->next == L) // 空链表，创建第一个表示项的结点
    {
        restore->data = coefficient;
        restore->power = xpower;
        L->next = restore;
        restore->next = L;
        return L;//直接返回
    }
    //不是空链表，需要寻找合适位置
    while (p->power > xpower)
        p = p->next;
    if (p->power == xpower)//指数相同，需要合并
    {
        p->data += coefficient;//合并系数
        if (p->data == 0)//合并成了0，需要删除该结点
        {
            pre = findpre(L, p);
            pre->next = p->next;
            free(p);
            p = NULL;
        }
    }
    else//指数不同，说明p代表的项阶数是第一个小于xpower的，在p结点之前插入新的项
    {
        pre = findpre(L, p);
        restore->data = coefficient;
        restore->power = xpower;
        pre->next = restore;
        restore->next = p;
    }
    return L;
}

//找前驱
PolyNode *findpre(LinkedPoly L, PolyNode *p)
{
    PolyNode *pre = L;
    while (pre->next != p)
        pre = pre->next;
    return pre;
}