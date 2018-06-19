#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int> &nums) {
        vector<int> lis;

        for (auto num : nums) {
            auto iter = lower_bound(lis.begin(), lis.end(), num);

            if (iter == lis.end()) lis.push_back(num);
            else *iter = num;
        }

        return lis.size();
    }
};

int main() {
    return 0;
}
