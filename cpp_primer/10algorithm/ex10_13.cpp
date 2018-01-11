#include "../need.h"

bool Predicate(const std::string str) {
    return str.size() >= 5;
}

int main() {

    std::vector<std::string> v = { "the", "quick", "red", "fox", "jumps",
                                   "over", "the", "slow", "red", "turtle" };
    PrintSeqContainer(v);
    auto iter = std::partition(v.begin(), v.end(), Predicate);
    PrintByIter(v.begin(), iter);

    return 0;
}
