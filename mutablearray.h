#ifndef _ARRAY_H_
#define _ARRAY_H_
struct ARRAY{
    int size;
    int* array;
};
struct ARRAY array_creat(int _size);
void array_free(struct ARRAY*a);
int array_size(const struct ARRAY*a);
int* array_at(struct ARRAY*a,int index);
void array_inflate(struct ARRAY*a,int moresize);
#endif