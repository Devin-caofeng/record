#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "tree_node.hpp"
using namespace std;

class Solution {
public:
    void flatten(TreeNode *root) {
        if (!root) return;
        if (root->left) flatten(root->left);
        if (root->right) flatten(root->right);

        TreeNode *tmp = root->right;
        root->right = root->left;
        root->left = NULL;

        while (root->right) root = root->right;
        root->right = tmp;
    }

    void flatten2(TreeNode *root) {
        TreeNode *cur = root;
        while (cur) {
            if (cur->left) {
                TreeNode *tmp = cur->left;
                while (tmp->right) tmp = tmp->right;
                tmp->right = cur->right;
                cur->right = cur->left;
                cur->left = NULL;
            }
            cur = cur->right;
        }
    }
};

int main() {
    return 0;
}
