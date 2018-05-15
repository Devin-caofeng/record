#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "tree_node.hpp"
using namespace std;

class Solution {
public:
    int minDepth(TreeNode *root) {
        if (!root) return 0;

        if      (!root->left)  return minDepth(root->right) + 1;
        else if (!root->right) return minDepth(root->left) + 1;
        else                   return min(minDepth(root->left),
                                          minDepth(root->right)) + 1;
    }
};

int main() {
    return 0;
}
