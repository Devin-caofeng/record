#include <iostream>
#include <string>
#include <cstring>
#include <memory>

void InputReverseOutputString(int n) {
    std::allocator<std::string> alloc;
    auto const ptr = alloc.allocate(n);

    std::string s;
    auto curr = ptr;
    while (curr != ptr + n && std::cin >> s) {
        alloc.construct(curr++, s);
    }

    while (curr != ptr) {
        std::cout << *--curr << ' ';
        alloc.destroy(curr);
    }
    std::cout << '\n';

    alloc.deallocate(ptr, n);
}

int main() {

    InputReverseOutputString(3);

    return 0;
}


