#include "../need.h"
using namespace std;

double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    int len1 = nums1.size();
    int len2 = nums2.size();
    if (len1 < len2) return findMedianSortedArrays(nums2, nums1);

    int i_min = 0, i_max = len1;
    int half_len = (len1 + len2 + 1) / 2;

    while (i_min <= i_max) {
        int i = (i_min + i_max) / 2;
        int j = half_len - i;

        if (i < i_max && nums2[j - 1] > nums1[i]) {
            i_min = i_min + 1;
        }
        else if (i > i_min && nums1[i - 1] > nums2[j]) {
            i_max = i_max - 1;
        }
        else {
            int max_left = 0;
            if (i == 0) max_left = nums2[j - 1];
            else if (j == 0) max_left = nums1[i - 1];
            else max_left = max(nums1[i - 1], nums2[j - 1]);

            if ((len1 + len2) % 2 == 1) return max_left;

            int min_right = 0;
            if (i == len1) min_right = nums2[j];
            else if (j == len2) min_right = nums1[i];
            else min_right = min(nums1[i], nums2[j]);

            return (max_left + min_right) / 2.0;
        }
    }

    return 0.0;
}

int main() {


    return 0;
}
