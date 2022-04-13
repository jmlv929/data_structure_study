/*

栈的顺序存储结构
需要先定义数组的长度 

*/


#include<stdio.h>

typedef int Elemtype;
#define MAXSIZE 200
typedef int Status;

#define OK 1
#define ERROR 0

typedef struct 
{
    Elemtype data[MAXSIZE];
    int top;      /*栈顶指针*/  //空栈指向-1
}SqStack;


Status into_stack(SqStack *s,Elemtype e){   //入栈操作
    if(s->top == MAXSIZE-1)
        return ERROR;
    s->data[s->top+1] = e;
    s->top++;
    return OK; 
}

Status pop_stack(SqStack *s,Elemtype *e){   //出栈操作
    if(s->top == -1)
        return ERROR;
    *e = s->data[s->top];
    s->top--;
    return OK; 
}

Status init_stack(SqStack *s){
    int i = 0;
    for ( i = 0; i < 100; i++)
    {
        s->data[i] = 0;
    }
    s->top = -1;
    return OK;
}

int main() {
    SqStack my_stack;
    Elemtype a = 1, b= 2, c= 3, d = 4;

    init_stack(&my_stack);   //初始化栈

    if (into_stack(&my_stack, a))    //入栈a
        printf("插入的数据为：%d\n",my_stack.data[my_stack.top]);
    else
        printf("bad operation!");

    if (into_stack(&my_stack, b))    //入栈b
        printf("插入的数据为：%d\n",my_stack.data[my_stack.top]);
    else
        printf("bad operation!");

    if (into_stack(&my_stack, c))    //入栈c
        printf("插入的数据为：%d\n",my_stack.data[my_stack.top]);
    else
        printf("bad operation!");

    if (pop_stack(&my_stack, &d))    //入栈c
        printf("出栈数据为：%d\n",d);
    else
        printf("bad operation!");

    printf("栈顶的元素为%d\n",my_stack.data[my_stack.top]);

}