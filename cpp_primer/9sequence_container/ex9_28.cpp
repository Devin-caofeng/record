#include "../need.h"

void InsertToFLst(std::forward_list<std::string> &flst,
                  const std::string &to_find,
                  const std::string &to_add) {
    auto prev = flst.before_begin();
    for (auto curr = flst.begin(); curr != flst.end(); ++curr) {
        if (*curr == to_find) {
            flst.insert_after(curr, to_add);
            return;
        }
        prev = curr;
    }
    flst.insert_after(prev, to_add);
}

int main() {

    std::forward_list<std::string> flst{ "tom", "jack" };

    InsertToFLst(flst, "ben", "love");
    for (auto i : flst) std::cout << i << ' ';
    std::cout << '\n';

    flst = { "tom", "jack" };
    InsertToFLst(flst, "tom", "love");
    for (auto i : flst) std::cout << i << ' ';
    std::cout << '\n';

    return 0;
}
