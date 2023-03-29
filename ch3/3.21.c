/*3.21-逆波兰式
假设表达式由单字母变量和双目四则运算符构成.
试写一个算法,将一个通常书写形式且书写正确的表达式转换为逆波兰式.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INITSIZE 10
#define OPSETSIZE 7
#define INCREMENTSIZE 10
typedef struct
{
    int top; // 栈顶
    char *base;
    int stacksize;
} SqStack; // 动态顺序栈
char OPSET[OPSETSIZE] = {'+', '-', '*', '/', '(', ')', '#'};
unsigned char Prior[OPSETSIZE][OPSETSIZE] = {
    {'=', '=', '<', '<', '>', '>', '>'},
    {'=', '=', '<', '<', '>', '>', '>'},
    {'>', '>', '=', '=', '>', '>', '>'},
    {'>', '>', '=', '=', '>', '>', '>'},
    {'>', '>', '>', '>', '>', '=', ' '},
    {'>', '>', '>', '>', ' ', '>', '>'},
    {'<', '<', '<', '<', '<', ' ', '='}};
int InitStack(SqStack *s);
int GetTop(SqStack *s, char *e);
int Push(SqStack *s, char e);
int Pop(SqStack *s, char *e);
int IsStackEmpty(SqStack *s);
void Precede(char Aop, char Bop, char *result);

int main()
{
    SqStack *s = (SqStack *)malloc(sizeof(SqStack));
    InitStack(s);
    Push(s, '#');
    char c;
    char *b = (char *)malloc(sizeof(char));
    char *temp = (char *)malloc(sizeof(char));
    char topelem;
    char *result = (char *)malloc(sizeof(char));
    while ((c = getchar()) != EOF && !IsStackEmpty(s))
    {
        if (c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z')
            printf("%c", c);
        else if (c != '\n')
        {
            GetTop(s, &topelem);
            Precede(c, topelem, result);
            if (*result == '>')
            {
                if (c != ')')
                    Push(s, c);
                else
                {
                    while (s->base[s->top - 1] != '(')
                    {
                        Pop(s, b);
                        printf("%c", *b);
                    }
                    Pop(s, b);
                }
            }
            else if (*result == '<')
            {
                while (*result == '<' || *result == '=')
                {
                    Pop(s, b);
                    printf("%c", *b);
                    GetTop(s, &topelem);
                    Precede(c, topelem, result);
                }
                Push(s, c);
            }
            else if (*result == '=')
            {
                Pop(s, b);
                if (*b != '(')
                    printf("%c", *b);
                Push(s, c);
            }
            else
            {
                Pop(s, temp);
            }
        }
        else if (c == '\n')
        {
            while (s->top != 1)
            {
                Pop(s, b);
                printf("%c", *b);
            }
            break;
        }
    }
    return 0;
}

int InitStack(SqStack *s)
{
    s->base = (char *)malloc(INITSIZE * sizeof(char));
    if (!s)
        return -1;
    s->top = 0;
    s->stacksize = INITSIZE;
    return 0;
}

int GetTop(SqStack *s, char *e)
{ // 只看不取
    if (s->top == 0)
        return -1;
    *e = s->base[s->top - 1];
    return 0;
}

int Push(SqStack *s, char e)
{
    if (s->top >= s->stacksize)
    { // 若栈已满，则增加INCREMENTSIZE个存储单元
        s->base = (char *)realloc(s->base, (s->stacksize + INCREMENTSIZE) * sizeof(char));
        if (!s->base)
            return -1;
        s->stacksize += INCREMENTSIZE;
    }
    s->base[s->top++] = e;
    return 0;
}

int Pop(SqStack *s, char *e)
{
    if (s->top == 0)
        return -1;
    *e = s->base[--s->top];
    return 0;
}

int IsStackEmpty(SqStack *s)
{
    if (s->top == 0)
        return 1;
    else
        return 0;
}

// 返回算符在算符数组里的位置
int ReturnOpOrd(char op, char *TestOp)
{
    for (int i = 0; i < OPSETSIZE; i++)
    {
        if (op == TestOp[i])
            return i;
    }
    return 0;
}

// 返回两算符之间的优先关系
void Precede(char Aop, char Bop, char *result)
{
    int i, j;
    i = ReturnOpOrd(Aop, OPSET);
    j = ReturnOpOrd(Bop, OPSET);
    *result = Prior[i][j];
    return;
}