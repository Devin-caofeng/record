#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using std::string; using std::vector;
using std::cout; using std::endl;

class Solution {
public:
    int pow(double x, int n) {
        if      (n == 0)  return 1;
        else if (n & 0x1) return x * pow(x, n/2) * pow(x, n/2);
        else              return pow(x, n/2) * pow(x, n/2);
    }

    int powIter(double x, int n) {
        double ans = 1;
        long absn = std::abs(static_cast<long>(n));
        while (absn > 0) {
            if (absn & 0x1) ans *= x;
            x *= x;
            absn >>= 1;
        }
        return n < 0 ? 1/ans : ans;
    }
};

int main() {
    return 0;
}
