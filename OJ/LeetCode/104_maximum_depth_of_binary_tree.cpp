#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "tree_node.hpp"
using namespace std;

class Solution {
public:
    int maxDepth(TreeNode *root) {
        if (!root) return 0;

        int left_height = maxDepth(root->left);
        int right_height = maxDepth(root->right);

        return max(left_height, right_height) + 1;
    }
};

int main() {
    return 0;
}
