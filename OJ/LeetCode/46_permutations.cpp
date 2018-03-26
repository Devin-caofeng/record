#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using std::vector;
using std::string;

class Solution {
public:
    vector<vector<int>> permute(vector<int> &num) {
        vector<vector<int>> result;
        permuteCore(num, 0, result);
        return result;
    }

    void permuteCore(vector<int> &num, size_t begin,
                     vector<vector<int>> &result) {
        if (begin >= num.size()) {
            result.push_back(num);
            return;
        }

        for (size_t i = begin; i < num.size(); ++i) {
            std::swap(num[begin], num[i]);
            permuteCore(num, begin + 1, result);
            std::swap(num[begin], num[i]);
        }
    }
};

int main() {



    return 0;
}
