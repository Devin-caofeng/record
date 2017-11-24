#ifndef _UTMP_LIB_H_
#define _UTMP_LIB_H_

#define NUM_RECORDS   16
#define NULL_UT       ((struct utmp *)NULL)
#define UT_SIZE       (sizeof(struct utmp))

int utmp_open(char *filename);

struct utmp * utmp_next();

int utmp_reload();

void utmp_close();

#endif
