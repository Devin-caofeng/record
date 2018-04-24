#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char>> &board) {
        solveSudoku(board, 0, 0);
    }

private:
    bool solveSudoku(vector<vector<char>> &board, int i, int j) {
        if (i == 9) return true;
        if (j == 9) return solveSudoku(board, i + 1, 0);
        if (board[i][j] != '-') return solveSudoku(board, i, j + 1);

        for (char c = '1'; c <= 9; ++c) {
            if (check(board, i, j, c)) {
                board[i][j] = c;
                if (solveSudoku(board, i, j + 1)) return true;
                board[i][j] = '.';
            }
        }
        return false;
    }

    bool check(vector<vector<char>> &board, int i, int j, char c) {
        int row = i - i%3, col = j - j%3;

        for (int x = 0; x < 9; ++x) {
            if (board[x][j] == c) return false;
        }
        for (int y = 0; y < 9; ++y) {
            if (board[i][y] == c) return false;
        }

        for (int x = 0; x < 3; ++x) {
            for (int y = 0; y < 3; ++y) {
                if (board[row + x][col + y] == c) return false;
            }
        }
        return true;
    }
};

bool findEmptyCell(const vector<vector<char>> &board,
                   size_t &row, size_t &col) {
    for (row = 0; row < board.size(); ++row) {
        for (col = 0; col < board[0].size(); ++col) {
            if (board[row][col] == '.') return true;
        }
    }
    return false;
}

bool isSafe(const vector<vector<char>> &board, size_t row, size_t col, char c) {
    for (size_t i = 0; i < 9; ++i) {
        if (board[row][i] == c) return false;
        if (board[i][col] == c) return false;
        if (board[row/3 * 3 + i / 3][col/3 * 3 + i % 3] == c) return false;
    }
    return true;
}

bool solvesSudoku(vector<vector<char>> &board) {
    size_t row = 0, col = 0;
    if (!findEmptyCell(board, row, col)) return true;

    for (const char &c : { '1', '2', '3', '4', '5', '6', '7', '8', '9' }) {
        if (isSafe(board, row, col, c)) {
            board[row][col] = c;
            if (solvesSudoku(board)) return true;
            board[row][col] = '.';
        }
    }
    return false;
}

int main() {
    return 0;
}
