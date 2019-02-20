#include "apue.h"
#include <sys/wait.h>

/*
1. fork跟随exec，两者的组合就是某些操作系统所称的产生(spawn)一个新进程。Unix中，这两部分分离成两个独立的函数。
*/

int main(void){
    char buf[MAXLINE];
    pid_t pid;
    int status;

    printf("%% ");
    while(fgets(buf, MAXLINE, stdin) != NULL){
        if(buf[strlen(buf) - 1] == '\n'){
            buf[strlen(buf) - 1] = 0;
        }

        if((pid = fork()) < 0){
            err_sys("fork error");
        }else if(pid == 0){
            // printf("============ ID %ld", (long)getpid());
            execlp(buf, buf, (char *)0);
            err_sys("couldn't execute: %s", buf);
            exit(127);
        }

        if((pid =  waitpid(pid, &status, 0)) < 0){
            err_sys("waitpid error");
        }
        printf("%% ");
    }
    exit(0);

}