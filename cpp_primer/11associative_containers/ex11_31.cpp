#include "../need.h"


int main() {

    std::multimap<std::string, std::vector<std::string>> authors = {
        { "LiBai", { "JinYeSi", "..." } },
        { "Dufu",  { "LiJiaBie", "ChuiLaoBie", "..." } }
    };

    std::string author_name = "LiBai";
    std::string work = "JinYei";
    auto found = authors.find(author_name);
    auto count = authors.count(author_name);
    while (count) {
        if (std::find(found->second.cbegin(), found->second.cend(), work) !=
            found->second.end()) {
            authors.erase(found);
            break;
        }
        ++found;
        --count;
    }

    for (const auto &author : authors) {
        std::cout << "author: " << author.first;
        std::cout << "  works: ";
        for (const auto &work : author.second) {
            std::cout << work << ' ';
        }
        std::cout << '\n';
    }

    return 0;
}
