#include "../need.h"
using namespace std;


int main() {

    multimap<string, vector<string>> authors = {
        { "LiBai", { "JinYeSi", "..." } },
        { "Dufu",  { "LiJiaBie", "ChuiLaoBie", "..." } }
    };

    map<string, vector<string>> m = { { "b", { "a" } } };
    map<string, vector<string>>::value_type ath = *m.begin();
    cout << ath.first << '\n';

    // 把作者名按字典序进行排序
    // using ath_type = decltype(authors)::value_type;
    sort(authors.begin(), authors.end(),
        [](const map<string, vector<string>>::value_type &ath1,
           const map<string, vector<string>>::value_type &ath2) {
            return ath1.first < ath2.first;
    });

    vector<int> vec = { 5, 4, 3 };
    sort(vec.begin(), vec.end(), [](int n1, int n2){ return n1 < n2; });
    PrintSeqContainer(vec);

    // 作品按字典序进行排序
    for (auto &author : authors) {
        sort(author.second.begin(), author.second.end());
    }

    // for (const auto &author : authors) {
    //     cout << "author: " << author.first;
    //     cout << "  works: ";
    //     for (const auto &work : author.second) {
    //         cout << work << ' ';
    //     }
    //     cout << '\n';
    // }

    return 0;
}
