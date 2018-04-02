#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int MyminPathSum(vector<vector<int>>& grid) {
    for (size_t i = 0; i < grid.size(); ++i) {
        for (size_t j = 0; j < grid[0].size(); ++j) {
            if      (!i && !j) continue;
            else if (!i)       grid[i][j] += grid[i][j - 1];
            else if (!j)       grid[i][j] += grid[i - 1][j];
            else               grid[i][j] += min(grid[i - 1][j],
                                                 grid[i][j - 1]);
        }

    }
    return grid.back().back();
}

int main() {
    return 0;
}
