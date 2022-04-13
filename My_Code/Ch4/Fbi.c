/*

Fibonacci序列

递归实现

*/
#include<stdio.h>


int Fbi(int n){
    if (n==0 || n==1)
        return n;
    return Fbi(n-1)+Fbi(n-2);
}

int main(){
    int n = 10;
    printf("%d\n",Fbi(n));
}
/*
0 1 1 2 3 5 8 13 21 34 55
0 1 2 3 4 5 6 7  8  9  10
*/