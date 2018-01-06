#include "../need.h"

int main() {

    std::vector<int> vec;

    std::cout << vec.at(0) << std::endl;
    std::cout << vec[0] << std::endl;
    std::cout << vec.front() << std::endl;
    std::cout << *vec.begin() << std::endl;

    return 0;
}
