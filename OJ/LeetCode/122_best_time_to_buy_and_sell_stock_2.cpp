#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int ret = 0;

        for (size_t i = 1; i < prices.size(); ++i) {
            int tmp = prices[i] - prices[i - 1];
            if (tmp > 0) ret += tmp;
        }

        return ret;
    }
};

int main() {
    return 0;
}
