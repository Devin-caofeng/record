#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findMin(vector<int> &nums) {
        if (nums.empty()) return 0;

        int left = 0, right = nums.size() - 1, res = nums[0];
        while (left < right - 1) {
            int mid = left + (right - left) / 2;
            if (nums[left] < nums[mid]) {
                res = min(res, nums[left]);
                left = mid + 1;
            }
            else if (nums[left] > nums[mid]) {
                res = min(res, nums[right]);
                right = mid;
            }
            else {
                ++left;
            }
        }

        res = min(res, nums[left]);
        res = min(res, nums[right]);

        return res;
    }

    int findMin_2(vector<int> &nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1 || (n > 1 && nums[0] < nums[n - 1])) return nums[0];

        int i = 0, j = n - 1;
        while (i < j - 1) {
            int mid = i + (j - i) / 2;

            while (i < j && nums[i] == nums[mid]) i++;
            while (i < j && nums[j] == nums[mid]) j--;

            if (nums[i] < nums[mid]) i = mid;
            else if (nums[mid] < nums[j]) j = mid;
        }

        return min(nums[i], nums[j]);
    }
};

int main() {
    return 0;
}
