#include "../need.h"

int main() {

    std::vector<int> vec{ 1, 2, 3, 4, 5 };
    auto iter = vec.begin();
    while (iter != vec.end()) {
        if (*iter & 0x1) {
            iter = vec.insert(iter, *iter);
            ++iter;
        }
        ++iter;
    }

    PrintSeqContainer(vec);

    return 0;
}
