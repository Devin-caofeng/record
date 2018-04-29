#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool isNumber(string s) {
    size_t i = 0;

    while (s[i] == ' ') ++i;

    if (s[i] == '+' || s[i] == '-') ++i;

    int n_nm, n_pt;
    for (n_nm = 0, n_pt = 0; (s[i] <= '9' && s[i] >= '0') || s[i] == '.'; ++i) {
        s[i] == '.' ? ++n_pt : ++n_nm;
    }
    if (n_pt > 1 || n_nm < 1) return false;

    // check the exponent if exist
    if (s[i] == 'e') {
        ++i;
        if (s[i] == '+' || s[i] == '-') ++i;

        int n_nm = 0;
        for ( ; s[i] >= '0' && s[i] <= '9'; ++i, ++n_nm) { }
        if (n_nm < 1) return false;
    }

    while (s[i] == ' ') ++i;

    return i == s.size();
}

int main() {
    return 0;
}
