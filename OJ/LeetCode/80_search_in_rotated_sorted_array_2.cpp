#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool search(vector<int>& nums, int target) {
    if (nums.empty()) return false;

    for (int l = 0, r = nums.size() - 1; l <= r; ) {
        int m = l + (r - l) / 2 ;
        if (target == nums[m] || target == nums[l] || target == nums[r]) {
            return true;
        }
        else if ((nums[l] < nums[m] && target > nums[l] && target < nums[m]) ||
                 (nums[l] > nums[m] && target > nums[l])) {
            r = m - 1;
        }
        else if ((nums[m] < nums[r] && target > nums[m] && target < nums[r]) ||
                 (nums[m] > nums[r] && target < nums[r])) {
            l = m + 1;
        }
        else {
            ++l;
            --r;
        }
    }
    return false;
}

int main() {
    return 0;
}
