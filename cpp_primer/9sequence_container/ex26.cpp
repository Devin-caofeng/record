#include "../need.h"

int main() {

    int ia[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89 };
    std::vector<int> vec(std::begin(ia), std::end(ia));
    std::list<int> lst(std::begin(ia), std::end(ia));

    for (auto iter = lst.begin(); iter != lst.end();) {
        if (*iter & 0x1) iter = lst.erase(iter);
        else ++iter;
    }

    for (auto iter = vec.begin(); iter != vec.end();) {
        if (!(*iter & 0x1)) iter = vec.erase(iter);
        else ++iter;
    }

    for (auto iter : lst) std::cout << iter << ' ';
    std::cout << '\n';
    for (auto iter : vec) std::cout << iter << ' ';
    std::cout << '\n';

    return 0;
}
