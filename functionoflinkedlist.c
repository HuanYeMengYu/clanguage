#include <stdio.h>
#include <stdlib.h>

struct node{     //定义链表的一个节点
    int value;
    struct node *next;
};

struct list{            //封装
struct node *head;     //相当于一个二级指针，用LIST来改变head。   用结构而不是直接传&head是为了工程效率
};

void add(struct list* plist,int num);  //给链表增加节点的函数
void print(struct list* plist);    //打印链表的函数

int main()
{
struct list LIST;
LIST.head=NULL;
int num;
do{
    scanf("%d",&num);
    if(num!=-1){
        add(&LIST,num);       //如果直接传head，只是传了head的值，在函数里不能改变head
    }
}while(num!=-1);

print(&LIST);

scanf("%d",&num);            //链表的查找
struct node *p;          
int isfound=0;
for(p=LIST.head;p;p=p->next){
    if(p->value==num){
        printf("找到了\n");
        isfound=1;
        break;
    }
}
if(!isfound){
        printf("没找到\n");
    }    

struct node* q;            //将找到的节点删除并重连链表
for(q=NULL,p=LIST.head;p;q=p,p=p->next){
    if(p->value==num){
        if(q){
            q->next=p->next;
        }else{
            LIST.head=p->next;
        }
        free(p);
        break;
    }
}

print(&LIST);        //检验是否删除

for(p=LIST.head;p;p=q){           //链表的清除
q=p->next;
free(p);
}
    return 0;
}

void add(struct list *plist,int num){         //给链表增加节点的函数
struct node *p=(struct node *)malloc(sizeof(struct node));
        p->value=num;
        p->next=NULL;
        struct node *last=plist->head;
        if(last){
            while(last->next){
                last=last->next;
            }
            last->next=p;
        }else{
            plist->head=p;
        }
}

void print(struct list* plist){      //链表的输出函数
    struct node *p;
    for(p=plist->head;p;p=p->next){
        printf("%d ",p->value);
    }
    printf("\n");
}