#include "../need.h"

void TestP341() {
    std::vector<int> v;
    std::fill_n(std::back_inserter(v), 10, 0);

    for (auto i : v) std::cout << i << ' ';
    std::cout << '\n';
}

namespace TestP349 {

void ElimDups(std::vector<std::string> &v) {
    std::sort(v.begin(), v.end());
    auto iter = std::unique(v.begin(), v.end());
    v.erase(iter, v.end());
}

void Biggies(std::vector<std::string> &words,
             std::vector<std::string>::size_type size) {
    ElimDups(words);
    // 按长度排序，长度相同的单词维持字典序
    std::stable_sort(words.begin(), words.end(),
        [](const std::string &str1, const std::string &str2) {
            return str1.size() < str2.size();
        });

    // 获取一个迭代器，指向第一个满足 size() >= sz 的元素
    auto iter = find_if(words.begin(), words.end(),
                    [size](const std::string &str) {
                        return str.size() >= size;
                    });

    // 计算满足 str.size() >= size 的元素数目
    auto count = words.end() - iter;
    std::cout << count << '\n';
    std::for_each(iter, words.end(), [](const std::string &str) {
                                         std::cout << str << ' ';
                                     });
    std::cout << '\n';
}

}

int main() {

//    TestP341();

    // void (*lambda)() = [] {
    //     std::cout << "hello lambda" << '\n';
    // };

    // lambda();

    std::vector<int> vec{ 1, 2, 3 };
    std::ostream_iterator<int> out_iter(std::cout, " ");
    std::copy(vec.cbegin(), vec.cend(), out_iter);
    std::cout << '\n';

    return 0;
}
