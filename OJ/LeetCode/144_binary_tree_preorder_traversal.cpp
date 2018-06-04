#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include "tree_node.hpp"
using namespace std;

class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> res;
        if (!root) return res;

        stack<TreeNode *> stk;
        TreeNode *cur = root;

        while (!stk.empty() || cur) {
            while (cur) {
                res.push_back(cur->val);
                stk.push(cur);
                cur = cur->left;
            }

            cur = stk.top()->right;
            stk.pop();
        }

        return res;
    }
};

int main() {
    return 0;
}
