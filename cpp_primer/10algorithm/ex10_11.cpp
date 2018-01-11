#include "../need.h"

void ElimDups(std::vector<std::string> &v) {
    std::sort(v.begin(), v.end());
    auto iter = std::unique(v.begin(), v.end());
    v.erase(iter, v.end());
}

bool IsShorter(const std::string &s1, const std::string &s2) {
    return s1.size() < s2.size();
}

int main() {

    std::vector<std::string> v = { "the", "quick", "red", "fox", "jumps",
                                   "over", "the", "slow", "red", "turtle" };
    ElimDups(v);
    PrintSeqContainer(v);
    std::stable_sort(v.begin(), v.end(), IsShorter);
    PrintSeqContainer(v);

    return 0;
}
