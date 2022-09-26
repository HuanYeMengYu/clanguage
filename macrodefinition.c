#include <stdio.h>
#define PI 3.14159     //#代表宏定义，定义的东西只能是单词，定义的结果是啥都可以。注释不会被定义进去
//注意不是c语言的语句，所以没有分号
//编译之前，会先进行编译预处理，把宏定义进行完全文本替换，即把所有“PI”在文本上替换成3.14159
#define PII 2*PI    //宏定义可以嵌套
#define PAI 3.14159265358979323846264338327950288\
4197169399375105820974944592307816     

//宏定义的值超出一行时，非最后一行的每行末尾要加\表示连接
#define _DEBUG    //宏定义可以没有值
//存在预定义的宏 如 _LINE_的值为所在行的行号
//                _FILE_的值为文件名
//                _DATE_的值为编译该文件的日期
//                _TIME_的值为编译该文件的时间
//                _STDC_的值为1
int main()
{

    return 0;
}