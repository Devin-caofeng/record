#include <iostream>
#include <string>
#include "ex13_30.hpp"

class T {
public:
    T() = default;
    T(const T &) = default;
};

int main() {

    HasPtr hp1("hp1"), hp2("hp2");

    swap(hp1, hp2);

    return 0;
}
