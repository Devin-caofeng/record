#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void solve(vector<vector<char>> &board) {
        int row = board.size();
        if (row < 1) return;
        int col = board[0].size();

        for (int i = 0; i < row; ++i) {
            check(board, i, 0, row, col);
            if (col > 1) check(board, i, col - 1, row, col);
        }
        for (int j = 1; j < col; ++j) {
            check(board, 0, j, row, col);
            if (row > 1) check(board, row - 1, j, row, col);
        }

        auto ConvertCh = [&board](int row, int col, char oldch, char newch) {
            for (int i = 0; i < row; ++i) {
                for (int j = 0; j < col; ++j) {
                    if (board[i][j] == oldch) board[i][j] = newch;
                }
            }
        };

        ConvertCh(row, col, 'O', 'X');
        ConvertCh(row, col, '1', 'O');
    }

    void check(vector<vector<char>> &vvec, int i, int j, int row, int col) {
        if (vvec[i][j] == 'O') {
            vvec[i][j] = '1';
            if (i > 1) check(vvec, i - 1, j, row, col);
            if (j > 1) check(vvec, i, j - 1, row, col);
            if (i + 1 < row) check(vvec, i + 1, j, row, col);
            if (j + 1 < col) check(vvec, i, j + 1, row, col);
        }
    }
};

int main() {
    return 0;
}
