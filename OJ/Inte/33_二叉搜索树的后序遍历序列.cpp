#include <iostream>
#include <string>
#include <vector>

using std::vector;

bool VerifySquenceOfBST(vector<int> sequence) {
    using size_type = decltype(sequence.size());

    if (sequence.empty()) {
        return false;
    }

    int root = sequence.back();

    // 在二叉搜索树中左子树的节点小于根节点
    size_type i = 0;
    for ( ; i < sequence.size() - 1; ++i) {
        if (sequence[i] > root) {
            break;
        }
    }

    // 在二叉搜索树种右子树的节点大于根节点
    auto j = i;
    for ( ; j < sequence.size() - 1; ++j) {
        if (sequence[j] < root) {
            return false;
        }
    }

    // 判断左子树是否为二叉搜索树
    bool left = true;
    if (i > 0) {
        left = VerifySquenceOfBST(vector<int>(sequence.begin(),
                                              sequence.begin() + i + 1));
    }

    // 判断右子树是否为二叉搜索树
    bool right = true;
    if (i < sequence.size() - 1) {
        right = VerifySquenceOfBST(vector<int>(sequence.begin() + i,
                                               sequence.begin() + j));
    }

    return true;
}

bool IterVersion(vector<int> sequence) {
    int size = sequence.size();
    if (0 == size) {
        return false;
    }

    while (--size) {
        int i = 0;

        while (sequence[i++] < sequence[size]);
        while (sequence[i++] > sequence[size]);

        if (i < size) {
            return false;
        }
    }

    return true;
}

int main() {



    return 0;
}
