#include "../need.h"

int main() {

    std::istream_iterator<int> in(std::cin), eof;
    std::vector<int> vec(in, eof);

    std::sort(vec.begin(), vec.end());
    std::copy(vec.cbegin(), vec.cend(),
              std::ostream_iterator<int>(std::cout, " "));
    std::cout << '\n';

    return 0;
}
