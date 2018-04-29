#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;

class Solution {
public:
    int totalNQueens(int n) {
        int res = 0;
        vector<int> pos(n, -1);
        totalNQueensDFS(pos, 0, n, res);
        return res;
    }

private:
    void totalNQueensDFS(vector<int> &pos, int row, int len, int &res) {
        if (row == len) {
            ++res;
            return;
        }

        for (int i = 0; i < len; ++i) {
            if (isValid(pos, row, i)) {
                pos[row] = i;
                totalNQueensDFS(pos, row + 1, len, res);
                pos[row] = - 1;
            }
        }
    }

    bool isValid(const vector<int> &pos, int row, int col) {
        for (int i = 0; i < row; ++i) {
            if (col == pos[i] || abs(row - i) == abs(col - pos[i])) {
                return false;
            }
        }

        return true;
    }
};

int totalNQueens(int n) {
    int upper_lim = (1 << n) - 1, sum = 0;
    function<void(int, int, int)> dfs = [&](int row, int l, int r) {
        if (row == upper_lim) {
            ++sum;
            return;
        }

        for (int cur = upper_lim & (~(row | l | r)), pos = 0;
                cur; dfs(row + pos, (l + pos) << 1, (r + pos) >> 1)) {
            pos = cur & (~pos);
            cur -= pos;
        }
    };
    dfs(0, 0, 0);
    return sum;
}

int main() {
    return 0;
}
