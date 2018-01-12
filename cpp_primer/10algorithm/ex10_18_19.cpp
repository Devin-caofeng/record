#include "../need.h"

void ElimDups(std::vector<std::string> &words) {
    std::sort(words.begin(), words.end());
    auto separete = std::unique(words.begin(), words.end());
    words.erase(separete, words.end());
}

void BiggiesEx18(std::vector<std::string> &words,
                 std::string::size_type str_size) {
    ElimDups(words);

    std::sort(words.begin(), words.end(),
        [](const std::string s1, const std::string s2) {
            return s1.size() < s2.size();
    });

    auto separate = std::partition(words.begin(), words.end(),
        [str_size](const std::string str) {
            return str.size() < str_size;
    });

    std::for_each(separate, words.end(),
        [](const std::string str) {
            std::cout << str << ' ';
    });
}

void BigiesEx19(std::vector<std::string> &words,
                std::string::size_type str_size) {
    ElimDups(words);

    std::sort(words.begin(), words.end(),
        [](const std::string s1, const std::string s2) {
            return s1.size() < s2.size();
    });

    auto separate = std::stable_partition(words.begin(), words.end(),
        [str_size](const std::string str) {
            return str.size() < str_size;
    });

    std::for_each(separate, words.end(),
        [](const std::string str) {
            std::cout << str << ' ';
    });
}

int main() {

    std::vector<std::string> words = {
        "fox", "cat", "super", "apple", "google"
    };
    auto cp = words;

    BigiesEx19(words, 3);
    std::cout << '\n';
    BiggiesEx18(cp, 3);
    std::cout << '\n';

    return 0;
}
