#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using std::vector;
using std::string;

template<typename T>
void MergeSort(T arr[], int len) {
    T *a = arr;
    T *b = new T[len];
    for (int seg = 1; seg < len; seg += seg) {
        for (int start = 0; start < len; start += (seg + seg)) {
            int low = start;
            int mid = std::min(start + seg, len);
            int high = std::min(start + seg + seg, len);
            int k = low;
            int start1 = low, end1 = mid;
            int start2 = mid, end2 = high;

            while (start1 < end1 && start2 < end2) {
                b[k++] = (a[start1] < a[start2]) ? a[start1++] : a[start2++];
            }
        }
    }
}

void Print(const vector<int> &vec) {
    for (const auto &i : vec) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

namespace CF {

void Merge(int *A, int *L, int left_cnt, int *R, int right_cnt) {
    int i, j, k;
    i = 0, j = 0, k = 0;

    while (i < left_cnt && j < right_cnt) {
        if (L[i] < R[j]) A[k++] = L[i++];
        else A[k++] = R[j++];
    }
    while (i < left_cnt) A[k++] = L[i++];
    while (j < right_cnt) A[k++] = R[j++];
}

}

int Merge(vector<int> &vec, int left, int mid, int right) {
    int n1 = mid - left;
    int n2 = right - mid;

    vector<int> l(n1);
    for (int i = 0; i < n1; ++i) l[i] = vec[left + i];

    vector<int> r(n2);
    for (int i = 0; i < n2; ++i) r[i] = vec[mid + i];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (l[i] <= r[j]) vec[k++] = l[i++];
        else vec[k++] = r[j++];
    }
    while (i < n1) vec[k++] = l[i++];
    while (j < n2) vec[k++] = r[j++];

    return right - left;
}

int MergeSort(vector<int> &vec, int left, int right) {
    int res = 0;
    if (left < right - 1) {
        int mid = (left + right) / 2;
        res += MergeSort(vec, left, mid);
        res += MergeSort(vec, mid, right);
        res += Merge(vec, left, mid, right);
    }

    return res;
}

int main() {

    vector<int> vec{ -1, 23, 0, 432 };

    MergeSort(vec, 0, vec.size());

    Print(vec);

    return 0;
}
