#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::vector;
using std::string;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        addingParenthesis(res, "", n, 0);
        return res;
    }

    void addingParenthesis(vector<string> &vec, string str, int n, int m) {
        if (n == 0 && m == 0) {
            vec.push_back(str);
            return;
        }
        if (m > 0) addingParenthesis(vec, str + ")", n, m - 1);
        if (n > 0) addingParenthesis(vec, str + "(", n - 1, m + 1);
    }
};

int main() {
    return 0;
}
