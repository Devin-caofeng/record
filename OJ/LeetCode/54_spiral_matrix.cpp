#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using std::string; using std::vector;
using std::cout; using std::endl;

vector<int> spiralOrder_v2(vector<vector<int>>& matrix) {
    if (matrix.empty()) return vector<int>();
    int m = matrix.size(), n = matrix[0].size();
    vector<int> spiral(m * n);
    int u = 0, d = m - 1, l = 0, r = n - 1, k = 0;
    while (true) {
        // up
        for (int col = l; col <= r; ++col) spiral[k++] = matrix[u][col];
        if (++u > d) break;
        // right
        for (int row = u; row <= d; ++row) spiral[k++] = matrix[row][r];
        if (--r < l) break;
        // down
        for (int col = r; col >= l; --col) spiral[k++] = matrix[d][col];
        if (--d < u) break;
        // left
        for (int row = d; row >= u; --row) spiral[k++] = matrix[row][l];
        if (++l > r) break;
    }
    return spiral;
}

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<vector<int>> dirs{ {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
    vector<int> res;
    int row = matrix.size();
    int col = matrix.front().size();
    if (row == 0 || col == 0) return res;

    vector<int> steps{col, row - 1};
    int dir = 0;
    int irow = 0, icol = -1;
    while (steps[dir % 2]) {
        for (int i = 0; i < steps[dir % 2]; ++i) {
            irow += dirs[dir][0];
            icol += dirs[dir][1];
            res.push_back(matrix[irow][icol]);
        }
        --steps[dir % 2];
        dir = (dir + 1) % 4;
    }
    return res;
}

int main() {
    return 0;
}
