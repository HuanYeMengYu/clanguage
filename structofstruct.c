#include <stdio.h>
struct dot{
    int x;
    int y;
};
struct line{
    struct dot d1;
    struct dot d2;
};
void f(struct line bian);
int main()
{
struct line bian[]={{{1,1},{5,1}},{{1,6},{5,6}}};
for(int i=0;i<2;i++){
    f(bian[i]);
}
    return 0;
}
void f(struct line bian){
printf("<%d,%d>to<%d,%d>\n",bian.d1.x,bian.d1.y,bian.d2.x,bian.d2.y);
}