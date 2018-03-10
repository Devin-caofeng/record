#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using std::vector;
using std::string;

int MaximumSubarray(const vector<int> &nums) {
    size_t len = nums.size();
    vector<int> max_part(len);
    max_part[0] = nums[0];
    int max = max_part[0];

    for (size_t i = 1; i < len; ++i) {
        max_part[i] = nums[i] + ((max_part[i - 1] > 0) ? max_part[i - 1] : 0);
        max = std::max(max, max_part[i]);
    }
    return max;
}


int main() {



    return 0;
}
