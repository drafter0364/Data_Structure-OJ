/*5.37-删除广义表中的元素
试编写递归算法，删除广义表中所有值等于x的原子项。

如果子表中不包含元素则删除该子表*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLEN 1000
#define OK 0
#define ERROR -1
typedef enum
{
    ATOM,
    LIST
} ElemTag;
typedef struct GLNode
{
    ElemTag tag; // ATOM or LIST
    union
    { // 原子结点和表结点的联合部分
        char atom;
        struct GLNode *hp; // 指向子表的指针
    } ptr;
    struct GLNode *tp; // 指向同一层下一个表元素结点的指针
} GLNode, *Glist;

int StrSubStr(char sub[], char s[], int i, int j);
int CreateGList(Glist *L, char s[]);
int Sever(char str[], char hstr[]);
int StrClear(char str[]);
int IsStrEmpty(char s[]);
void DisplayList(Glist head);
void Print(Glist head);
void Delete(Glist *L, char x);
int main()
{
    char s[MAXLEN];
    scanf("%s", s);
    char delc;
    getchar();
    scanf("%c", &delc);
    Glist L;
    CreateGList(&L, s);
    Delete(&L, delc);
    if(L->ptr.hp==NULL&&L->tp==NULL)
        printf("-1");
    else
        DisplayList(L);

    return 0;
}

int CreateGList(Glist *L, char s[])
{
    GLNode *p, *q, *r, *head;
    char hsub[MAXLEN];
    if (!strcmp(s, "()"))
        (*L) = NULL; // 创建空表
    else
    {
        // 生成表结点
        if (!(*L = (Glist)malloc(sizeof(GLNode))))
            return ERROR;
        if (strlen(s) == 1)
        { // 建立单原子广义表
            (*L)->tag = ATOM;
            (*L)->ptr.atom = *s;
        }
        else
        {
            (*L)->tag = LIST;
            p = (*L);
            // 设sub为 脱去串 S 最外层括弧的子串
            char *sub = (char *)malloc(sizeof(char) * (strlen(s)));
            StrSubStr(sub, s, 2, strlen(s) - 2);
            do
            { // 重复建n个子表
                // 分离出子表串hsub
                Sever(sub, hsub);
                // 创建由串hsub定义的广义表p→hp
                CreateGList(&(p->ptr.hp), hsub);
                q = p;
                if (!IsStrEmpty(sub))
                {
                    // 余下的表不为空
                    if (!(p = (GLNode *)malloc(sizeof(GLNode))))
                        return ERROR;
                    // 建下一个子表的表结点*(p->tp)
                    p->tag = LIST;
                    q->tp = p;
                }
            } while (!IsStrEmpty(sub));
            q->tp = NULL; // 表尾为空表
        }
    }
    return OK;
}

void Delete(Glist *L, char x)
{
    Glist head, p;
    if (*L && (*L)->tag == LIST)
    {
        head = (*L)->ptr.hp;
        if (head)
        {
            if (head->tag == LIST)
            {
                Delete(&((*L)->ptr.hp), x);
                Delete(&((*L)->tp), x);
            }
            else
            {
                if (head->ptr.atom == x)
                {
                    p = *L;
                    *L = (*L)->tp;
                    p->tp = NULL;
                    Delete(L, x);
                }
                else
                {
                    Delete(&((*L)->tp), x);
                }
            }
        }
        else
        {
            if ((*L)->tp)
            {
                Delete(&((*L)->tp), x);
            }
            else
            {
                free(*L);
            }
        }
    }
}

int StrSubStr(char sub[], char s[], int i, int j)
{
    int k;
    if (i <= 0 || i + j > strlen(s) + 1)
        return ERROR;
    for (k = 0; k < j; k++)
        sub[k] = s[i + k - 1];
    sub[k] = '\0';
    return OK;
}

int Sever(char str[], char hstr[])
{
    // 将非空串str分割为两部分：hstr为第一个逗号之前的子串,str为之后的子串
    int n, i, j, k;
    char ch[MAXLEN];
    n = strlen(str);
    i = 0;
    k = 0; // k:尚未配对的左括号个数
    do
    {
        ++i;
        StrSubStr(ch, str, i, 1); // 取一个字符
        if (*ch == '(')
            ++k;
        else if (*ch == ')')
            --k;
    } while (i < n && (*ch != ',' || k != 0));
    if (i < n)
    { // 遇到逗号或括号
        StrSubStr(hstr, str, 1, i - 1);
        StrSubStr(str, str, i + 1, n - i);
    }
    else
    {
        strcpy(hstr, str);
        StrClear(str);
    }
} // sever

int StrClear(char str[])
{
    *str = '\0';
    return OK;
}

int IsStrEmpty(char s[])
{
    return (*s == '\0') ? 1 : 0;
}

void DisplayList(Glist head)
{
    GLNode *p, *q;
    if (!head)
        return;
    if (head->tag == ATOM)
    {
        printf("%c", head->ptr.atom);
        return;
    }
    printf("(");
    if (head)
    {
        do
        {
            p = head->ptr.hp;
            q = head->tp;
            while (q && p && p->tag == ATOM)
            {
                printf("%c", p->ptr.atom);
                p = q->ptr.hp;
                q = q->tp;
                if (p&&p->ptr.hp)
                    printf(",");
            }
            if (p && p->tag == ATOM)
            {
                printf("%c", p->ptr.atom);
                break;
            }
            else
            {
                if (!p)
                    printf("");
                else
                    DisplayList(p);
                if (q)
                    printf(",");
                head = q;
            }
        } while (head);
        printf(")");
    }
}

void Print(Glist l)
{
    if (l != NULL)
    {
        if (l->tag == ATOM)
        {
            printf("%c", l->ptr.atom);
        }
        else if (l->ptr.hp && l->ptr.hp->tag == ATOM)
        {
            Print(l->ptr.hp);
        }
        else if (l->ptr.hp && l->ptr.hp->tag == LIST)
        {
            printf("(");
            Print(l->ptr.hp);
            printf(")");
        }
        if (l->tp != NULL)
        {
            printf(",");
        }
        Print(l->tp);
    }
}