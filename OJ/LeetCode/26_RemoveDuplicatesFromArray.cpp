#include "../need.h"
using namespace std;

class Solution {
public:
    int RemoveDuplicates(vector<int> &nums) {
        auto i = nums.begin(), j = nums.begin();
        for (; i != prev(nums.end()); ++i, ++j) {
            while (*i == *next(i)) ++i;
            *i = *j;
        }

        return distance(nums.begin(), i);
    }
};

int main() {



    return 0;
}
