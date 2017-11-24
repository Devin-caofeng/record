#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <utmp.h>
#include <fcntl.h>
#include <unistd.h>

#define SHOWHOST

void show_info(struct utmp *ut_bufp);
void show_time(long time_val);

int main() {

    int utmpfd;
    if ((utmpfd = open(UTMP_FILE, O_RDONLY)) == -1) {
        perror(UTMP_FILE);
        exit(1);
    }

    struct utmp current_record;
    int reclen = sizeof(current_record);
    while (read(utmpfd, &current_record, reclen) == reclen)
        show_info(&current_record);

    close(utmpfd);

    return 0;
}

void show_info(struct utmp *utbufp) {
    if (utbufp->ut_type != USER_PROCESS)
        return;

    printf("%-8.8s ", utbufp->ut_name);
    printf("%-8.8s ", utbufp->ut_line);
    printf("%10d ", utbufp->ut_time);
    show_time(utbufp->ut_time);

#ifdef SHOWHOST
    if (utbufp->ut_host[0] != '\0')
        printf("(%s)", utbufp->ut_host);
#endif
    printf("\n");
}

void show_time(long time_val) {
    char *cp = ctime(&time_val);      // 把时间转换成字符串
    printf("%12.12s", cp + 4);
}
