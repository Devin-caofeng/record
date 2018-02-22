#include <iostream>
#include <string>
#include <memory>

int main() {

    std::unique_ptr<std::string> ptr(new std::string("hello"));

    auto ptr2 = ptr;
    // std::unique_ptr<std::string> ptr2 = ptr;

    std::cout << *ptr << '\n';

    ptr.reset(nullptr);

    return 0;
}
