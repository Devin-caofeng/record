#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int trailingZeroes(int n) {
        int res = 0;

        while (n) {
            n /= 5;
            res += n;
        }

        return res;
    }
};

int main() {
    return 0;
}
