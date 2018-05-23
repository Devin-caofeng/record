#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include "tree_node.hpp"
using namespace std;

class Solution {
public:
    TreeNode *bulidTree(vector<int> &preorder, vector<int> &inorder) {
        return bulidTree(preorder, 0, preorder.size() - 1,
                         inorder, 0, inorder.size() - 1);
    }

private:
    TreeNode *bulidTree(vector<int> &preorder, int pre_left, int pre_right,
                        vector<int> &inorder, int in_left, int in_right) {
        if (pre_left > pre_right || in_left > in_right) return NULL;

        int i = 0;
        for (i = in_left; i <= in_right; ++i) {
            if (preorder[pre_left] == inorder[i]) break;
        }

        TreeNode *cur = new TreeNode(preorder[pre_left]);
        cur->left = bulidTree(preorder, pre_left + 1, pre_left + i - in_left,
                              inorder, in_left, i - 1);
        cur->right = bulidTree(preorder, pre_left + i - in_left + 1, pre_right,
                               inorder, i + 1, in_right);
        return cur;
    }
};

TreeNode *bulidTree(vector<int> &preorder, vector<int> &inorder) {
    TreeNode *ptr = NULL, *pp = NULL;
    size_t i = 0, j = 0;
    TreeNode *root = new TreeNode(0);
    stack<TreeNode *> stk;
    stk.push(root);

    while (j < inorder.size()) {
        if (stk.top()->val == inorder[j]) {
            pp = stk.top(); stk.pop();
            ++j;
        }
        else if (pp) {
            ptr = new TreeNode(preorder[i]);
            pp->right = ptr;
            pp = NULL;
            stk.push(pp);
            ++i;
        }
        else {
            ptr = new TreeNode(preorder[i]);
            stk.top()->left = ptr;
            stk.push(ptr);
            ++i;
        }
    }

    ptr = root->left; delete ptr;
    return ptr;
}

int main() {
    return 0;
}
