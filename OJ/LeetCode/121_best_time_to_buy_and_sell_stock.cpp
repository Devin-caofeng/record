#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.size() < 2) return 0;

        int ret = 0;
        int min_val = prices[0];
        for (size_t i = 1; i < prices.size(); ++i) {
            min_val = min(min_val, prices[i]);
            ret = max(prices[i] - min_val, ret);
        }

        return ret;
    }
};

int main() {
    return 0;
}
