#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0, fast = 0, t = 0;
        while (true) {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if (slow == fast) break;
        }

        while (true) {
            slow = nums[slow];
            t = nums[t];
            if (slow == t) break;
        }

        return slow;
    }

    int findDuplicate_binarySearch(vector<int>& nums) {
        int low = 1, high = nums.size() - 1;
        while (low < high) {
            int mid = low + (high - low) / 2;
            int cnt = 0;
            for (int num : nums) {
                if (num <= mid) ++cnt;
            }

            if (cnt <= mid) low = mid + 1;
            else high = mid;
        }

        return low;
    }
};

int main() {
    return 0;
}
