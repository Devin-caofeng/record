#include "../need.h"

std::istream &Print(std::istream &is) {
    std::string s;
    while (is >> s) std::cout << s << std::endl;

    is.clear();
    return is;
}

int main() {


    return 0;
}
