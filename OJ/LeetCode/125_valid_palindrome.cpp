#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        for (size_t l = 0, r = s.size() - 1; l < r; ++l, --r) {
            while (!isalnum(s[l]) && l < r) ++l;
            while (!isalnum(s[r]) && l < r) --r;

            if (toupper(s[l]) != toupper(s[r])) return false;
        }

        return true;
    }
};

int main() {
    return 0;
}
