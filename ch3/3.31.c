/*假设称正读和反读都相同的字符序列为"回文",例如,'abba'和'abcba'是回文，

而'abcde'和'ababab'则不是回文。

试写一个算法判别读入的一个以'@'为结束符的字符序列是否为回文。*/

#include<stdio.h>
#include<string.h>
#define MAXLEN 1000
int main(){
    char s[MAXLEN];
    scanf("%s", s);
    int len = strlen(s);
    if (s[len-1] != '@'||len<1)
        printf("wrong input");
    else if(len==2){
        printf("1");
        return 0;
    }
    else{
        int i;
        for(i=0;s[i]!='\0'&&i<(len-1)/2;i++)
            if(s[i]==s[len-2-i])
                ;
            else
                break;
        if(i==(len-1)/2)
            printf("1");
        else
            printf("0");
    }
    return 0;
}