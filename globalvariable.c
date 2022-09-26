#include <stdio.h>
int a=2;   //全局变量的作用域和生存期是全局。全局变量不初始化则默认为0（指针为NULL，即空指针）
//一般不要int b=a；存在危险
int main()
{
int a=5;
printf("%d",a);  //变量重名时，小范围的会覆盖掉大范围的（全局变量）
    return 0;
}