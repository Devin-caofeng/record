#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <unistd.h>
#include <sys/types.h>
#include <utmp.h>
#include <fcntl.h>
#include "utmplib.h"

#define SHOW_HOST

void show_info(struct utmp *);
void show_time(time_t);

struct utmp * utmp_next();

int main() {

    if (utmp_open(UTMP_FILE) == -1) {
        perror(UTMP_FILE);
        exit(1);
    }

    struct utmp *ut_buf;
    while ((ut_buf = utmp_next()) != ((struct utmp *)NULL))
        show_info(ut_buf);

    utmp_close();

    return 0;
}

void show_info(struct utmp *utbufp) {
    if (utbufp->ut_type != USER_PROCESS)
        return;

    printf("%-8.8s ", utbufp->ut_name);
    printf("%-8.8s ", utbufp->ut_line);
    printf("%10d ", utbufp->ut_time);

#ifdef SHOWHOST
    if (utbufp->ut_host[0] != '\0')
        printf("(%s)", utbufp->ut_host);
#endif
    printf("\n");
}
