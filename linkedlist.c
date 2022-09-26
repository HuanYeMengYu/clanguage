#include <stdio.h>
#include <stdlib.h>
struct node{
    int value;
    struct node *next;
};
int main()
{
struct node *head=NULL;
int num;
do{
    scanf("%d",&num);
    if(num!=-1){
        struct node *p=(struct node *)malloc(sizeof(struct node));
        p->value=num;
        p->next=NULL;
        struct node *last=head;
        if(last){
            while(last->next){
                last=last->next;
            }
            last->next=p;
        }else{
            head=p;
        }
    }
}while(num!=-1);
    return 0;
}