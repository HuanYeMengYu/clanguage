#ifndef _LIST_HEAD_
#define _LIST_HEAD_
extern int a;    //声明，告诉编译器在目录下某个文件中定义了一个全局变量a，a便可以在目录下所有文件中使用
#endif           //用条件编译来保证头文件没有被多次引用而导致发生重复定义
//还有一种格式：#if
//                
 //            #else
 //
 //            #endif
 //或者：      #if
 //
 //            #elif
 //
 //            #endif  