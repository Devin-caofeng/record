#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int s) {
        int res = 0;
        findTargetSumWays(nums, s, 0, res);
        return res;
    }

    void findTargetSumWays(vector<int>& nums, int s, size_t start, int& res) {
        if (start >= nums.size()) {
            if (s == 0) ++res;
            return;
        }

        findTargetSumWays(nums, s - nums[start], start + 1, res);
        findTargetSumWays(nums, s + nums[start], start + 1, res);
    }
};

int findTargetSumWays(vector<int>& nums, int S) {
    int n = nums.size();
    vector<unordered_map<int, int>> dp(n + 1);
    dp[0][0] = 1;

    for (int i = 0; i < n; ++i) {
        for (const auto &pr : dp[i]) {
            int sum = pr.first, cnt = pr.second;
            dp[i + 1][sum + nums[i]] += cnt;
            dp[i + 1][sum - nums[i]] += cnt;
        }
    }

    return dp[n][S];
}

int main() {
    return 0;
}
