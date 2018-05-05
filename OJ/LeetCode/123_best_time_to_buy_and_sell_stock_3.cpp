#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.empty()) return 0;
        int n = prices.size();
        vector<vector<int>> glb(n, vector<int>(3, 0));
        auto loca = glb;

        for (int i = 1; i < n; ++i) {
            int diff = prices[i] - prices[i - 1];
            for (int j = 1; j <= 2; ++j) {
                loca[i][j] = max(glb[i - 1][j - 1] + max(diff, 0),
                                 loca[i - 1][j] + diff);
                glb[i][j] = max(loca[i][j], glb[i - 1][j]);
            }
        }

        return glb[n - 1][2];
    }
};

int main() {
    return 0;
}
