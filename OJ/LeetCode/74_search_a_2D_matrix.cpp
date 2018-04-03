#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if (matrix.empty() || matrix[0].empty()) return false;

    int m = matrix.size(), n = matrix[0].size();
    int start = 0, end = m * n - 1;
    while (start <= end) {
        int mid = start + (end - start) / 2;
        int e = matrix[mid / n][mid % n];
        if      (target < e) end = mid - 1;
        else if (target > e) start = mid + 1;
        else                 return true;
    }
    return false;
}

bool searchMatrix_T(vector<vector<int>>& matrix, int target) {
    int n = matrix.size(), m = matrix[0].size();
    int l = 0, r = m * n - 1;
    while (l != r) {
        int mid = (l + r - 1) >> 1;
        if (matrix[mid / m][mid % m] < target) l = mid + 1;
        else r = mid;
    }
    return matrix[r / m][r % m] == target;
}

bool searchMatrix_error(vector<vector<int>>& matrix, int target) {
    int m = matrix.size() - 1, n = matrix[0].size() - 1;
    for (int i = m; i >= 0; ) {
        for (int j = 0; j <= n; ) {
            if      (matrix[i][j] > target) --i;
            else if (matrix[i][j] < target) ++j;
            else                            return true;
        }
    }
    return false;
}

int main() {


    return 0;
}
