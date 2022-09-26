#include <stdio.h>
#include <string.h>
int main()  //函数原型：char *strstr(const char*a,const char*b),在字符串a中找字符串b,返回首字符地址
{                     //char *strcasestr(const char*a,const char*b),case代表不区分大小写
char a[]="hello";
char b[]="llo";
char *c=strstr(a,b);
printf("%s",c);
    return 0;
}