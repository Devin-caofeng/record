#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool isMatch(string s, string p) {
    int star = 0, ss = 0, i = 0, j = 0;
    while (s[i]) {
        if (p[j] == '?' || p[j] == s[i]) {
            j++; i++;
            continue;
        }
        if (p[j] == '*') {
            star = ++j;
            ss = i;
            continue;
        }
        if (star) {
            j = star;
            i = ++ss;
            continue;
        }
        return false;
    }
    while (p[j] == '*') j++;

    return !p[j];
}

int main() {
    return 0;
}
