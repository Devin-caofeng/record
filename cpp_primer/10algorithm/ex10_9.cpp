#include "../need.h"

void ElimDups(std::vector<std::string> &v) {
    std::sort(v.begin(), v.end());
    auto iter = std::unique(v.begin(), v.end());
    v.erase(iter, v.end());
}

int main() {

    std::vector<std::string> v = { "a", "b", "c", "c", "d" };
    PrintSeqContainer(v);
    ElimDups(v);
    PrintSeqContainer(v);

    return 0;
}
