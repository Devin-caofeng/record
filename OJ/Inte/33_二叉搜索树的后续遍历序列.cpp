#include <iostream>
using namespace std;

bool VerifySquenceOfBSt(int sequence[], int len) {
    if (sequence == nullptr || len < 0) return false;

    int root = sequence[len - 1];

    // 在二叉搜索树中左子树的结点小于根节点
    int i = 0;
    for (; i < len - 1; ++i) {
        if (sequence[i] > root) break;
    }

    // 在二叉搜索树中右子树的节点大于根节点
    int j = i;
    for (; j < len - 1; ++j) {
        if (sequence[j] < root) return false;
    }

    // 判断左子树是不是二叉搜索树
    bool left = true;
    if (i > 0) left = VerifySquenceOfBSt(sequence, i);

    // 判断右子树是不是二叉搜索树
    bool right = true;
    if (i < len - 1) right = VerifySquenceOfBSt(sequence + i, len - i - 1);

    return left && right;
}

int main() {

    return 0;
}
