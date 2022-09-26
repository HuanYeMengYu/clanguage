#include <stdio.h>
enum color{red,yellow,green,blue=6,numcolor};  //red=0,yellow=1.....//enum可以跳跃赋值（如blue）
//一般最后放一个numcolor，它的值即枚举变量的个数
void f(enum color x); //注意枚举不是函数，要有分号                        
int main()  
{
enum color b=red;     //不同于函数，枚举量必须带着enum
scanf("%d",&b);  //enum相当于int
f(b);
    return 0;
}
void f(enum color x){
    printf("%d\n",x);
}