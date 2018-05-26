#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>> &triangle) {
        int n = triangle.size();
        vector<int> min_len(triangle.back());

        for (int i = n - 2; i >= 0; --i) {
            for (int j = 0; j <= i; ++j) {
                min_len[j] = min(min_len[j], min_len[j + 1]) + triangle[i][j];
            }
        }

        return min_len[0];
    }
};

int main() {
    return 0;
}
