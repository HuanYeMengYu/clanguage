#include <stdio.h>
#include <string.h>
#include <errno.h>

//常见的文件操作函数
//1.FILE *fopen(“文件名.文件格式”,打开模式) 返回文件地址
//2.int fclose(文件地址) 成功返回0失败返回-1
//3.size_t(类似于整型) fread(文件读取的地址,单个数据的字节量,数据量,文件地址)返回数据量
//4.size_t fwrite(文件写入的地址,单个数据的字节量,数据量,文件地址)返回数据量
//5.int fgetc(文件地址)返回该字符的ASCII码
//6.int fputc(字符，文件地址)返回该字符的ASCII码
//7.char *fgets(每次读取一行)(缓冲区地址，n（最多读取n-1个字符），文件地址)返回缓冲区地址
//8.int fputs(字符地址，文件地址)成功返回0，失败返回-1
//9.int fprintf(文件地址，"%d %s %s %d",a,b,c,d)返回输入文件的字节数
//10.int fscanf(文件地址，"%d %s %d ",a,b,c)返回读取的字符数（3）
//11.long ftell(文件地址)返回指针处距离文件开头的字节数
//12.int fseek(文件地址，偏移的字节数，int whence开始偏移的点)
                      //whence一般为SEEK_SET(值为0)、SEEK_CUR(值为1)、SEEK_END(值为2)
//13.rewind(文件地址) 无返回值

//fopen函数的打开模式：r只读、w只写、a追加
//如果无该文件r报错，而w可以创建，并且用w会直接把之前的文件清空
//a从文件末端开始加

int main()
{
  FILE *pf=fopen("test.txt","w");
  if(pf==NULL)//一般在fopen()后作错误判断及处理
  {
    printf("%s\n",strerror(errno)); //字符串函数
    return 0;
  }
  fputc('f',pf);
  fputc('u',pf);
  fputc('c',pf);
  fputc('k',pf);
  fputc('y',pf);
  fputc('o',pf);
  fputc('u',pf);
  fclose(pf);
  pf=NULL;//指针使用完要指向NULL
  return 0;
}
