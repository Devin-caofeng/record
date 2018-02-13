#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x = 0) : val(x), left(nullptr), right(nullptr) { }
};

class Solution {
public:
    TreeNode *KthNode(TreeNode *root, int k) {
        if (root == nullptr) return nullptr;

        TreeNode *ret = nullptr;
        if ((ret = KthNode(root->left, k)) != nullptr) return ret;
        ++count;

        if (count == k) return root;

        if ((ret = KthNode(root->right, k)) != nullptr) return ret;

        return nullptr;
    }

private:
    int count = 0;
};
