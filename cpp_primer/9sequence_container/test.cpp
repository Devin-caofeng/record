#include "../need.h"

void TestP313() {
    std::forward_list<int> flst{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    auto prev = flst.before_begin();
    auto curr = flst.begin();
    while (curr != flst.end()) {
        if (*curr & 0x1) {
            curr = flst.erase_after(prev);
        }
        else {
            prev = curr;
            ++curr;
        }
    }

    for (auto i : flst) std::cout << i << ' ';
    std::cout << '\n';
}

int main() {

    std::vector<int> vec{ 1, 2, 3, 4 };

    auto iter = vec.begin();
    std::cout << *(iter = vec.insert(iter, 0)) << '\n';

    PrintSeqContainer(vec);

    return 0;
}
