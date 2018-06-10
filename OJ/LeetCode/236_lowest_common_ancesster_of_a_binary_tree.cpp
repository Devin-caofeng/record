#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "tree_node.hpp"
using namespace std;

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || p == root || q == root) return root;

        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        if (left && right) return root;
        return left ? left : right;
    }

    const TreeNode* lowestCommonAncestor_optimize(const TreeNode* root,
                                                  const TreeNode* p,
                                                  const TreeNode* q) {
        if (!root || p == root || q == root) return root;

        const TreeNode* left = lowestCommonAncestor_optimize(root->left, p, q);
        if (left && left != q && left != p) return left;

        const TreeNode* right = lowestCommonAncestor_optimize(root->right,
                                                              p, q);
        if (right && right != q && right != p) return right;

        if (left && right) return root;
        return left ? left : right;
    }
};

int main() {
    return 0;
}
