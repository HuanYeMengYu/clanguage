#include <stdio.h>
#include "externstatement.h"  
extern int a;//extern声明外部变量，去其他文件寻找
int main()
{
printf("%d",10*a);           //当编译器同时编译该文件和externstatement.h时便可成功编译
    return 0;
}