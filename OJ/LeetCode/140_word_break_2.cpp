#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<string> wordBreak(string s, vector<string> &wordDict) {
        unordered_map<string, vector<string>> un_mp;
        return wordBreak(s, wordDict, un_mp);
    }

private:
    vector<string> wordBreak(string s, vector<string> &wordDict,
                             unordered_map<string, vector<string>> &un_mp) {
        if (un_mp.count(s)) return un_mp[s];
        if (s.empty()) return vector<string>();

        vector<string> res;
        for (const string &word : wordDict) {
            if (s.substr(0,word.size()) != word) continue;
            vector<string> rem = wordBreak(s.substr(word.size()),
                                           wordDict, un_mp);
            for (const string &str : rem) {
                res.push_back(word + (str.empty() ? "" : " ") + str);
            }
        }

        return un_mp[s] = res;
    }
};

int main() {
    return 0;
}
