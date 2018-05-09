#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximumGap(vector<int> &nums) {
        if (nums.empty()) return 0;

        int mx = nums[0], mn = nums[0], n = nums.size();
        for (const int &val : nums) {
            mx = max(mx, val);
            mn = min(mn, val);
        }

        int size = (mx - mn) / n + 1;
        int bucketNums = (mx - mn) / size + 1;
        vector<int> bucketMin(bucketNums, INT_MAX);
        vector<int> bucketMax(bucketNums, INT_MIN);
        set<int> st;

        for (const int &val : nums) {
            int idx = (val - mn) / size;
            bucketMin[idx] = min(bucketMin[idx], val);
            bucketMax[idx] = max(bucketMax[idx], val);
            st.insert(idx);
        }

        int pre = 0, res = 0;
        for (int i = 1; i < n; ++i) {
            if (!st.count(i)) continue;
            res = max(res, bucketMin[i] - bucketMax[pre]);
            pre = i;
        }

        return res;
    }
};

int main() {
    return 0;
}
