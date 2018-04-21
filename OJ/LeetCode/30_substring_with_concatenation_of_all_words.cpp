#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string> &words) {
        vector<int> res;
        if (s.empty() || words.empty()) return res;

        int word_len = words[0].size();
        unordered_map<string, int> cnt_word;
        for (const string &word : words) {
            ++cnt_word[word];
        }

        for (int i = 0; i < word_len; ++i) {
            size_t total_in = 0;
            unordered_map<string, int> cur_cnt;

            for (size_t j = i, start = i; j + word_len <= s.size();
                    j += word_len) {
                string word = s.substr(j, word_len);
                if (cnt_word.find(word) == cnt_word.end()) {
                    cur_cnt.clear();
                    total_in = 0;
                    start = j + word_len;
                }
                else {
                    ++cur_cnt[word];
                    while (cur_cnt[word] > cnt_word[word]) {
                        --cur_cnt[s.substr(start, word_len)];
                        start += word_len;
                        --total_in;
                    }
                    if (++total_in == word.size()) res.push_back(start);
                }
            }
        }
        return res;
    }
};

vector<int> findSubstring(string s, vector<string> &words) {
    vector<int> res;
    if (s.empty() || words.empty()) return res;

    int word_len = words[0].size();
    int n = words.size();
    unordered_map<string, int> cnt_word;
    for (const string &word : words) {
        ++cnt_word[word];
    }

    for (size_t i = 0; i + n * word_len <= s.size(); ++i) {
        int total_in = 0;
        unordered_map<string, int> cur_cnt;

        for (size_t j = i; j < i + n * word_len; j += word_len) {
            string word = s.substr(j, word_len);
            if (++cur_cnt[word] > cnt_word[word]) break;
            ++total_in;
        }
        if(total_in == n) res.push_back(i);
    }

    return res;
}

int main() {
    return 0;
}
