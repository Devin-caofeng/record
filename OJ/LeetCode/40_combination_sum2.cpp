#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using std::vector;
using std::string;

class Solution {
public:
    vector<vector<int>> CombinationSum2(vector<int> &nums, int target) {
        vector<vector<int>> res;
        std::sort(nums.begin(), nums.end());
        vector<int> local;
        FindCombinationSum2(res, 0, target, local, nums);

        return res;
    }

    void FindCombinationSum2(vector<vector<int>> &res, const size_t order,
                             const int target, vector<int> &local,
                             const vector<int> &num) {
        if (target == 0) {
            res.push_back(local);
            return;
        }

        for (size_t i = order; i < num.size(); ++i) {
            if (num[i] > target) return;
            if (i && num[i] == num[i - 1] && i > order) continue;
            local.push_back(num[i]);
            FindCombinationSum2(res, i + 1, target - num[i], local, num);
            local.pop_back();
        }
    }
};

void DFS(const vector<int> &num, vector<vector<int>> &ret, int target,
         vector<int> cur, size_t start) {

}

int main() {


    return 0;
}
