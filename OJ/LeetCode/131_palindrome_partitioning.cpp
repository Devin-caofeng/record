#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> out;
        partition(s, 0, out, res);
        return res;
    }

    void partition(string s, size_t start, vector<string> &out,
                   vector<vector<string>> &res) {
        if (start == s.size()) {
            res.push_back(out);
            return;
        }

        for (size_t i = start; i < s.size(); ++i) {
            if (isPalindrome(s, start, i)) {
                out.push_back(s.substr(start, i - start + 1));
                partition(s, i + 1, out, res);
                out.pop_back();
            }
        }
    }

    bool isPalindrome(string s, int start, int end) {
        while (start < end) {
            if (s[start++] != s[end--]) return false;
        }
        return true;
    }
};

int main() {
    return 0;
}
