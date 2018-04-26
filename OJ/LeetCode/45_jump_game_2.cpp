#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int jump_2(vector<int> &nums) {
    size_t times = 0, reached = 0, max_dist = 0;
    for (size_t i = 0; i < nums.size(); ++i) {
        if (reached < i) {
            ++times;
            reached = max_dist;
        }
        max_dist = max(max_dist, i + nums[i]);
    }
    return times;
}

int jump(vector<int> &nums) {
    int n = nums.size();
    int step = 0, max_dist = 0;
    for (int i = 0, cur_dist = 0; i <= max_dist && i < n - 1; ++i) {
        cur_dist = max(max_dist, nums[i] + i);
        if (i == max_dist) {
            max_dist = cur_dist;
            ++step;
        }
    }
    return max_dist >= n - 1 ? step : -1;
}

int main() {
    return 0;
}
