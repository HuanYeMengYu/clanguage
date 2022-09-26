#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()   //函数完整形式：char *strchr(const char *p,int c)   int c代表一个字符
{                          // char *strrchr(const cahr *p,int c) r代表right，指从字符串右边数起
char a[]="hello";
char *p=strchr(a,'l');
printf("%s\n",p);
p=strchr(p+1,'l');             //这样可以找到字符串中的第二个l
printf("%s\n",p);
char b[]="world";           //这样可以找到r之前部分的字符串
char *q=strchr(b,'r');
*q='\0';
char *t=(char *)malloc(strlen(b)+1);
strcpy(t,b);
printf("%s\n",t);
    return 0;
}