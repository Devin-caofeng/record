#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    string fractionToDecimal(int64_t numerator, int64_t denominator) {
        if (numerator == 0) return "0";

        string res;
        if (numerator < 0 ^ denominator < 0) res += '-';

        numerator = abs(numerator);
        denominator = abs(denominator);

        res += to_string(numerator / denominator);
        if (numerator % denominator == 0) return res;

        res += ".";

        unordered_map<int, int> unmp;
        for (int64_t r = numerator % denominator; r; r %= denominator) {
            if (unmp.count(r) > 0) {
                res.insert(unmp[r], 1, '(');
                res += ")";
                break;
            }

            unmp[r] = res.size();
            r *= 10;
            res += to_string(r / denominator);
        }

        return res;
    }
};

int main() {
    return 0;
}

