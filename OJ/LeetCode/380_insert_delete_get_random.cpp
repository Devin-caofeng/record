#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class RandomizedSet {
public:
    RandomizedSet() { }

    bool insert(int val) {
        if (unmp.count(val)) return false;

        nums.push_back(val);
        unmp[val] = nums.size() - 1;

        return true;
    }

    bool remove(int val) {
        if (!unmp.count(val)) return false;

        int last = nums.back();
        unmp[last] = unmp[val];

        nums[unmp[val]] = last;
        nums.pop_back();
        unmp.erase(val);

        return true;
    }

    int getRandom() {
        return nums[rand() % nums.size()];
    }

private:
    vector<int> nums;
    unordered_map<int, int> unmp;
};

int main() {
    return 0;
}
