#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using std::string; using std::vector;
using std::cout; using std::endl;

bool canJump(vector<int>& nums) {
    size_t n = nums.size();
    for (size_t i = 0, max_val = 0; i <= max_val; ++i) {
        if ((max_val = std::max(max_val, i + nums[i])) >= n - 1) return true;
    }
    return false;
}

int main() {

    vector<int>vec{ 0 };
    cout << canJump(vec) << endl;;

    return 0;
}
