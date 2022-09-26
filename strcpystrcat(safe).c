#include <stdio.h>
#include <string.h>
int main()  //char *strncpy(char *restrict a,const char *restric b,size_t n)只拷贝n个字符
{            //char *strncat(char *restrict a,const char *restric b,size_t n)只连接n个字符
char a[]="hello";
char b[]="world";
strncpy(a,b,3);
for(int i=0;i<3;i++){
    printf("%c",a[i]);
}
printf("\n");
char c[]="fuck";
char d[]="you";
strncat(c,d,2);
for(int j=0;j<6;j++){
    printf("%c",c[j]);
}
    return 0;
}