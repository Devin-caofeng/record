#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    string decodeString(string s) {
        int i = 0;
        return decode(s, i);
    }

    string decode(string s, int& i) {
        string res("");
        int n = s.size();

        while (i < n && s[i] != ']') {
            if (s[i] < '0' || s[i] > '9') {
                res += s[i++];
            }
            else {
                int cnt = 0;
                while (i < n && s[i] >= '0' && s[i] <= '9') {
                    cnt = (cnt * 10) + (s[i++] - '0');
                }

                ++i;
                string tmp = decode(s, i);
                ++i;

                while (cnt-- > 0) {
                    res += tmp;
                }
            }
        }

        return res;
    }
};

string decodeString(string s) {
    stack<int> num_stk;
    stack<string> str_stk;
    string res(""), t("");
    int cnt = 0;

    for (size_t i = 0; i < s.size(); ++i) {
        if (s[i] >= '0' && s[i] <= '9') {
            cnt = (cnt * 10) + (s[i] - '0');
        }
        else if (s[i] == '[') {
            num_stk.push(cnt);
            str_stk.push(t);
            cnt = 0;
            t.clear();
        }
        else if (s[i] == ']') {
            int k = num_stk.top();
            num_stk.pop();
            for (int j = 0; j < k; ++j) {
                str_stk.top() += t;
            }
            t = str_stk.top();
            str_stk.pop();
        }
        else {
            t += s[i];
        }
    }

    return str_stk.empty() ? t : str_stk.top();
}

int main() {
    return 0;
}
