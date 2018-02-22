#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using std::vector;
using std::string;

class Solution {
public:
    vector<string> Permutation(string str) {
        vector<string> res;
        if (str.empty()) return res;

        string temp;
        DoPermutation(str, res, temp, 0);

        return res;
    }

    void DoPermutation(string str, vector<string> &res,
                       string &temp, size_t start) {
        if (start == str.size()) {
            res.push_back(temp);
            return;
        }
        for (auto i = start; i < str.size(); ++i) {
            if (i != start && str[start] == str[i]) continue;

            std::swap(str[start], str[i]);
            temp += str[start];
            DoPermutation(str, res, temp, start + 1);
            temp.pop_back();
        }
    }
};

void DoPermutation(char *str, char *begin);

void Permutation(char *str) {
    if (str == nullptr) return;
    DoPermutation(str, str);
}

void DoPermutation(char *str, char *begin) {
    if (*begin == '\0') {
        printf("%s\n", str);
    }
    else {
        for (char *ch = begin; *ch != '\0'; ++ch) {
            char temp = *ch;
            *ch = *begin;
            *begin = temp;

            DoPermutation(str, begin + 1);

            temp = *ch;
            *ch = *begin;
            *begin = temp;
        }
    }
}

int main() {



    return 0;
}
