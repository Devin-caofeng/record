#include <cstdio>
#include <cstdlib>
#include <utmp.h>
#include <fcntl.h>
#include <unistd.h>

#define SHOWHOST

void show_info(struct utmp *utbufp);

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
    printf("%-8.8s ", utbufp->ut_name);
    printf("%-8.8s ", utbufp->ut_line);
    printf("%10d ", utbufp->ut_time);

#ifdef SHOWHOST
    printf("(%s)", utbufp->ut_host);
#endif
    printf("\n");
}

