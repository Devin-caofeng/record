#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <unordered_map>
#include <algorithm>
using namespace std;

string minWindow_2(string s, string t) {
    vector<int> mp(128, 0);
    for (const auto &c : t) ++mp[c];
    size_t cnt = t.size(), begin = 0, end = 0, d = ULONG_MAX, head = 0;

    while (end < s.size()) {
        if (mp[s[end++]]-- > 0) --cnt;
        while (cnt == 0) {
            if (end - begin < d) d = end - (head = begin);
            if (mp[s[begin++]]++ == 0) ++cnt;
        }
    }

    return d == ULONG_MAX ? "" : s.substr(head, d);
}

string minWindow(string s, string t) {
    if (t.size() > s.size()) return string();

    unordered_map<char, int> mp;
    for (size_t i = 0; i < t.size(); ++i) {
        if (mp.find(t[i]) != mp.end()) ++mp[t[i]];
        else mp[t[i]] = 1;
    }

    string res;
    size_t left = 0, cnt = 0, min_len = s.size() + 1;

    for (size_t right = 0; right < s.size(); ++right) {
        if (mp.find(s[right]) != mp.end()) {
            --mp[s[right]];
            if (mp[s[right]] >= 0) ++cnt;
            while (cnt == t.size()) {
                if (right - left + 1 < min_len) {
                    min_len = right - left + 1;
                    res = s.substr(left, min_len);
                }

                if (mp.find(s[left]) != mp.end()) {
                    ++mp[s[left]];
                    if (mp[s[left]] > 0) --cnt;
                }
                ++left;
            }
        }
    }
    return res;
}

int main() {
    return 0;
}
