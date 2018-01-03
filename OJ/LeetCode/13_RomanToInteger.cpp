#include "../need.h"

class Solution {
    int RomanToInt(std::string s) {
        if (s.empty()) return 0;

        std::unordered_map<char, int> table = {
            { 'I', 1 },
            { 'V', 5 },
            { 'X', 10 },
            { 'L', 50 },
            { 'C', 100 },
            { 'D', 500 },
            { 'M', 1000 }
        };

        int num = 0;
        for (size_t i = 0; i < s.size() - 1; ++i) {  // 这里 size 确保会大于0
            if (table[s[i]] < table[s[i + 1]]) num -= table[s[i]];
            else num += table[s[i]];
        }
        num += table[s.back()];

        return num;
    }
};

int main() {


    return 0;
}
