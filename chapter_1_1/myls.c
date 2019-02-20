#include "apue.h"
#include <dirent.h>

int main(int argc, char *argv[]){
    DIR *dp;
    struct dirent *dirp;

    printf("%s\n", argv[0]);
    // printf("%s\n", argv[1]);
    printf("\n\n");

    if(argc != 2){
        err_quit("usage: ls directory_name");
    }

    if((dp = opendir(argv[1])) == NULL){
        err_sys("can't open %s", argv[1]);
    }

    while((dirp = readdir(dp)) != NULL){
        printf("%s\n", dirp->d_name);
    }

    closedir(dp);
    exit(0);
}
