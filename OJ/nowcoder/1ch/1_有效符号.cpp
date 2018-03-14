#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using std::vector;
using std::string;

class Solution {
public:
    bool isValid(string s) {
        if (s.empty()) return true;

        int count = 0;
        for (size_t i = 0; i < s.size(); ++i) {
            if (s[i] != ')' && s[i] != '(') return false;
            if (s[i] == ')' && --count > 0) return false;
            if (s[i] == '(') ++count;
        }

        return count == 0;
    }
};

int main() {



    return 0;
}
