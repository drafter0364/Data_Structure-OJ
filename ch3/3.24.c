//试编写如下定义的递归函数的递归算法，并根据算法画出求ｇ(5, 2)时栈的变化过程。

//g(m, n)  = 0 (m = 0, n>=0)   g(m, n) = g(m-1, 2n) + n (m>0, n>=0)
#include<stdio.h>
int  g(int m,int n,int * result);
int main(){
    int m,n;
    scanf("%d,%d",&m,&n);
    int result=0;
    g(m,n,&result);
    printf("%d",result);
    return 0;
}

int  g(int m,int n,int * result){
    if(m==0)
        return 0;
    else{
        *result=*result+n;
        g(m-1,2*n,result);
    }
}