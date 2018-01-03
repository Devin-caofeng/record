#include "../need.h"

void ReadFileToVec(const std::string &filename,
                   std::vector<std::string> &strs) {
    std::ifstream ifs{filename};
    if (ifs) {
        std::string buf;
        while (getline(ifs, buf)) strs.push_back(buf);
    }
}

int main() {

    std::string filename{"c1.cpp"};
    std::vector<std::string> strs;
    ReadFileToVec(filename, strs);

    // std::vector<std::string> strs;
    // std::ifstream input{"c1.cpp"};

    // std::string str;
    // while (getline(input, str)) strs.push_back(str);

    for (auto iter : strs) std::cout << iter << '\n';

    return 0;
}
