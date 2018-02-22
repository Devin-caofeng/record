#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using std::vector;
using std::string;

class Solution {
public:
    vector<int> PrintMatrix(vector<vector<int>> matrix) {
        vector<int> res;
        int row = matrix.size();
        int col = matrix[0].size();
        int circle = (((row < col) ? row : col) - 1) / 2 + 1;

        for (int i = 0; i < circle; ++i) {
            for (int j = i; j < col - i; ++j) {
                res.push_back(matrix[i][j]);
            }
            for (int j = i + 1; j < row - i; ++j) {
                res.push_back(matrix[j][col - 1 - i]);
            }
            for (int j = col - i - 2; (j >= i) && ((row - i - 1) != i); --j) {
                res.push_back(matrix[row - i - 1][j]);
            }
            for (int j = row - i - 2; (j > i) && ((col - i - 1) != i); --j) {
                res.push_back(matrix[j][i]);
            }
        }

        return res;
    }
};

int main() {



    return 0;
}
