#include <stdio.h>
//结构可以声明在函数内外，体现不同的范围
//结构的三种定义方式：
//   struct{                                         struct p{                struct p{
//         int x;                                          int x;                  int x;
//         int y;                                          int y;                  int y;
//          }p1,p2;表示除了p1 p2不再需要该结构              }p1,p2;                       }
//                                                                            struct p a;

//              结构变量本身的值是第一个成员的值！！！！！！！！

struct p{       
    int year;                         
    int month;
    int day;
}p1,p2;//注意结构不是函数，需要有分号
int main()
{                           
struct p today;              //结构初始化的方法
today.year=2022;             ///    .  是用来访问的运算符
today.month=8;
today.day=16;
printf("today is %d-%d-%d\n",today.year,today.month,today.day);
struct p tomorrow={2022,8,17};
struct p nextmonth={.year=2022,.month=8};
printf("nextmonth is %d-%d-%d\n",nextmonth.year,nextmonth.month,nextmonth.day);  
//与数组一样，未赋值的量默认为0
p1=(struct p){2032,8,16};   //把2022 8 16 这三个值强制类型转换为结构
p2=p1;  //相当于把p1拷贝给p2，说明结构不是const，与数组不同。并且结构的名字也不是地址
return 0;          
}