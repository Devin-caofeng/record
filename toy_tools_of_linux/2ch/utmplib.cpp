#include <cstdio>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <utmp.h>
#include "utmplib.h"

static char utmp_buf[NUM_RECORDS * UT_SIZE];
static int  num_records;
static int  cur_record;
static int  fd_utmp = -1;

int utmp_open(char *filename) {
    fd_utmp = open(filename, O_RDONLY);
    cur_record = num_records = 0;

    return fd_utmp;
}

struct utmp * utmp_next() {
    if (fd_utmp == -1)
        return NULL_UT;

    if (cur_record == num_records && utmp_reload() == 0)
        return NULL_UT;

    struct utmp *record = (struct utmp *)&utmp_buf[cur_record * UT_SIZE];
    ++cur_record;

    return record;
}

int utmp_reload() {
    int amt_read = read(fd_utmp, utmp_buf, NUM_RECORDS * UT_SIZE);
    num_records = amt_read / UT_SIZE;
    cur_record = 0;

    return num_records;
}

void utmp_close() {
    if (fd_utmp != -1)
        close(fd_utmp);
}
