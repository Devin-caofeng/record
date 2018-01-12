#include "../need.h"

int main() {

    std::ifstream ifs("./note.md");
    std::istream_iterator<std::string> in_iter(ifs), end_iter;
    std::vector<std::string> words;

    std::copy(in_iter, end_iter, back_inserter(words));
    std::copy(words.cbegin(), words.cend(),
              std::ostream_iterator<std::string>(std::cout, "\n"));

    return 0;
}
