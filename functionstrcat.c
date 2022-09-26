#include <stdio.h>
#include <string.h>
char *strcat(char *a,const char *b);
int main()   //函数原型：char* strcat(char *restrict a,const char *restrict b)
{            //把b连接到a上，形成一个新的字符串
char a[11]="hello";
char b[]="world";
char *c=strcat(a,b);
for(int i=0;i<10;i++){
 printf("%c",c[i]);
}
 return 0;
}
    

//char *strcat(char *a,const char *b){            这是自己写的strcat函数
//int i=0;
//int x=strlen(a);
//while(*(b+i)!='\0'){
//*(a+x+i)=*(b+i);
//i++;
//}
//a[10]='\0';
//return a;
//}