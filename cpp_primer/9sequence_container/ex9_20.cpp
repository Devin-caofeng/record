#include "../need.h"

int main() {

    std::list<int> lst{ 1, 2, 3, 4, 5 };
    std::deque<int> deq1;
    std::deque<int> deq2;

    int flag = 1;
    for (auto i : lst) {
        flag > 0 ? deq1.push_back(i) : deq2.push_back(i);
        flag = -flag;
    }

    for (auto i : deq1) std::cout << i << std::endl;
    for (auto i : deq2) std::cout << i << std::endl;

    return 0;
}
