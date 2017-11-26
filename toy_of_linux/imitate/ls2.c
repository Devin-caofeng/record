#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <time.h>
#include <string.h>
#include <pwd.h>
#include <grp.h>


void list(const char *);
void getStatus(const char *);
void showFileInfo(const char *, const struct stat *);
void modeToLetters(const int, char *);
char * uidToName(const uid_t);
char * gidToName(const gid_t);


int main(int argc, char *argv[]) {

    if (argc == 1) {
        list(".");
    } else {
        while (--argc) {
            printf("%s:\n", *++argv);
            list(*argv);
        }
    }

    return 0;
}


void list(const char *dir_name) {
    DIR *dir;
    struct dirent *dir_entry;

    if ((dir = opendir(dir_name)) == NULL) {
        fprintf(stderr, "ls: cannot open %s\n", dir_name);
    } else {
        while ((dir_entry = readdir(dir)) != NULL)
            getStatus(dir_entry->d_name);
        closedir(dir);
    }
}

void getStatus(const char *file_name) {
    struct stat info;

    if (stat(file_name, &info) == -1)
        perror(file_name);
    else
        showFileInfo(file_name, &info);
}

void showFileInfo(const char *file_name, const struct stat *info) {
    char mode[11];
    modeToLetters(info->st_mode, mode);

    printf("%s", mode);
    printf("%4ld ", (long)info->st_nlink);
    printf("%s ", uidToName(info->st_uid));
    printf("%s ", gidToName(info->st_uid));
    printf("%8ld ", (long)info->st_size);
    printf("%.12s ", 4 + ctime(&info->st_mtime));
    printf("%s\n", file_name);
}

void modeToLetters(const int mode, char *str) {
    strcpy(str, "----------");

    if (S_ISDIR(mode))
        str[0] = 'd';
    if (S_ISCHR(mode))
        str[0] = 'c';
    if (S_ISBLK(mode))
        str[0] = 'b';

    if (mode & S_IRUSR)
        str[1] = 'r';
    if (mode & S_IWUSR)
        str[2] = 'w';
    if (mode & S_IXUSR)
        str[3] = 'x';

    if (mode & S_IRGRP)
        str[4] = 'r';
    if (mode & S_IWGRP)
        str[5] = 'w';
    if (mode & S_IXGRP)
        str[6] = 'x';

    if (mode & S_IROTH)
        str[7] = 'r';
    if (mode & S_IWOTH)
        str[8] = 'w';
    if (mode & S_IXOTH)
        str[9] = 'x';
}

char * uidToName(const uid_t uid) {
    struct passwd *pw;
    static char num[10];

    if ((pw = getpwuid(uid)) == NULL) {
        sprintf(num, "%d", uid);
        return num;
    } else {
        return pw->pw_name;
    }
}

char *gidToName(const gid_t gid) {
    struct group *grp;
    static char num[10];

    if ((grp = getgrgid(gid)) == NULL) {
        sprintf(num, "%d", gid);
        return num;
    } else {
        return grp->gr_name;
    }
}
