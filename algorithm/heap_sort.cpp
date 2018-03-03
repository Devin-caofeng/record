#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using std::vector;
using std::string;

void HeapBuild(vector<int> &vec, int root, int len) {
    int lchild = root * 2 + 1;
    if (lchild < len) {
        int flag = lchild;  // 保存左右孩子节点中的最大值下标
        int rchild = lchild + 1;
        if (rchild < len) {
            if (vec[rchild] > vec[flag]) {
                flag = rchild;
            }
        }

        if (vec[root] < vec[flag]) {
            std::swap(vec[root], vec[flag]);
            HeapBuild(vec, flag, len);
        }
    }
}

void HeapSort(vector<int> &vec) {
    for (int i = vec.size() / 2; i >= 0; --i) {
        HeapBuild(vec, i, vec.size());
    }

    for (int j = vec.size() - 1; j > 0; --j) {
        std::swap(vec[0], vec[j]);
        HeapBuild(vec, 0, j);
    }
}

int main() {
    vector<int> vec{ 543, 43, 53, 12 };

    HeapSort(vec);

    for (const auto &i : vec) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}
