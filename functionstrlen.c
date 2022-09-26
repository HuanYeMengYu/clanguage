#include <stdio.h>
#include <string.h>
int main()               //size_t strlen(const char *p),const保证函数里不改变数组。strlen的类型为size_t
{                        //size_t相当于unsigned  int
	char a[]="Hello";
	printf("strlen=%lu\n",strlen(a));          //strlen的作用是得出字符串的长度
	printf("sizeof(a)=%lu\n",sizeof(a));
	return 0;
}