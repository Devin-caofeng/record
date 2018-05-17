#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "tree_node.hpp"
using namespace std;

class Solution {
public:
    bool hasPathSum(TreeNode *root, int sum) {
        if (!root) return false;
        if (!root->left && !root->right && root->val == sum) return true;

        return hasPathSum(root->left, sum - root->val) ||
               hasPathSum(root->right, sum - root->val);
    }

// private:
//     bool hasPathSum(TreeNode *root, int sum, int cur) {
//         if (!root) {
//             if (sum == cur) return true;
//             else return false;
//         }

//         if (root->left && root->right) {
//             return hasPathSum(root->left, sum, cur + root->val) ||
//                    hasPathSum(root->right, sum, cur + root->val);
//         }
//         else if (root->right) {
//             return hasPathSum(root->right, sum, cur + root->right->val);
//         }
//         else if (root->left) {
//             return hasPathSum(root->left, sum, cur + root->left->val);
//         }
//         else {
//             return hasPathSum(NULL, sum, cur + root->val);
//         }
//     }
};

int main() {
    return 0;
}
