#include <stdio.h>
union lianhe{
    int i;
    char p[sizeof(int)];         //联合中，i和p【】共用一处内存，
};
int main()
{
union lianhe t;
t.i=1234;
for(int j=0;j<sizeof(int);j++){
    printf("%02hhx",t.p[j]);    //1234的十六进制为04d2，而计算机的内存是由低位到高位储存的，所以成了d204
}
printf("\n");
    return 0;
}