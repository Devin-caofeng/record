#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include "tree_node.hpp"
using namespace std;

class Solution {
public:
    TreeNode *bulidTree(vector<int> &inorder, vector<int> &postorder) {
        return bulidTree(inorder, 0, inorder.size() - 1,
                         postorder, 0, postorder.size() - 1);
    }

private:
    TreeNode *bulidTree(vector<int> &inorder, int in_left, int in_right,
                        vector<int> &postorder, int post_left, int post_right) {
        if (in_left > in_right || post_left > post_right) return NULL;

        size_t i = 0;
        for (i = in_left; i < inorder.size(); ++i) {
            if (inorder[i] == postorder[post_right]) break;
        }

        TreeNode *cur = new TreeNode(postorder[post_right]);
        cur->right =
            bulidTree(inorder, i + 1, in_right,
                      postorder, post_left + i - in_left, post_right - 1);
        cur->left =
            bulidTree(inorder, in_left, i - 1,
                      postorder, post_left, post_left + i - in_left - 1);
        return cur;
    }
};

int main() {
    return 0;
}
