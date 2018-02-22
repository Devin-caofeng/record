#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using std::vector;

class Solution {
public:
    int GetUglyNumber(int index) {
        if (index <= 0) return 0;

        int *ugly_nums = new int[index];
        ugly_nums[0] = 1;
        int next_ugly_index = 1;

        int *multiply2 = ugly_nums;
        int *multiply3 = ugly_nums;
        int *multiply5 = ugly_nums;

        while (next_ugly_index < index) {
            int min =
                std::min({ *multiply2 * 2, *multiply3 * 3, *multiply5 * 5 });
            ugly_nums[next_ugly_index] = min;

            while (*multiply2 * 2 <= ugly_nums[next_ugly_index]) ++multiply2;
            while (*multiply3 * 3 <= ugly_nums[next_ugly_index]) ++multiply2;
            while (*multiply5 * 5 <= ugly_nums[next_ugly_index]) ++multiply2;

            ++next_ugly_index;
        }

        int ugly = ugly_nums[next_ugly_index - 1];
        delete[] ugly_nums;

        return ugly;
    }

    int So(int index) {
        if (index < 7) return index;

        vector<int> res(index);
        res[0] = 1;
        int t2 = 0, t3 = 0, t5 = 0;
        for (int i = 1; i < index; ++i) {
            res[i] = std::min({ res[t2] * 2, res[t3] * 3, res[t5] * 5 });
            if (res[i] == res[t2] * 2) ++t2;
            if (res[i] == res[t3] * 3) ++t3;
            if (res[i] == res[t5] * 5) ++t5;
        }

        return res[index - 1];
    }
};

bool IsUgly(int num) {
    while (num % 2 == 0) num /= 2;
    while (num % 3 == 0) num /= 3;
    while (num % 5 == 0) num /= 5;

    return (num == 1) ? true : false;
}


int GetUglyNumber(int index) {
    if (index <= 0) return 0;

    int num = 0;
    int ugly_found = 0;
    while (ugly_found < index) {
        ++num;
        if (IsUgly(num)) ++ugly_found;
    }

    return num;
}

int main() {



    return 0;
}
