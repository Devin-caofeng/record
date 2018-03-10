#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using std::vector;
using std::string;

string addBinary(string a, string b) {
    string res;
    int carry = 0;
    for (int i = a.size() - 1, j = b.size() - 1; i >= 0 || j >= 0; --i, --j) {
        int m = (i >= 0 && a[i] == '1');
        int n = (j >= 0 && b[j] == '1');
        res = std::to_string((m + n + carry) & 0x1) + res;
        carry = (m + n + carry) >> 1;
    }
    return carry ? "1" + res : res;
}

int main() {



    return 0;
}