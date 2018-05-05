#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>
#include "tree_node.hpp"
using namespace std;

class Solution {
public:
    int maxPathSum(TreeNode *root) {
        int res = INT_MIN;
        maxPathSum(root, res);
        return res;
    }

private:
    int maxPathSum(TreeNode *node, int &res) {
        if (!node) return 0;

        int left = max(maxPathSum(node->left, res), 0);
        int right = max(maxPathSum(node->right, res), 0);
        res = max(res, left + right + node->val);

        return max(left, right) + node->val;
    }
};

int main() {
    return 0;
}
