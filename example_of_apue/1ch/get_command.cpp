#include <sys/wait.h>
#include "apue.h"
#include "../apueerror.h"


int main() {

    printf("%% ");         // 显示提示符

    char buf[MAXLINE];     // apue.h 中的宏
    while (fgets(buf, MAXLINE, stdin) != NULL) {
        if (buf[strlen(buf) - 1] == '\n')
            buf[strlen(buf) - 1] = '\0';  // execlp 函数参数要以 NULL 为结尾

        pid_t pid;
        if ((pid = fork()) < 0) {
            err_sys("fork error");
        } else if (pid == 0) {
            execlp(buf, buf, NULL);       // execlp 函数出错时才返回
            err_ret("couldn`t execute: %s", buf);
            exit(127);
        } else {
            int status;                   // 获取子进程中止状态
            if ((pid = waitpid(pid, &status, 0)) < 0)
                err_sys("waitpid error");
            printf("%% ");
        }
    }

    return 0;
}
