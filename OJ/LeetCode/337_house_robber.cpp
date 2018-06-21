#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "tree_node.hpp"
using namespace std;

class Solution {
public:
    int rob(TreeNode* root) {
        int l = 0, r = 0;
        return helper(root, l, r);
    }

    int helper(TreeNode* node, int& l, int& r) {
        if (!node) return 0;

        int ll = 0, lr = 0, rl = 0, rr = 0;
        l = helper(node->left, ll, lr);
        r = helper(node->right, rl, rr);
        return max(node->val + ll + lr + rl + rr, l + r);
    }
};

int main() {
    return 0;
}
