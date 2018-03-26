#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using std::string; using std::vector;
using std::cout; using std::endl;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::map<int, int> str_index;
        int cnt = 0;
        for (const auto& iter : strs) {
            str_index[getStrSum(iter)] = cnt;
        }

        vector<vector<string>> ret(cnt, vector<string>());
        for (const auto& iter : strs) {
            ret[str_index[getStrSum(iter)]].push_back(iter);
        }

        return ret;
    }

private:
    int getStrSum(const string& s) {
        int sum = 0;
        for (const auto& ch : s) {
            sum += ch - 'a';
        }
        return sum;
    }
};

int main() {

    return 0;
}
