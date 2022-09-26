#include <stdio.h>
#include "headfile.h"    //在定义、使用函数的地方都要引入头文件，用双引号让编译器直接在目录里找头文件
void f(int a);
int main()
{
int a=5;
f(a);
    return 0;
}
void f(int a){
    printf("%d",10*a);
}