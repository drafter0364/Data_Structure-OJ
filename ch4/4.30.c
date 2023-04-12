/*4.30-最长重复子串及其位置
假设以定长顺序存储结构表示串，
试写出一个算法，求串s中第一次出现的最长重复字串及其位置。
注意：重复的子串可以重叠*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXLEN 100

int searchrep(char s[], int i);
int main()
{
    char s[MAXLEN];
    scanf("%s", s);
    int i;
    int maxlenth=0;
    int init;
    int temp;
    for (i = 0; i < strlen(s); i++)
    {
        temp = searchrep(s, i);
        if (maxlenth < temp)
        {
            maxlenth = temp;
            init=i;
        }
    }
    if(!maxlenth){
        printf("-1");
        return 0;
    }
    for(i=0;i<maxlenth;i++)
        printf("%c",s[init+i]);
    printf(" %d",init);
}

int searchrep(char s[], int i){
    int k;
    char *t=(char *)malloc(sizeof(char)*MAXLEN);//存储从i开始的串
    char *temp=(char *)malloc(sizeof(char)*MAXLEN);//储存t的前缀
    strcpy(t,s+i);
    strcpy(temp,t);
    char *p;
    int maxk=0;
    for(k=1;k<strlen(s)-i;k++)
    {
        strcpy(temp,t);
        *(temp+k)='\0';
        p=strstr(t+1,temp);
        if(p!=NULL)
        {
            maxk=k;
        }
    }
    return maxk;
}
