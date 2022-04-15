/*

孩子结点表示法

利用数组 以及 两个 数据结构

*/
#define MAXSIZE 100

typedef int ElemType;

//孩子链表结点
typedef struct CTNode{
    ElemType child;
    struct CTNode *next;
}*ChildPtr;


//表头数组
typedef struct {
    ElemType data;
    ChildPtr firstchild;
}CTBox;

typedef struct 
{
    CTBox nodes[MAXSIZE];   //树结构
    int r,n;   //根的位置和结点数
}CTree;
