#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using std::vector;
using std::string;

class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        reverse(matrix.begin(), matrix.end());

        for (decltype(matrix.size()) i=0; i<matrix.size(); ++i)
            for (decltype(matrix.size()) j=i; j<matrix[i].size(); ++j)
                std::swap(matrix[i][j], matrix[j][i]);
    }
};

int main() {



    return 0;
}
