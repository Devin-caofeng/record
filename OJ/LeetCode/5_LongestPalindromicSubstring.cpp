#include "../need.h"
using namespace std;

string longestPalindrome(string s) {
    using s_size = string::size_type;

    if (s.empty()) return "";
    else if (s.size() == 1) return s;

    s_size min_start = 0;
    s_size max_len = 1;
    for (s_size i = 0; i < s.size();) {
        if (s.size() - i <= max_len / 2) break;

        s_size j = i, k = i;
        while (k < s.size() - 1 && s[k + 1] == s[k]) ++k;

        i = k + 1;
        while (k < s.size() - 1 && j > 0 && s[k + 1] == s[j - 1]) {
            ++k;
            --j;
        }

        s_size cur_len = k - j + 1;
        if (cur_len > max_len) {
            min_start = j;
            max_len = cur_len;
        }
    }

    return s.substr(min_start, max_len);
}

int main() {


    return 0;
}
