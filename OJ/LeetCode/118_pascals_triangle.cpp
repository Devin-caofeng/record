#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res(numRows, vector<int>());

        for (int i = 0; i < numRows; ++i) {
            vector<int> tmp(i + 1, 1);

            for (int j = 1; j < i; ++j) {
                tmp[j] = res[i - 1][j - 1] + res[i - 1][j];
            }

            // res[i] = tmp;
            res[i] = move(tmp);
        }

        return res;
    }
};

int main() {
    return 0;
}
