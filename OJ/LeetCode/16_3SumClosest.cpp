#include "../need.h"

class Solution {
    public:
        int ThreeSumClosest(std::vector<int> &nums, int target) {
            sort(nums.begin(), nums.end());

            int closest = 0;
            int nums_len = static_cast<int>(nums.size());
            for (int i = 0; i < nums_len - 2; ++i) {
                if (i == 0 || (i > 0 && nums[i] != nums[i - 1])) {
                    int low = i + 1;
                    int high = nums_len - 1;
                    int ret = target - nums[i];

                    while (low < high) {
                        int sum = nums[low] + nums[high];
                        if (sum == ret) {
                            return target;
                        }
                        else if (nums[low] + nums[high] < ret) {
                            closest = abs(closest) > abs(sum)
                                      ? ret - sum : closest;
                            ++low;
                        }
                        else {
                            closest = abs(closest) > abs(sum)
                                      ? ret - sum: closest;
                            --high;
                        }
                    }
                }
            }

            return target - closest;
        }
};

int main() {


    return 0;
}
