/*

线性表的顺序存储结构 数组形式实现
*/
#include <stdio.h>

#define MAXSIZE 20
#define OK 1
#define ERROR 0

typedef int ElemType;
typedef int Status;

typedef struct {      // 线性表顺序存储
	ElemType data[MAXSIZE];
	int length;
}Sq_List;

//获取链表中元素操作
//获取线性链表中 第i（1开始）个数据 e为传入数据的地址
Status GetElem(Sq_List L, int i, ElemType *e ){  // ElemType *e定义的时候  前缀* 表示后面变量是一个指针
	if (L.length==0 || L.length<i || i<1)
		return ERROR;
	*e = L.data[i-1];  //解引用
	return OK;
}  


//插入第i个位置的元素 i从1开始
Status ListInert(Sq_List *L, int i, ElemType e) {
	int k;
	if (L->length==MAXSIZE)
		return ERROR;
	if (i<1 || i>L->length+1)
		return ERROR;
	if(i<=L->length)
	{
		for(k = L->length-1; k >=i-1; k-- ) //移动元素
			L->data[k+1] = L->data[k]; 
		
	}
	L->data[i-1] = e;   //插入元素
	L->length ++;

	return OK;
}


//初始化链表
Status InitList(Sq_List *L) {
	L->length = 0;
	int i;
	for (i=0;i<=MAXSIZE;i++){
		L->data[i] = 0;
	}
	return OK;
}

//删除链表中第i个元素 i从1开始
Status DeteList(Sq_List *L, int i, ElemType *t){
	int k = 0;
	if (L->length == 0)
		return ERROR;
	if(i<1 || i>L->length)
		return ERROR;
	for(k=i;k<=L->length-1;k++){
		if (L->length==1){
			*t = L->data[0];
			break;
	}
		if (k == i)
			*t = L->data[i-1];
		L->data[i-1] = L->data[i];	
	}
	L->length --;
	return OK;
}


int main() {
	Sq_List my_list;  //实例化
	InitList(&my_list); //初始化数组

	ElemType my_get_elem = 5;

	if (ListInert(&my_list, 1, my_get_elem)){   //插入第一个元素 5
		printf("数组的长度为：%d\n", my_list.length);
	}
	else
		printf("bad operation\n");

	if (ListInert(&my_list, 1, 3)){   //插入第2个元素 3
		printf("数组的长度为：%d\n", my_list.length);
	}
	else
		printf("bad operation\n");   //{3 5}

	if (DeteList(&my_list, 2, &my_get_elem)){   //删除第二个元素 5
		printf("数组的长度为：%d\n", my_list.length);
		printf("删除的数据元素为：%d\n",my_get_elem);
	}
	else
		printf("bad operation\n");   //{3 5}
	

	if (GetElem(my_list, 2, &my_get_elem))
		printf("得到的数据元素为：%d\n", my_get_elem);
	else
		printf("bad operation\n");

}