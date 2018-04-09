#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> restoreIpAddresses(string s) {
    vector<string> ret;

    for (size_t a = 1; a <= 3; ++a)
    for (size_t b = 1; b <= 3; ++b)
    for (size_t c = 1; c <= 3; ++c)
    for (size_t d = 1; d <= 3; ++d) {
        if ((a + b + c + d) == s.size()) {
            int A = stoi(s.substr(0, a));
            int B = stoi(s.substr(a, b));
            int C = stoi(s.substr(a + b, c));
            int D = stoi(s.substr(a + b + c, d));
            if (A <= 255 && B <= 255 && C <= 255 && D <= 255) {
                string ans = to_string(A) + "." + to_string(B) + "." +
                             to_string(C) + "." + to_string(D);
                if (ans.size() == s.size() + 3) {
                    ret.push_back(ans);
                }
            }
        }
    }
    return ret;
}

class L93 {
public:
    vector<string> restoreIpAddresses(string s) {
        if (s.size() >= 4 && s.size() <= 12) restore(s, "", 4);
        return ret;
    }

private:
    void restore(const string &origin, const string &ip, int part) {
        if (part == 0) {
            if (origin.empty()) ret.push_back(ip);
            return;
        }

        for (size_t i = 1; i <= 3; ++i) {
            if (origin.size() < i) break;
            string section = origin.substr(0, i);
            if (isValid(section)) {
                if (part != 1) section.append(".");
                restore(origin.substr(i), ip + section, part - 1);
            }
        }
    }

    bool isValid(const string &s) {
        if (s.size() > 1 && s[0] == '0') return false;
        int num = stoi(s);
        return 0 <= num && num <= 255;
    }

    vector<string> ret;
};

int main() {
    return 0;
}
