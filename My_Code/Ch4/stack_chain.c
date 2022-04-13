/*
栈的链式存储结构
较灵活  栈顶放在链表头部 这样就不需要头节点了

*/

#include<stdio.h>
#include<stdlib.h>

typedef int ELemtype;
typedef int Status;

#define OK 1
#define ERROR 0

typedef struct
{
    struct Node  *top;
    int count;
}ChainStack;

typedef struct Node
{
    ELemtype data;
    struct Node *next;
}Node, *Nodeptr;


Status push_stack(ChainStack *c, ELemtype e) {
    Nodeptr p = (Nodeptr)malloc(sizeof(Node));   //malloc后的用free释放  需要手动释放
    p->data = e;
    p->next = c->top;
    c->top = p;
    c->count++;
    return OK;
}
/*
Status push_stack(ChainStack *c, ELemtype e) {   //这段代码是不可行的 因为变量p的值 在执行完这个函数之后就被释放了指向不确定 ；
    Node p;
    p.data = e;
    p.next = c->top;
    c->top = &p;
    c->count++;
    return OK;
}
*/
Status pop_stack(ChainStack *c, ELemtype *e) {
    if(c->top->next == NULL)
        return ERROR;
    *e = c->top->data;
    c->count--;
    Nodeptr p = c->top;
    c->top = c->top->next;
    free(p);
    return OK;
}


Status InitStack(ChainStack *c){
    c->count = 0;
    c->top = NULL;
}

int main(){
    ChainStack my_stack;
    ELemtype t = 5;

    InitStack(&my_stack);

    if(push_stack(&my_stack, t))
        printf("链表现在的长度为:%d\n",my_stack.count);
        printf("栈顶的数据位：%d\n",(*(my_stack.top)).data);
    
    if(push_stack(&my_stack, 7))
        printf("链表现在的长度为:%d\n",my_stack.count);
        printf("栈顶的数据位：%d\n",(*(my_stack.top)).data);
    if(pop_stack(&my_stack, &t))
        printf("出栈的元素为：%d\n",t);
        printf("链表现在的长度为:%d\n",my_stack.count);
        printf("栈顶的数据位：%d\n",(*(my_stack.top)).data);
}