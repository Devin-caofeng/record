#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void MultiChar() {
    for (string s, t; cin >> s >> t; ) {
        int cnt[26] = { 0 };
        int slen = s.size(), tlen = t.size();
        for (int i = 0; i < slen - tlen + 1; ++i) {
            ++cnt[s[i] - 'a'];
        }

        int ans = 0;
        for (int i = 0; i < tlen; ++i) {
            ans += slen - tlen + 1 - cnt[t[i] - 'a'];
            --cnt[s[i] - 'a'];
            ++cnt[s[i + slen - tlen + 1] - 'a'];
        }
        cout << ans << endl;
    }
}

int main() {

    for (string s, t; cin >> s >> s; ) {
        int a = 0, b = 0;
        int slen = s.size(), tlen = t.size();
        for (int i = 0; i < slen - tlen + 1; ++i) {
            a += s[i] == 'a';
            b += s[i] == 'b';
        }
        int ans = 0;
        for (int i = 0; i + slen - tlen < slen; ++i) {
            ans += (t[i] == 'a') ? b : a;
            s[i] == 'a' ? --a : --b;
            s[i + slen - tlen + 1] == 'a' ? ++a : ++b;
        }
        cout << ans << endl;
    }

    return 0;
}
