#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void setZeroes(vector<vector<int>>& matrix) {
    bool first_col_is_zero = false;
    size_t rows = matrix.size(), cols = matrix[0].size();

    for (size_t i = 0; i < rows; ++i) {
        if (matrix[i][0] == 0) first_col_is_zero = true;
        for (size_t j = 1; j < cols; ++j) {
            if (matrix[i][j] == 0) matrix[i][0] = matrix[0][j] = 0;
        }
    }

    for (int i = rows - 1; i >= 0; --i) {
        for (int j = cols - 1; j > 0; --j) {
            if (matrix[i][0] == 0 || matrix[0][j] == 0) matrix[i][j] = 0;
        }
        if (first_col_is_zero) matrix[i][0] = 0;
    }
}

int main() {
    return 0;
}
