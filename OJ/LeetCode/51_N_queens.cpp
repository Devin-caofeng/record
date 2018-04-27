#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<string>> sloveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> nqueens(n, string(n, '.'));
        solveNQueens(res, nqueens, 0, n);
        return res;
    }

private:
    void solveNQueens(vector<vector<string>> &res,
                      vector<string> &nqueens, int row, int n) {
        if (row == n) {
            res.push_back(nqueens);
            return;
        }
        for (int col = 0; col != n; ++col) {
            if (isValid(nqueens, row, col, n)) {
                nqueens[row][col] = 'Q';
                solveNQueens(res, nqueens, row + 1, n);
                nqueens[row][col] = '.';
            }
        }
    }

    bool isValid(vector<string> &nqueens, int row, int col, int n) {
        // check if the column had a queen before
        for (int i = 0; i != row; ++i) {
            if (nqueens[i][col] == 'Q') return false;
        }
        // check if the 45 diagonal had a queen before
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j) {
            if (nqueens[i][j] == 'Q') return false;
        }
        for (int i = row - 1, j = col + 1; i >= 0 && j <= n - 1; --i, ++j) {
            if (nqueens[i][j] == 'Q') return false;
        }
        return true;
    }
};

int main() {
    return 0;
}
