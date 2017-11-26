#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>


void list(char *);

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

void list(char *dir_name) {
    DIR *dir;
    struct dirent *dir_ent;

    if ((dir = opendir(dir_name)) == NULL) {
        fprintf(stderr, "ls : cannot open %s\n", dir_name);
    } else {
        while ((dir_ent = readdir(dir)) != NULL)
            printf("%s\n", dir_ent->d_name);
       closedir(dir);
    }
}
