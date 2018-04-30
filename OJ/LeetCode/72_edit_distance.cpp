#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int minDistance_DP(string word1, string word2) {
    if (word1 == word2) return 0;
    if (word1.empty()) return word2.size();
    if (word2.empty()) return word1.size();

    vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, 0));
    for (size_t i = 0; i < word1.size() + 1; ++i) {
        dp[i][word2.size()] = word1.size() - i;
    }
    for (size_t j = 0; j < word2.size() + 1; ++j) {
        dp[word1.size()][j] = word2.size() - j;
    }

    for (int i = word1.size() - 1; i >= 0; --i) {
        for (int j = word2.size() - 1; j >= 0; --j) {
            if (word1[i] == word2[j]) {
                dp[i][j] = dp[i + 1][j + 1];
            }
            else {
                dp[i][j] = min(1 + dp[i][j + 1],
                               min(1 + dp[i + 1][j], 1 + dp[i + 1][j + 1]));
            }
        }
    }

    return dp[0][0];
}

int minDistance(string word1, string word2) {
    if (word1 == word2) return 0;
    if (word1.empty()) return word2.size();
    if (word2.empty()) return word1.size();

    if (word1[0] == word2[0]) {
        return minDistance(word1.substr(1), word2.substr(1));
    }
    else {
        return min(1 + minDistance(word1, word2.substr(1)),
                   min(1 + minDistance(word1.substr(1), word2),
                       1 + minDistance(word1.substr(1), word2.substr(1))));
    }
}

int main() {
    return 0;
}
