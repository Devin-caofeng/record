#include "apue.h"
#include "../apueerror.h"

const int kBufSize = 4096;

int main() {

    int n;
    char buf[kBufSize];

    while((n = read(STDIN_FILENO, buf, kBufSize)) > 0) {
        if (write(STDOUT_FILENO, buf, n) != n)
            err_sys("write error");
    }

    if (n < 0)
        err_sys("read error");

    return 0;
}
