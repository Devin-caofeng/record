#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using std::vector;
using std::string;

string CountAndSay(int n) {
    if (n == 0) return "";
    string res = "1";
    while (--n) {
        string cur = "";
        for (size_t i = 0; i < res.size(); ++i) {
            int count = 1;
            while ((i + 1 < res.size()) && (res[i] == res[i + 1])) {
                ++count;
                ++i;
            }
            cur += std::to_string(count) + res[i];
        }
        res = cur;
    }
    return res;
}

int main() {



    return 0;
}
