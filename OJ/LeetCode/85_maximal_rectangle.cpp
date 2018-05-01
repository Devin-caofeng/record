#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>> &matrix) {
        int res = 0;
        vector<int> heights;
        for (int i = 0; i < matrix.size(); ++i) {
            heights.resize(matrix[i].size());
            for (int j = 0; j < matrix[i].size(); ++j) {
                heights[j] = matrix[i][j] == '0' ? 0 : (1 + heights[j]);
            }
            res = max(res, largestRectangArea(heights));
        }

        return res;
    }

private:
    int largestRectangArea(vector<int> &heights) {
        int res = 0;
        stack<int> stk;
        heights.push_back(0);

        for (int i = 0; i < heights.size(); ++i) {
            if (stk.empty() || heights[stk.top()] <= heights[i]) {
                stk.push(i);
            }
            else {
                int tmp = stk.top(); stk.pop();
                res = max(res, heights[tmp] *
                               (stk.empty() ? i : (i - stk.top() - 1)));
                --i;
            }
        }

        return res;
    }
};

int main() {
    return 0;
}
