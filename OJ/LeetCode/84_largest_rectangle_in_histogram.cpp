#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int largestRectangleArea(vector<int> &heights) {
    int max_area = 0, i = 0, size = heights.size();
    for (stack<int> stk; i < size || !stk.empty(); ) {
        if (stk.empty() || (i != size && heights[stk.top()] <= heights[i])) {
            stk.push(i++);
        }
        else {
            int tp = stk.top(); stk.pop();
            max_area = max(max_area, heights[tp] *
                                     (stk.empty() ? i : (i - stk.top() - 1)));
        }
    }

    return max_area;
}

int largestRectangleArea_2(vector<int> &heights) {
    int res = 0;
    for (size_t i = 0; i < heights.size(); ++i) {
        if (i + 1 < heights.size() && heights[i] <= heights[i + 1]) continue;

        int min_height = heights[i];
        for (int j = i; j >= 0; --j) {
            min_height = min(min_height, heights[j]);
            int area = min_height * (i - j + 1);
            res = max(res, area);
        }
    }

    return res;
}

int main() {
    return 0;
}
