#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) { }
};

class Solution {
public:
    bool HasSubtree(TreeNode *root1, TreeNode *root2) {
        if (root2 == nullptr || root1 == nullptr) return false;

        return IsSubtree(root1, root2) ||
               HasSubtree(root1->left, root2) ||
               HasSubtree(root1->right, root2);
    }

    bool IsSubtree(TreeNode *root1, TreeNode *root2) {
        if (root2 == nullptr) return true;
        if (root1 == nullptr) return false;

        return root1->val == root2->val &&
               IsSubtree(root1->left, root2->left) &&
               IsSubtree(root1->left, root2->right);
    }
};

int main() {



    return 0;
}
