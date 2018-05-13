#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <list>
#include <algorithm>
#include "tree_node.hpp"
using namespace std;

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode *root) {
        if (!root) return vector<vector<int>>();

        queue<TreeNode *> que;
        que.push(root);
        list<vector<int>> lst;

        while (!que.empty()) {
            vector<int> cur_level;
            int size = que.size();
            for (int i = 0; i < size; ++i) {
                TreeNode *node = que.front(); que.pop();
                cur_level.push_back(node->val);

                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }

            lst.push_front(cur_level);
        }

        return vector<vector<int>>(lst.begin(), lst.end());
    }
};

int main() {
    return 0;
}
