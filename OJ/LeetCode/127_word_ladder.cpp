#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord,
                     vector<string> &wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        unordered_map<string, int> mp;
        queue<string> que;

        mp[beginWord] = 1;
        que.push(beginWord);

        while (!que.empty()) {
            string word = que.front(); que.pop();
            for (size_t i = 0; i < word.size(); ++i) {
                string newWord = word;
                for (char ch = 'a'; ch <= 'z'; ++ch) {
                    newWord[i] = ch;
                    if (dict.count(newWord) && newWord == endWord) {
                        return mp[word] + 1;
                    }
                    if (dict.count(newWord) && !mp.count(newWord)) {
                        que.push(newWord);
                        mp[newWord] = mp[word] + 1;
                    }
                }
            }
        }

        return 0;
    }
};

int main() {
    return 0;
}
