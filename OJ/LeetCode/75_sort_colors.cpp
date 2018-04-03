#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void sortColors(vector<int>& nums) {
    int second_idx = nums.size() - 1, zero_idx = 0;
    for (int i = 0; i <= second_idx; ++i) {
        while (nums[i] == 2 && i < second_idx) swap(nums[i], nums[second_idx--]);
        while (nums[i] == 0 && i > zero_idx) swap(nums[i], nums[zero_idx++]);
    }
}

int main() {


    return 0;
}
