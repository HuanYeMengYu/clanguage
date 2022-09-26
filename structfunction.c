#include <stdio.h>
#include <stdbool.h>
struct date{
    int month;
    int day;
    int year;
}today,tomorrow;
bool run(struct date today);  //bool类型代表判断true/false
int lastday(struct date today);
int main()
{
scanf("%d %d %d",&today.month,&today.day,&today.year);
if(today.day!=lastday(today)){
tomorrow.year=today.year;
tomorrow.month=today.month;
tomorrow.day=today.day+1;
}else if(today.month=12){
tomorrow.year=today.year+1;
tomorrow.month=1;
tomorrow.day=1;
}else{
tomorrow.year=today.year;
tomorrow.month=today.month+1;
tomorrow.day=1;
}
printf("tomorrow is %d-%d-%d",tomorrow.month,tomorrow.day,tomorrow.year);
    return 0;
}

int lastday(struct date today){//注意与数组不同，结构的函数只是传值而不是指针结构
                                  //（新申请、克隆了一个一模一样的结构）
int monthday[12]={31,28,31,30,31,30,31,31,30,31,30,31};   //传结构给函数，函数里不能改变结构里的值
int lastday;
if(today.month=2&&run(today)){
lastday=29;
}else{
    lastday=monthday[today.month-1];
}
return lastday;
}

bool run(struct date today){
    bool run=false;
    if(today.year%4==0){
        run=true;
    }
    return run;
}
                