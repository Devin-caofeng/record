#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int> &nums) {
        int res = 0;
        unordered_set<int> st(nums.begin(), nums.end());

        for (const int &val : nums) {
            if (!st.count(val)) continue;

            st.erase(val);
            int pre = val - 1, next = val + 1;
            while (st.count(pre)) st.erase(pre--);
            while (st.count(next)) st.erase(next++);

            res = max(res, next - pre - 1);
        }

        return res;
    }
};

class Solution2 {
public:
    int longestConsecutive(vector<int> &nums) {
        int res = 0;
        unordered_map<int, int> mp;

        for (const int &val : nums) {
            if (!mp.count(val)) {
                int left = mp.count(val - 1) ? mp[val - 1] : 0;
                int right = mp.count(val + 1) ? mp[val + 1] : 0;
                int sum = left + right + 1;

                mp[val] = sum;
                mp[val - left] = sum;
                mp[val + right] = sum;

                res = max(res, sum);

            }
        }

        return res;
    }
};

int main() {
    return 0;
}
