#include <cstdio>
#include <cstdlib>
#include <string>
#include <unistd.h>
#include <fcntl.h>
using namespace std;

#define BUFFR_SIZE   4096
#define COPY_MODE    0644

void oops(string , string );

int main(int argc, char *argv[]) {

    if (argc != 3) {
        fprintf(stderr, "usage: %s source destination\n", *argv);
        exit(1);
    }

    int in_fd;
    if((in_fd = open(argv[1], O_RDONLY)) == -1)
        oops("Cannot open", argv[1]);

    int out_fd;
    if ((out_fd = creat(argv[2], COPY_MODE)) == -1)
        oops("Cannot create", argv[2]);

    int n_chars;
    char buf[BUFFR_SIZE];
    while ((n_chars = read(in_fd, buf, BUFFR_SIZE)) > 0) {
        if (write(out_fd, buf, n_chars) != n_chars)
            oops("Write error to", argv[2]);
    }

    if (n_chars == -1)
        oops("Read error from", argv[1]);

    if (close(in_fd) == -1 || close(out_fd) == -1)
        oops("Error closing files", "");

    return 0;
}

void oops(string s1, string s2) {
    fprintf(stderr, "Error: %s", s1.c_str());
    perror(s2.c_str());
    exit(1);
}
