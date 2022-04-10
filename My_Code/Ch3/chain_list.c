/*
线性表 链式存储结构  利用结构指针描述
结点Node 数据域 与 指针域
*/

#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0

typedef int ElemType;
typedef int Status;

typedef struct NODE{
    ElemType data;
    struct NODE *next;  //嵌套自己的时候 要用struct NODE！
}Node;  //Node是一个类

typedef Node *LinkList;  // LinkList 是一个类
//Node * LinkLinst 
//上式则定义LinkList就不是一个类了  而是一个实例

/* 
随机产生n个元素的值，建立带表头结点的单链线性表L 尾插
*/
Status CreatList(LinkList *L, int n) {   //L是头部节点指针（头指针） 没有数据 只有指向链表中第一个元素（头结点）的指针
    LinkList p, r; // p 新申请的指针区域  r尾部指针
    int i;

    *L = (LinkList)malloc(sizeof(Node));  //LinkList是一个指向Node的指针 
    r = *L;  //r是尾指针 先指向头指针
    for (i=0; i<n ;i++) //根据n 动态分配空间
    {
        p = (LinkList)malloc(sizeof(Node)); //p指向新生成的空间
        p->data = (ElemType)(rand()%100+1); //随机生成100以内的数字
        r->next = p;
        r = p;
    }
    r->next = NULL;
}
/*
获取链表中第i个的元素 i从1开始
*/

Status GetList(LinkList L, int i, ElemType *t){ //这里对LinkList不修改 直接值传递
    if(i<1)
        return ERROR;
    int k;
    for(k=1;k<=i;k++){
        if(L->next==NULL)
            break;   //空链表 或者 循环次数大于链表长度
        L = L->next;
        if(k==i) {
            *t = L->data;
            return OK;
        }    
    }
    return ERROR;
}
/*
插入链表中第i个元素 i从1开始
*/
Status InsertList(LinkList *L, int i, ElemType t) {
    if(i<1)
        return ERROR;
    int j=1;
    LinkList p, s; //插入的前一个节点地址 以及插入的节点的地址
    p = *L;
    while (p && j<i)
    {
        p = p->next;
        j++;
    }
    if (!p || j>i)
        return ERROR;
    s = (LinkList)malloc(sizeof(Node));
    s->data = t;
    s->next = p->next;
    p->next = s;
    return OK;
}

int main(){
    LinkList my_linklist;//头指针
    int my_num;

    CreatList(&my_linklist, 20);
    if(GetList(my_linklist, 5, &my_num))
        printf("%d\n",my_num);
    else
        printf("bad operation!");

    if (InsertList(&my_linklist, 1, 30))
        printf("%d\n",my_linklist->next->data); //第一个数据元素
    else
        printf("bad operation!");
}