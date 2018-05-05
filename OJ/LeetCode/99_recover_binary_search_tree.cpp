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

class S2 {
public:
    void recoverTree(TreeNode *root) {
        TreeNode *firs = nullptr, *secd = nullptr, *parent = nullptr;
        TreeNode *cur, *pre;
        cur = root;

        while (cur) {
            if (!cur->left) {
                if (parent && parent->val > cur->val) {
                    if (!firs) firs = parent;
                    secd = cur;
                }
                parent = cur;
                cur = cur->right;
            }
            else {
                pre = cur->left;
                while (pre->right && pre->right != cur) pre = pre->right;
                if (!pre->right) {
                    pre->right = cur;
                    cur = cur->left;
                }
                else {
                    pre->right = nullptr;
                    if (parent->val > cur->val) {
                        if (!firs) firs = parent;
                        secd = cur;
                    }
                    parent = cur;
                    cur = cur->right;
                }
            }
        }
        if (firs && secd) swap(firs->val, secd->val);
    }
};

int main() {
    return 0;
}
