#include <stdio.h>
void f();
int main()
{
f();
f();
f();
    return 0;
}
void f(){
    static int a=5;      //静态本地变量实际上是全局变量，它的生存期为全局，但作用域为定义时所在的范围
    printf("%d\n",a);   //只有在块内，才能通过a访问对象5，但在其他块中，可以通过a的地址来访问对象5
    a++;               //这就是静态本地变量的意义所在
    printf("%d\n",a);
}