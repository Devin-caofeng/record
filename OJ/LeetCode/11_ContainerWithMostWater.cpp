#include "../need.h"

int MaxArea(std::vector<int> &height) {
    std::size_t max_area = 0;
    std::size_t left = 0;
    std::size_t right = height.size() - 1;

    while (left < right) {
        max_area = std::max(max_area, std::min(height[left], height[right])
                                      * (right - left));

        if (height[left] < height[right]) ++left;
        else ++right;
    }

    return max_area;
}

int MaxArea0(std::vector<int> &height) {
    int len = height.size();
    int min_cur = 0;

    int *min_left = new int[len];
    for (int i = 0; i < len; ++i) {
        min_cur = std::min(min_cur, min_left[i]);
        min_left[i] = min_cur;
    }

    min_cur = 0;
    int *min_right = new int[len];
    for (int i = len - 1; i >= 0; --i) {
        min_cur = std::min(min_cur, min_right[i]);
        min_right[i] = min_cur;
    }
    std::reverse(min_right, min_right + len);

    int ret = 0;
    for (int i = 0; i < len; ++i) {
        ret = std::max(abs())
    }
}

int main() {


    return 0;
}
