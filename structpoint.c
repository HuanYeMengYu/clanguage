#include <stdio.h>
struct point{
    int x;
    int y;
};
struct point* getstruct(struct point*p);
void output(struct point t);
void print(struct point* p);
int main()
{
struct point t={0,0};
getstruct(&t);
output(t);
output(*getstruct(&t));       //发生了函数的嵌套
print(getstruct(&t));
    return 0;
}
struct point* getstruct(struct point*p){
    scanf("%d",&p->x);     //注意此处没有*了
    scanf("%d",&p->y);     //注意此处要有&
    printf("%d,%d\n",p->x,p->y);
    return p;
}
void output(struct point t){
    printf("%d,%d\n",t.x,t.y);
}
void print(struct point* p){
    printf("%d,%d\n",p->x,p->y);
}