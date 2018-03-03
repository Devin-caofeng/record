#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using std::vector;
using std::string;

int Partition(vector<int> &vec, int left, int right) {
    int split = vec[right];
    int i = left - 1;
    for (int j = left; j < right; ++j) {
        if (vec[j] <= split) {
            ++i;
            std::swap(vec[i], vec[j]);
        }
    }
    std::swap(vec[i + 1], vec[right]);

    return i + 1;
}

void QuickSort(vector<int> &vec, int left, int right) {
    if ((left < right) && (left >= 0)) {
        int q = Partition(vec, left, right);
        QuickSort(vec, left, q - 1);
        QuickSort(vec, q + 1, right);
    }
}

void Print(const vector<int> &vec) {
    for (const auto &i : vec) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

int main() {

    vector<int> vec1{ 1, 2, 5, 0 };
    vector<int> vec2;
    vector<int> vec3{ -1, 2, -5, 0 };
    vector<int> vec4{ 0 };

    QuickSort(vec1, 0, vec1.size() - 1);
    QuickSort(vec2, 0, vec2.size() - 1);
    QuickSort(vec3, 0, vec3.size() - 1);
    QuickSort(vec4, 0, vec4.size() - 1);

    Print(vec1);
    Print(vec2);
    Print(vec3);
    Print(vec4);

    return 0;
}
