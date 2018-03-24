#include "./need.h"

void Print() {
    ;
}

template <typename T, typename... Type>
void Print(const T &a, const Type&...args) {
    std::cout << a << '\n';
    Print(args...);
}

int main() {

    Print(1,  2, "fd");

    return 0;
}
