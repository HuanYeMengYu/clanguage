#include <stdio.h>
#include <stdlib.h>
#include <string.h> //完整形式：char* strcpy(char*restrict a,const char*restrict b)     把b拷贝到a
  //该函数返回一个字符串即结果a，所以类型为char*，restrict表示防止a、b重叠，a没有const，b有const
int main()
{
char a[]="hello";
char*b=(char*)malloc(strlen(a)+1);   //malloc得到void类型，要进行强制类型转换为char*
strcpy(b,a);                         //这是复制一个字符串的常见做法
for(int i=0;i<5;i++){
  printf("%c",b[i]);
}
    return 0;
}
              //   char* strcpy(char *m,const char*n){                   这是自己写的strcpy函数
             //             char*p=m;                                     
             //         while(*m++=*n++){}           '\0'的ASCII码就是0，所以当m=n='\0'时结束循环
            //          *m='\0';
             //                 return p;
             //             }
