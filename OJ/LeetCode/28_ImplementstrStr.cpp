#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using std::vector;
using std::string;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.size(), n = needle.size();
        if (!n) return 0;

        for (int i = 0; i < m - n + 1; ++i) {
            int j = 0;
            for ( ; j < n; ++j) {
                if (haystack[i + j] != needle[j]) break;
            }
            if (j == n) return i;
        }
        return -1;
    }

    int strStrKMP(string haystack, string needle) {
        int hs_len = haystack.size();
        int needle_len = needle.size();
        if (needle_len < 1) return 0;

        vector<int> lps = kmpProcess(needle);
        for (int i = 0, j = 0; i < hs_len; ) {
            if (haystack[i] == needle[j]) {
                ++i;
                ++j;
            }
            if (j == needle_len) return i - j;
            if (i < hs_len && haystack[i] != needle[j]) {
                if   (j) j = lps[j - 1];
                else     ++i;
            }
        }
        return -1;
    }

private:
    vector<int> kmpProcess(string &needle) {
        int len = needle.size();
        vector<int> lps(len, 0);
        for (int i = 1, len = 0; i < len; ) {
            if      (needle[i] == needle[len]) lps[i++] = ++len;
            else if (len)                      len = lps[len - 1];
            else                               lps[i++] = 0;
        }
        return lps;
    }
};

int main() {



    return 0;
}
