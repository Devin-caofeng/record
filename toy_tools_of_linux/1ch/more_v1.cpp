#include <iostream>
#include <cstdio>
using namespace std;

const int kPageLen = 24;
const int kLineLen = 512;

void DoMore(FILE *fp);
int  SeeMore();

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
    char line[kLineLen];
    int num_of_lines = 0;

    while (fgets(line, kLineLen, fp)) {    // 每次读取 kLineLen 字节
        int reply = 0;
        if (num_of_lines == kPageLen) {
            reply = SeeMore();             // 是否继续查看
            if (reply == 0)                // 不需要继续查看
                break;                     // 结束
            num_of_lines -= reply;
        }

        if (fputs(line, stdout) == EOF)
            exit(1);
        ++num_of_lines;
    }
}

int SeeMore() {
    printf("\033[7m more?\033[m");         // 反白显示 more?
    int c;
    while ((c = getchar()) != EOF) {
        if (c == 'q')
            return 0;
        else if (c == ' ')
            return kPageLen;
        else if (c == '\n')
            return 1;
    }
    return 0;
}
