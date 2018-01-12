#include "../need.h"

void ElimDups(std::vector<std::string> &v) {
    std::sort(v.begin(), v.end());
    auto iter = std::unique(v.begin(), v.end());
    v.erase(iter, v.end());
}

void Biggies(std::vector<std::string> &words,
             std::vector<std::string>::size_type str_size) {
    ElimDups(words);

    std::stable_sort(words.begin(), words.end(),
        [](const std::string &str1, const std::string &str2) {
            return str1.size() < str2.size();
        });

    auto separate = std::find_if(words.begin(), words.end(),
                        [str_size](const std::string &str) {
                            return str.size() >= str_size;
                        });

    std::for_each(separate, words.end(), [](const std::string &str) {
                                             std::cout << str << " ";
                                         });
}

int main() {

    std::vector<std::string> words = {
        "fox",
        "separate",
        "like",
        "me",
        "fork"
    };

    Biggies(words, 3);
    std::cout << '\n';

    return 0;
}
