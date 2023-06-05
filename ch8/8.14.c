/*8.14-伙伴管理系统*/

#include <stdio.h>
#include <ctype.h>
#define MAXNUM 20
typedef struct node {
    int k;
    int start[MAXNUM];
}node;

int pow(int x, int y);
void gettoken(struct node a[], char* str);
void plugin(struct node a[], int kval, int startaddr);
void back1(struct node a[], int kval, int p);
void forward2(struct node a[], int kval, int p);
int findbuddy(struct node a[], int kval, int startaddr);
int main()
{
    node a[MAXNUM];
    int i = 0;
    int j = 0;
    //初始化a
    while (i<MAXNUM)
    {
        (a+i)->k = i;
        for (j = 0; j < MAXNUM; j++)
        {
            (a+i)->start[j] = -1;
        }
        i++;
    }
    char str[MAXNUM];
    do{
        gets(str);
       if (str[0]=='\0')
           break;
       else {
           gettoken(a,str);
       }
    }while(1);
    int kval, startaddr;
    int c;
     while (scanf("%d %d", &kval, &startaddr)!=EOF){
        
        plugin(a, kval, startaddr);
    } 
    int first = 1;
    int flag = 0;
    for (i = 0; i < MAXNUM; i++)
    {
        //if (flag != 0 && first==0 && (a + i)->start[0] != -1)
         
        if ((a + i)->start[0] != -1)
        {
            printf("%d", (a + i)->k);
            flag = 1;
            first = 0;
            for (j = 0; j < MAXNUM && (a + i)->start[j] != -1; j++) 
            {
            printf(" %d",(a + i)->start[j]);  
            
            }
            printf("\n");
        }
    }
    return 0;
}


void gettoken(struct node a[], char* str) {
    int kval = 0;
    int i;
    for (i = 0; i < MAXNUM && str[i] != ' '; i++) 
    {
        kval = kval * 10 + str[i] - '0';
    }
    int addr;
    int n = 0;
    do {
        addr = 0;
        for (i++; i < MAXNUM && str[i] != ' '&&str[i]!='\0'; i++)
        {
            addr = addr * 10 + str[i] - '0';
        }
        (a+kval)->start[n] = addr;
        n++;
    } while (str[i] != '\0');
}

void plugin(struct node a[], int kval, int startaddr)
{
    int p=0;
    for (p = 0; p < MAXNUM && (a + kval)->start[p] != -1; p++)
    {
        if ((a + kval)->start[p] > startaddr)
            break;
    }
    if ((a + kval)->start[p]!=-1) 
        back1(a, kval, p);
    (a + kval)->start[p] = startaddr;
    //if (p > 0 && (((a + kval)->start[p - 1] + pow(2, kval)) == startaddr) && p % 2 ==1 ) {
    int modval = pow(2, kval + 1);
    int buddyaddr_1 = startaddr + pow(2, kval);
    int buddyaddr_2 = startaddr - pow(2, kval);
    if(startaddr % modval==0 && findbuddy(a,kval,buddyaddr_1)){
        
        plugin(a, kval + 1, startaddr);
        forward2(a, kval, p + 2);
    }
    //else if (( startaddr + pow(2, kval)) == (a + kval)->start[p + 1] && p % 2 == 0 ) {
    else if(startaddr % modval != 0 && findbuddy(a, kval, buddyaddr_2)){
        plugin(a, kval + 1, buddyaddr_2);
        forward2(a, kval, p + 1);
    }
    return;
}

void back1(struct node a[], int kval, int p) {
    int q;
    for (q = MAXNUM-1; q >0 && (a + kval)->start[q] == -1;q--)
        ;
    q++;
    for (; q > p; q--) {
        (a + kval)->start[q] = (a + kval)->start[q - 1];
    }
    return;
}

void forward2(struct node a[], int kval, int p) {
    int i;
    for (i = p; i < MAXNUM; i++) {
        (a + kval)->start[i - 2] = (a + kval)->start[i];
        (a + kval)->start[i] = -1;
    }
    return 0;
}

int findbuddy(struct node a[], int kval, int startaddr) {
    int i;
    for (i = 0; i < MAXNUM; i++)
        if ((a + kval)->start[i] == startaddr)
            return 1;
    return 0;
}

int pow(int x, int y) {
    int i=y;
    int result=1;
    while (i--)
        result *= x;
    return result;
}