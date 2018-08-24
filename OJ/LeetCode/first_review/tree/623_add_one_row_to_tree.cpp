#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "../tree_node.hpp"
#include "../list_node.hpp"
using namespace std;

class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if (d == 0 || d == 1) {
            TreeNode* new_node = new TreeNode(v);
            (d ? new_node->left : new_node->right) = root;
            return new_node;
        }
        if (root && d > 1) {
            root->left = addOneRow(root->left, v, (d > 2) ? (d - 1) : 1);
            root->right = addOneRow(root->right, v, (d > 2) ? (d - 1) : 0);
        }
        return root;
    }
};

int main() {
    return 0;
}
