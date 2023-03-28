/*3.21-逆波兰式
假设表达式由单字母变量和双目四则运算符构成.
试写一个算法,将一个通常书写形式且书写正确的表达式转换为逆波兰式.*/
#define INITSIZE 100
#define OPSETSIZE 7
typedef union{float x;char op;} ElemType;
typedef struct {
    int top; //栈顶
    ElemType *base;
    int stacksize;
}SqStack; // 动态顺序栈
char OPSET[OPSETSIZE]={'+' , '-' , '*' , '/' ,'(' , ')' , '#'};
unsigned char Prior[OPSETSIZE][OPSETSIZE] = {
 {'>','>','<','<','<','>','>'},
 {'>','>','<','<','<','>','>'},
 {'>','>','>','>','<','>','>'},
 {'>','>','>','>','<','>','>'},
 {'<','<','<','<','<','=',' '},
 {'>','>','>','>',' ','>','>'},
{'<','<','<','<','<',' ','='} };
int main(){

}