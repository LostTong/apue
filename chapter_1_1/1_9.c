#include "apue.h"
#include <sys/wait.h>

/*
1. 信号(signal)用于通知进程发生了某种情况。
2. 3中处理信号的方式：1)忽略；2)安系统默认处理；3)提供一个函数，信号发生时调用该函数，这被称为 捕捉信号。
3. 终端键盘上有两种产生信号的方法：中断键(Ctrl+C)和退出键(Ctrl+\)。
4. 调用kill函数产生信号。例如在进程A中调用kill可向进程B发送一个信号，但这要求是B的所有者或超级用户。
*/

static void sig_int(int);

int main(void){
    char buf[MAXLINE];
    pid_t pid;
    int status;

    if(signal(SIGINT, sig_int) == SIG_ERR){
        err_sys("singal error");
    }

    printf("%% ");
    while(fgets(buf, MAXLINE, stdin) != NULL){
        if(buf[strlen(buf) - 1] == '\n'){
            buf[strlen(buf) - 1] = 0;
        }
        
        if((pid = fork()) < 0){
            err_sys("fork error");
        }else if(pid == 0){
            execlp(buf, buf, (char *)0);
            err_ret("couldn't execute:%s", buf);
            exit(127);
        }

        if((pid == waitpid(pid, &status, 0)) < 0){
            err_sys("waitpid error");
        }
        printf("%% ");
    }
    exit(0);
}

void sig_int(int signo){
    printf(" interrupt\n%% ");
}