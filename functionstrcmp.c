#include <stdio.h>
#include <string.h>                   //用字符串函数别忘了string.h
int main()   //char *strncmp(char *a,const char *b,n)升级版，只比较前n个字符
{
char a[]="abc";
char b[]="Abc";
printf("%d\n",strcmp(a,b));          //strcmp判断字符串大小，大/小了输出正/负差值，相等输出零
    return 0;
}
//    int strcmp(const char *a,const char *b){               这是自己写的strcmp函数
 //   while(*a==*b&&*a!='\0'){
 //       a++;
  //      b++;
 //    }
  //  return *a-*b;
//     }
