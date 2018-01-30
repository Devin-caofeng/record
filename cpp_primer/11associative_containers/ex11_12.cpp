#include "../need.h"


int main() {

    std::vector<std::pair<std::string, int>> vec;

    int value;
    std::string str;
    while (std::cin >> str >> value) {
        vec.push_back({str, value});
        // vec.push_back(make_pair(str, value));
        // vec.push_back(std::pair<std::string, int>(str, value));
    }

    for (const auto &kv : vec) {
        std::cout << kv.first << " : " << kv.second << '\n';
    }

    return 0;
}
