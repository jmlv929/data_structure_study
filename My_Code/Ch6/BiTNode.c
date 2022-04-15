/*

二叉链表的 结构定义

*/
#include<stdio.h>

typedef int ElemType;

typedef struct BitNode {
    ElemType data;
    struct BitNode *lchild;
    struct BitNode *rchild;
}BitNode,*BiTree;

//前序遍历  递归方式！

void PreOrder(BiTree T) {
    if (T == NULL)
        return;
    printf("%c",T->data);
    PreOrder(T->lchild);
    PreOrder(T->rchild);    
}

//中序遍历  递归方式！

void PreOrder(BiTree T) {
    if (T == NULL)
        return;
    PreOrder(T->lchild);
    printf("%c",T->data);
    PreOrder(T->rchild);    
}


//中序遍历  递归方式！

void PreOrder(BiTree T) {
    if (T == NULL)
        return;
    PreOrder(T->lchild);
    PreOrder(T->rchild);  
    printf("%c",T->data);  
}