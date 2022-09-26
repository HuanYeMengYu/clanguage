#include <stdio.h>
#include <stdlib.h>
#include "mutablearray.h"

//struct ARRAY{
//    int size;
//    int* array;
//};

const int BLOCK=20;

struct ARRAY array_creat(int _size){
    struct ARRAY a;
    a.size=_size;
    a.array=(int*)malloc(sizeof(int)*a.size);
    return a;
}

void array_free(struct ARRAY* a){
    free(a->array);
    a->array=NULL;
    a->size=0;
}

int array_size(const struct ARRAY*a){    //封装
    return a->size;
}

int* array_at(struct ARRAY*a,int index){
    if(index>=a->size){
        array_inflate(a,(index/BLOCK+1)*BLOCK-a->size);
    }
    return &(a->array[index]);
}

void array_inflate(struct ARRAY*a,int moresize){
    int*p=(int*)malloc(sizeof(int)*(a->size+moresize));
    for(int i=0;i<a->size;i++){
        p[i]=a->array[i];
    }
    free(a->array);
    a->array=p;
    a->size+=moresize;
}

int main()
{
struct ARRAY a=array_creat(100);
int num=0;
int c=0;
while(num!=-1){
    scanf("%d",&num);
    if(num!=-1){
        *array_at(&a,c++)=num;
    }
}
for(int j=0;j<array_size(&a);j++){
printf("%d ",a.array[j]);
}
array_free(&a);
    return 0;
}