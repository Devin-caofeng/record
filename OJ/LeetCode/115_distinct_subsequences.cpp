#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size();
        int n = t.size();
        if (m < n) return 0;

        vector<int> vec(n + 1, 0);
        vec[0] = 1;
        for (int i = 1; i <= m; ++i) {
            for (int j = min(i, n) + 1; j >= 0; --j) {
                if (s[i - 1] == t[j - 1]) vec[j] += vec[j - 1];
            }
        }

        return vec[n];
    }
};

int main() {
    return 0;
}
