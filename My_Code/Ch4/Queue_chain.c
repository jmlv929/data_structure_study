/*

队列的链式存储结构
*/

#include<stdio.h>
#include<stdlib.h>
typedef int Qelem;

#define OK 1
#define ERROR 0

typedef int Status;

typedef struct QNode
{
    Qelem data;
    struct QNode *next;
}QNode, *QNodeptr;

typedef struct 
{
    QNodeptr front, rear;
}LinkQueue;

//enqueue入队 插入尾节点

Status enqueue(LinkQueue *l, Qelem q){
    QNodeptr s = (QNodeptr)malloc(sizeof(QNode));
    s->data = q;
    s->next = NULL;
    l->rear->next = s;
    l->rear = s;
    return OK;
}

Status dequeue(LinkQueue *l, Qelem *q){
    QNodeptr p;
    if(l->front == l->rear)
        return ERROR;
    p = l->front->next;
    *q = p->data;
    l->front->next = p->next;
    if(l->rear==p)                  //front指向一个元素的结点 在顶部 出队 是出front指向的下一个节点的元素  rear指向有元素的节点
        l->rear=l->front;
    free(p);
    return OK;
}

int main(){


}