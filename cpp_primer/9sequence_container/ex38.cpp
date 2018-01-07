#include "../need.h"

int main() {

    std::vector<int> vec;

    const int size = 100;
    for (int i = 0; i < size; ++i) {
        std::cout << "size: " << vec.size() << ' ';
        std::cout << "capacity: " << vec.capacity() << '\n';
        vec.push_back(0);
    }

    return 0;
}
