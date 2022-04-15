/*
朴素的模式匹配算法

*/

#include<stdio.h>
#include<string.h>



typedef char* String;  

/*
返回字串在主串S中第pos个字符之后的位置 ，不存在就返回0
其中 T非空 T长度取值范围 [1, Str(s)]
*/

int Index(String S, String T, int pos) {
    if(strlen(T) == 0 || strlen(S) == 0 || strlen(S) < strlen(T))
        return 0;

    int i = pos-1;
    int j = 0;

    while ( i <= strlen(S)-1 && j <= strlen(T)-1)
    {
        if(S[i] == T[j]) {
            i++;
            j++;
        }
        else {
            i = i - j + 1;
            j = 0;
        } 
    }
    if(j >= strlen(T)) // =情况下不包括 S包含T的字串在S的最后
            return (i - strlen(T)+1);
        else
            return 0;  
}


int main() {
    String S;
    S = "hello world!";

    printf("字符串S的长度为%d\n",strlen(S));

    String T;
    T = "wo";

    int pos = 4; //字串在主串中寻找的初始位置 [1,strlen(S)]

    if(Index(S, T, pos) != 0)
        printf("字串T在主串S中的位置为:%d\n",Index(S, T, pos));
    else
        printf("主串中没有您想找的子串！");
}