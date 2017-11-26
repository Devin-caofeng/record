#include <cstdio>
#include <unistd.h>
#include <utmp.h>
#include <cstring>
#include <fcntl.h>
#include <ctime>

int logout_tty(char *line);

int main() {



    return 0;
}

int logout_tty(char *line) {
    int fd;
    if ((fd = open(UTMP_FILE, O_RDWR)) == -1)
        return -1;

    int ret_val = -1;
    struct utmp record;
    int len = sizeof(record);
    while (read(fd, &record, len) == len) {
        if (strncmp(record.ut_line, line, sizeof(record.ut_line)) == 0) {
            record.ut_type = DEAD_PROCESS;
            if (time(&record.ut_time != -1)) {
                if (lseek(fd, -len, SEEK_CUR) != -1) {
                    if (write(fd, &record, len) == len)
                        ret_val = 0;
                }
            }
            break;
        }
    }

    if (close(fd) == -1)
        ret_val = -1;

    return ret_val;
}
