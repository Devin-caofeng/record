#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include "tree_node.hpp"
using namespace std;

class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        if (!root) return true;
        return isSymmetric(root->left, root->right);
    }

    bool isSymmetric_Iter(TreeNode *root) {
        if (!root) return true;

        queue<TreeNode *> que1, que2;
        que1.push(root->left);
        que2.push(root->right);

        while (!que1.empty() && !que2.empty()) {
            TreeNode *node1 = que1.front();
            TreeNode *node2 = que2.front();
            que1.pop();
            que2.pop();

            if ((!node1 && node2) || (node1 && !node2)) return false;
            if (node1) {
                if (node1->val != node2->val) return false;
                que1.push(node1->left);
                que1.push(node1->right);
                que2.push(node2->right);
                que2.push(node2->left);
            }
        }

        return true;
    }

private:
    bool isSymmetric(TreeNode *left, TreeNode *right) {
        if (!left && !right) return true;
        if ((left && !right) || (!left && right) ||
                (left->val != right->val)) return false;

        return isSymmetric(left->left, right->right) &&
               isSymmetric(left->right, right->left);
    }
};

int main() {
    return 0;
}
