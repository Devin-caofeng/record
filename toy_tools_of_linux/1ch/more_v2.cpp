/*
 * 消除了当 more 从管道中读取时不接受用户输入的 bug
 * 在 SeeMore 函数中从 使用 /dev/tty 读取用户输入
 */

#include <iostream>
#include <cstdio>
using namespace std;

int const kPageLen = 24;
int const kLineLen = 512;

int  SeeMore(FILE *fp_cmd);
void DoMore(FILE *fp);

int main(int argc, char *argv[]) {

    if (argc == 1) {
        DoMore(stdin);
    } else {
        while (--argc) {
            FILE *fp = fopen(*++argv, "r");
            if (fp != NULL) {
                DoMore(fp);
                fclose(fp);
            } else {
                exit(1);
            }
        }
    }

    return 0;
}


void DoMore(FILE *fp) {
    char line[kLineLen] = { 0 };
    char num_of_lines = 0;
    FILE *fp_tty = fopen("/dev/tty", "r");

    if (fp_tty == NULL)
        exit(1);

    while (fgets(line, kLineLen, fp)) {
        int reply = 0;
        if (num_of_lines == kPageLen) {
            reply = SeeMore(fp_tty);
            if (reply == 0)
                break;
            num_of_lines -= reply;
        }

        if (fputs(line, stdout) == EOF)
            exit(1);
        ++num_of_lines;
    }
}

int SeeMore(FILE *fp_cmd) {
    printf("\033[7m more?\033[m");
    int c;
    while ((c = getc(fp_cmd)) != EOF) {
        if (c == 'q')
            return 0;
        else if (c == ' ')
            return kPageLen;
        else if (c == '\n')
            return 1;
    }
    return 0;
}
