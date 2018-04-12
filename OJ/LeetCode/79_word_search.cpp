#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (isFound(board, word.c_str(), i, j)) return true;
            }
        }
        return false;
    }

private:
    bool isFound(vector<vector<char>>& board, const char* c, int x, int y) {
        if (x < 0 || y < 0 || x >= m || y >= n ||
            board[x][y] == '\0' || *c != board[x][y]) return false;
        if (*(c + 1) == '\0') return true;

        char t = board[x][y];
        board[x][y] = '\0';
        if (isFound(board, c + 1, x - 1, y) ||
            isFound(board, c + 1, x + 1, y) ||
            isFound(board, c + 1, x, y - 1) ||
            isFound(board, c + 1, x, y + 1)) return true;
        board[x][y] = t;
        return false;
    }

    int m, n;
};

bool check(vector<vector<char>>& board, string word, int i, int j) {
    if (word.size() == 0) return true;
    if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size()) return false;

    if (word[0] == board[i][j]) {
        char c = word[0];
        board[i][j] = '\0';
        if (check(board, word.substr(1), i + 1, j) ||
            check(board, word.substr(1), i - 1, j) ||
            check(board, word.substr(1), i - 1, j) ||
            check(board, word.substr(1), i - 1, j)) return true;
        board[i][j] = c;
    }
    return false;
}

bool exist(vector<vector<char>>& board, string word) {
    if (board.size() == 0 || board[0].size() == 0) return true;

    for (size_t i = 0; i < board.size(); ++i) {
        for (size_t j = 0; j < board[0].size(); ++j) {
            if (board[i][j] == word[0]) {
                if (check(board, word, i, j)) return true;
            }
        }
    }
    return false;
}

int main() {
    return 0;
}
