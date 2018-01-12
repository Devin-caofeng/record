#include "../need.h"

bool CheckSize(const std::string &str, std::string::size_type len) {
    return str.size() < len;
}

int main() {

    std::vector<int> vec = { 1, 2, 3, 4, 5, 6, 7 };
    std::string str = "google";
    using std::placeholders::_1;
    auto pos = std::find_if(vec.cbegin(), vec.cend(),
                            std::bind(CheckSize, str, _1));

    if (pos != vec.cend()) std::cout << *pos << '\n';
    else std::cout << "not find\n";

    return 0;
}
