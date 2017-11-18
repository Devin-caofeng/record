/*
 * 消除了当 more 从管道中读取时不接受用户输入的 bug
 * 在 SeeMore 函数中从 使用 /dev/tty 读取用户输入
 */

#include <iostream>
#include <cstdio>
using namespace std;

int const kPageLen = 24;
int const kLineLen = 512;

int  SeeMore(FILE *fp);
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
