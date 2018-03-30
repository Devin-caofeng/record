#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> ret(n, vector<int>(n));
    int k = 1, i = 0;
    while (k <= n * n) {
        int j = i;
        // left to right
        while (j < n - i) ret[i][j++] = k++;
        j = i + 1;
        // top to bottom
        while (j < n - i) ret[j++][n - i - 1] = k++;
        j = n - i - 2;
        // right to left
        while (j > i)     ret[n - i - 1][j--] = k++;
        j = n - i - 1;
        // bottom to top
        while (j > i)     ret[j--][i] = k++;
        ++i;
    }
    return ret;
}

int main() {
    return 0;
}
