#include "../need.h"

int main() {

    std::deque<std::string> deq;
    std::string str;

    while (std::cin >> str) deq.push_back(str);
    for (auto i : deq) std::cout << i << std::endl;

    return 0;
}
