#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "tree_node.hpp"
using namespace std;

class Solution {
public:
    int pathSum(TreeNode *root, int sum) {
        if (!root) return 0;
        return sumUp(root, 0, sum) +
               pathSum(root->left, sum) + pathSum(root->right, sum);
    }

    int sumUp(TreeNode *node, int pre, int &sum) {
        if (!node) return 0;
        int cur = pre + node->val;
        return (cur == sum) +
               sumUp(node->left, cur, sum) + sumUp(node->right, cur, sum);
    }
};

int main() {
    return 0;
}
