#include "apue.h"

/*
1. 用户ID。口令文件登录项中的用户ID是一个数值，表示不同的用户。用户ID为0为根用户/超级用户，即root。
2. 组ID。组 被用于将若干用户集合，允许同组内的成员之间共享资源。组文件通常在/etc/group

*/

int main(void){
    printf("uid = %d, gid = %d\n", getuid(), getgid());
    exit(0);
}