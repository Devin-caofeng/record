#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "tree_node.hpp"
using namespace std;

class Solution {
public:
    void recoverTree(TreeNode *root) {
        vector<TreeNode *> lst;
        vector<int>        vals;

        inorder(root, lst, vals);
        sort(vals.begin(), vals.end());
        for (size_t i = 0; i < lst.size(); ++i) {
            lst[i]->val = vals[i];
        }
    }

private:
    void inorder(const TreeNode *root, vector<TreeNode *> &lst,
                 vector<int> &vals) {
        if (!root) return;
        inorder(root->left, lst, vals);
        lst.push_back(const_cast<TreeNode *>(root));
        vals.push_back(root->val);
        inorder(root->right, lst, vals);
    }

};

int main() {
    return 0;
}
