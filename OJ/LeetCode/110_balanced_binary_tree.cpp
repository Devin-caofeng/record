#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "tree_node.hpp"
using namespace std;

class Solution {
public:
    bool isBalanced(TreeNode *root) {
        if (!root) return true;
        if (abs(getDepth(root->left) - getDepth(root->right)) > 1) return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }

    int getDepth(TreeNode *root) {
        if (!root) return 0;
        return max(getDepth(root->left), getDepth(root->right)) + 1;
    }
};

int main() {
    return 0;
}
