#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int n = gas.size();
        int cur_gas = 0;

        for (int i = 0; i < n; ++i) {
            if (gas[i] < cost[i]) continue;

            int j, cnt = 0;
            for (j = i; cnt < n; ++cnt) {
                cur_gas += (gas[j] - cost[j]);
                if (cur_gas < 0) break;
            }

            if (cnt == n) return j;
            if (++j >= n) j = 0;
        }

        return -1;
    }
};

int main() {
    return 0;
}
