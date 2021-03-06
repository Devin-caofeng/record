#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int> &nums) {
        int res = nums[0];

        for (size_t i = 1; i < nums.size(); ++i) {
            res ^= nums[i];
        }

        return res;
    }
};

int main() {
    return 0;
}
