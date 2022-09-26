#include <stdio.h>
int* f(void);
void g(void);
int c=7;
int main()
{
int *p=f();
printf("%p\n",*p);
g();
printf("%p\n",*p);
    return 0;
}
int* f(void){
    int a=5;
    return &c;    //如果函数返回全局变量的地址则没有问题
  //  如果return &a;   函数返回本地变量的地址是有问题的
}
void g(void){   //当调用下一个函数，b直接占用了a的地址，因此不能再用a的地址来改变a
    int b=5;        
}