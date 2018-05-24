#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "tree_node.hpp"
using namespace std;

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode *root, int sum) {
        vector<vector<int>> res;
        vector<int> cur;
        pathSum(root, sum, cur, res);

        return res;
    }

private:
    void pathSum(TreeNode *node, int sum, vector<int> &cur,
                 vector<vector<int>> &res) {
        if (!node) return;

        cur.push_back(node->val);
        if (sum == node->val && !node->left && !node->right) {
            res.push_back(cur);
        }

        pathSum(node->left, sum - node->val, cur, res);
        pathSum(node->right, sum - node->val, cur, res);

        cur.pop_back();
    }
};

int main() {
    return 0;
}
