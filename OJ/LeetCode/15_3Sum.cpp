#include "../need.h"

class Solution {
public:
    std::vector<std::vector<int>>
    ThreeSum(std::vector<int> &nums) {
        sort(nums.begin(), nums.end());

        std::vector<std::vector<int>> ret;
        int nums_len = static_cast<int>(nums.size());
        for (int i = 0; i < nums_len - 2; ++i) {
            if (i == 0 || (i > 0 && nums[i] != nums[i - 1])) {
                int low = i + 1;
                int high = nums_len - 1;
                int sum = 0 - nums[i];

                while (low < high) {
                    if (nums[low] + nums[high] == sum) {
                        ret.push_back({nums[i], nums[low], nums[high]});
                        while (low < high && nums[low] == nums[low + 1]) ++low;
                        while (low < high && nums[high] == nums[high-1]) --high;
                        ++low; --high;
                    }
                    else if (nums[low] + nums[high] < sum) {
                        ++low;
                    }
                    else {
                        --high;
                    }
                }
            }
        }

        return ret;
    }
};

int main() {


    return 0;
}
