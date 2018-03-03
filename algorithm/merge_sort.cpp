#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using std::vector;
using std::string;

int Merge(vector<int> &vec, int left, int mid, int right) {
    int n1 = mid - left;
    int n2 = right - mid;

    vector<int> l(n1 + 1);
    for (int i = 0; i < n1; ++i) l[i] = vec[left + i];
    l[n1] = 0x7fffffff;

    vector<int> r(n2 + 1);
    for (int i = 0; i < n2; ++i) r[i] = vec[mid + i];
    r[n2] = 0x7fffffff;

    for (int i = 0, j = 0, k = left; k < right; ++k) {
        if (l[i] <= r[j]) {
            vec[k] = l[i++];
        }
        else {
            vec[k] = r[j++];
        }
    }

    return right - left;
}

int MergeSort(vector<int> &vec, int left, int right) {
    int res = 0;
    if (left + 1 < right) {
        int mid = (left + right) / 2;
        res += MergeSort(vec, left, mid);
        res += MergeSort(vec, mid, right);
        res += Merge(vec, left, mid, right);
    }

    return res;
}

void Print(const vector<int> &vec) {
    for (const auto &i : vec) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

int main() {

    for (int i = 0; i < 10; ++i) {
        vector<int> vec;
        for (int j = 0; j < 9; ++j) {
            vec.push_back(rand() % 10000);
        }

        MergeSort(vec, 0, vec.size() - 1);
        Print(vec);

        vec.clear();
    }

    return 0;
}
