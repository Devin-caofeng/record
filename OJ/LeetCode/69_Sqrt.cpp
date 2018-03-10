#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using std::vector;
using std::string;

int sqrt(int x) {
    int left = 1, right = x;
    int ret = 0;
    while (left < right) {
        int mid = (left + right) >> 1;
        if (mid <= x / mid) {
            left = mid + 1;
            ret = mid;
        }
        else {
            right = mid - 1;
        }
    }

    return ret;
}

int main() {



    return 0;
}
