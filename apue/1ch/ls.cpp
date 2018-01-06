#include <cstdio>
#include <dirent.h>

#include "apue.h"
#include "../apueerror.h"

int main(int argc, char *argv[]) {

    if (argc != 2)
        err_quit("usage: ls directory_name");

    DIR *dp = opendir(argv[1]);
    if (dp == NULL)
        err_sys("can`t open %s", argv[1]);

    struct dirent *dirp;
    while ((dirp = readdir(dp)) != NULL)
        printf("%s\n", dirp->d_name);

    return 0;
}
