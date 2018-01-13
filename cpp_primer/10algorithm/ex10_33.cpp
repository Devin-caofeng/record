#include "../need.h"

int main(int argc, char *args[]) {
    if (argc < 4) return -1;

    std::ifstream ifs(args[1]);
    std::ofstream ofs_odd(args[2]);
    std::ofstream ofs_even(args[3]);

    std::istream_iterator<int> in(ifs), eof;
    std::ostream_iterator<int> out_odd(ofs_odd, "\n");
    std::ostream_iterator<int> out_even(ofs_even, "\n");

    while (in != eof) {
        (*in & 0x1) ? (*out_odd++ = *in++) : (*out_even++ = *in++);
    }

    return 0;
}
