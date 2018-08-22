#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "../tree_node.hpp"
#include "../list_node.hpp"
using namespace std;

class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        vector<int> res;
        int max_cnt = 0, cnt = 1;
        TreeNode* pre = nullptr;
        inorder(root, pre, cnt, max_cnt, res);
        return res;
    }

private:
    void inorder(TreeNode* node, TreeNode*& pre,
                 int& cnt, int& max_cnt, vector<int>& res) {
        if (!node) return;
        inorder(node->left, pre, cnt, max_cnt, res);

        if (pre) {
            cnt = (node->val == pre->val) ? cnt + 1 : 1;
        }

        if (cnt >= max_cnt) {
            if (max_cnt > cnt) res.clear();
            res.emplace_back(node->val);
            max_cnt = cnt;
        }
        pre = node;

        inorder(node->right, pre, cnt, max_cnt, res);
    }
};

int main() {
    return 0;
}
