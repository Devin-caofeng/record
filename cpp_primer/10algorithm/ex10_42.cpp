#include "../need.h"

void ElimDups(std::list<std::string> &lst) {
    lst.sort();
    lst.unique();
}

int main() {

    std::list<std::string> lst{
        "fox", "google", "apple", "smart", "fox"
    };

    ElimDups(lst);

    PrintSeqContainer(lst);
    PrintByIter(lst.cbegin(), lst.cend());

    return 0;
}
