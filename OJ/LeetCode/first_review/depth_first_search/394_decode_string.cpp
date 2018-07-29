#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    string decodeString(string s) {
        string::size_type i = 0;
        return decode(s, i);
    }

    string decode(string s, string::size_type& i) {
        string res;

        while (i < s.size() && s[i] != ']') {
            if (!isdigit(s[i])) {
                res += s[i++];
            }
            else {
                int cnt = 0;
                while (i < s.size() && isdigit(s[i])) {
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

int main() {
    return 0;
}
