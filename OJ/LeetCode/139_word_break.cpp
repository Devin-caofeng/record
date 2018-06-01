#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
    int wordBreak(string s, vector<string> &wordDict) {
        unordered_set<string> dict(wordDict.cbegin(), wordDict.cend());
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;

        for (size_t i = 1; i <= s.size(); ++i) {
            for (int j = i - 1; j >= 0; --j) {
                if (dp[j] && dict.find(s.substr(j, i - j)) != dict.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[s.size()];
    }
};

int main() {
    return 0;
}
