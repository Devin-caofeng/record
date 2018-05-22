#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include "tree_node.hpp"
using namespace std;

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        vector<vector<int>> res;
        if (!root) return res;

        queue<TreeNode *> que;
        que.push(root);
        bool left_to_right = 1;

        while (!que.empty()) {
            vector<int> tmp(que.size());

            size_t n = que.size();
            for (size_t i = 0; i < n; ++i) {
                TreeNode *cur = que.front(); que.pop();

                int index = left_to_right ? i : n - i - 1;
                tmp[index] = cur->val;

                if (cur->left) que.push(cur->left);
                if (cur->right) que.push(cur->right);
            }

            left_to_right = !left_to_right;
            res.push_back(std::move(tmp));
        }

        return res;
    }
};

int main() {
    return 0;
}
