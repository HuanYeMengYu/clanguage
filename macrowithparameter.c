#include <stdio.h>
#define CUBE(x) ((x)*(x)*(x))  //宏可以带（多个）参数。
                               //注意防止出现运算顺序的错误，宏的所有参数都要给自己带上一个括号
#define MIN(a,b) ((a)>(b)?(b):(a))
int main()
{
int x;
scanf("%d",&x);
printf("%d\n",CUBE(x));
int a,b;
scanf("%d%d",&a,&b);
printf("MIN=%d\n",MIN(a,b));
    return 0;
}