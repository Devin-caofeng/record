#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int res = 0;
        findTargetSumWays(nums, 0, S, res);
        return res;
    }

    void findTargetSumWays(const vector<int>& nums,
                           decltype(nums.size()) i,
                           int S,
                           int& res) {
        if (i > nums.size()) {
            return;
        }

        if (i == nums.size() && S == 0) {
            ++res;
            return;
        }

        findTargetSumWays(nums, i + 1, S - nums[i], res);
        findTargetSumWays(nums, i + 1, S + nums[i], res);
    }

    int findTargetSumWays_1(vector<int>& nums, int S) {
        unordered_map<int, int> dp;
        dp[0] = 1;

        for (int num : nums) {
            unordered_map<int, int> tmp;
            for (auto pr : dp) {
                int cur_sum = pr.first, cnt = pr.second;
                tmp[cur_sum + num] += cnt;
                tmp[cur_sum - num] += cnt;
            }
            dp = tmp;
        }

        return dp[S];
    }
};

int main() {
    return 0;
}
