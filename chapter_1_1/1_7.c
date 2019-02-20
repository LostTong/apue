#include "apue.h"
#include<errno.h>
/*
1. extern; extern "C"
2. errno两条规则：1)如果没出错，其值不会被清除；2)任何函数都不将errno值设置为0，而且在<errno.h>中定义的所有常量都不为0 
3. char strerror(int errnum); strerror函数将errnum映射为一个出错消息字符串，并且返回此字符串的指针。
4. void perror(const char *msg); perror输出msg指向的指针，然后是一个冒号，一个空格，errno对应的出错消息，最后是一个换行符。
*/

int main(int argc, char *argv[]){
    fprintf(stderr, "EACCES: %s\n", strerror(EACCES));
    errno = ENOENT;
    perror(argv[0]);
    exit(0);
}