/*

测试string文件的函数

*/

#include<stdio.h>
#include<string.h>

int main() {

    char str1[] = "hello world!";
    char str2[20] = ""; //数组长度大于源数组长度  char str2[] = ""这样定义 就不对

    strcpy(str2, str1);

    printf("str2的内容现在为%s\n",str2);

    printf("%d\n",strlen(str1));
    printf("%d\n",strlen(str2));

    printf("%d\n",strcmp(str1, str1));
    printf("%d\n",strcmp(str1, str2));

}

/*
函数名称:  strcpy 

函数原型:  char* strcpy(char* str1,char* str2); 

函数功能:  把str2指向的字符串拷贝到str1中去 

函数返回:  返回str1,即指向str1的指针 
*/

/*
函数名称:  strcmp 

函数原型:  int strcmp(char * str1,char * str2); 

函数功能:  比较两个字符串str1,str2. 

函数返回:  str1<str2,返回负数;str1=str2,返回 0;str1>str2,返回正数.  
*/