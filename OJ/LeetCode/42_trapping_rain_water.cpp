#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int trap(vector<int> &height) {
    if (height.size() < 3) return 0;

    int cnt = 0;
    for (int i = 0, j = height.size() - 1, max_i = height[i], max_j = height[j];
            i < j; max_i = max(max_i,height[i]), max_j = max(max_j,height[j])) {
        if (max_i < max_j) cnt += max_i - height[i++];
        else cnt += max_j - height[j--];
    }
    return cnt;
}

int main() {
    return 0;
}
