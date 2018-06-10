#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int rows = matrix.size();
        int cols = rows > 0 ? matrix[0].size() : 0;
        vector<vector<int>> dp(rows + 1, vector<int>(cols + 1, 0));

        int max_edge = 0;
        for (int i = 1; i <= rows; ++i) {
            for (int j = 1; j <= cols; ++j) {
                if (matrix[i - 1][j - 1] == '1') {
                    dp[i][j] = min({ dp[i][j - 1],
                                     dp[i - 1][j],
                                     dp[i - 1][j - 1] }) + 1;
                    max_edge = max(max_edge, dp[i][j]);
                }
            }
        }

        return max_edge * max_edge;
    }

    int maximalSquare_optimizeSpaceV(vector<vector<char>>& matrix) {
        int rows = matrix.size();
        int cols = rows > 0 ? matrix[0].size() : 0;
        vector<int> dp(cols + 1, 0);

        int max_edge = 0, previous = 0;
        for (int i = 1; i <= rows; ++i) {
            for (int j = 1; j <= cols; ++j) {
                int tmp = dp[j];
                if (matrix[i - 1][j - 1] == '1') {
                    dp[j] = min({ dp[j - 1], previous, dp[j] }) + 1;
                    max_edge = max(max_edge, dp[j]);
                }
                else {
                    dp[j] = 0;
                }
                previous = tmp;
            }
        }

        return max_edge * max_edge;
    }
};

int main() {
    return 0;
}
