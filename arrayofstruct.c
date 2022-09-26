#include <stdio.h>

struct time{
    int hour;
    int minute;
    int second;
};

struct time update(struct time now);

int main()
{
struct time testtime[5]={
{11,59,59},{12,0,0},{1,29,59},{23,59,59},{19,12,27}
};
for(int i=0;i<5;i++){
    printf("now is %d-%d-%d,",testtime[i].hour,testtime[i].minute,testtime[i].second);
    testtime[i]=update(testtime[i]);
    printf("next second is %d-%d-%d\n",testtime[i].hour,testtime[i].minute,testtime[i].second);
}
    return 0;
}

struct time update(struct time now){
    now.second++;
    if(now.second==60){
        now.minute++;
        now.second=0;
        if(now.minute==60){
            now.hour++;
            now.minute=0;
            if(now.hour==24){
                now.hour=0;
            }
        }
    }
    return now;
}