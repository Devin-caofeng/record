#include "../need.h"

int main() {

    std::vector<int> vec{ 1, 2, 3 };
    auto iter = vec.begin();
    while (iter != vec.end()) {
        ++iter;
        /*iter = */vec.insert(iter, 42);
        ++iter;
    }

    for (auto i : vec) std::cout << i << '\n';
    std::cout << '\n';

    return 0;
}
