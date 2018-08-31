#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "../tree_node.hpp"
#include "../list_node.hpp"
using namespace std;

class Solution {
public:
    TreeNode* pruneTree(TreeNode* root) {
        return cotainOne(root) ? root : nullptr;
    }

    bool cotainOne(TreeNode* const root) {
        if (!root) return false;
        bool left = cotainOne(root->left);
        bool right = cotainOne(root->right);
        if (!left) root->left = nullptr;
        if (!right) root->right = nullptr;
        return (root->val == 1) ? true : (left || right);
    }
};

int main() {
    return 0;
}
