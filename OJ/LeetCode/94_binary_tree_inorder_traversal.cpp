#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) { }
};

vector<int> inorderTraversal(TreeNode *root) {
    vector<int> ret;
    for (stack<TreeNode *> node_stk; root || !node_stk.empty(); ) {
        if (root) {
            node_stk.push(root);
            root = root->left;
        }
        else {
            root = node_stk.top(); node_stk.pop();
            ret.push_back(root->val);
            root = root->right;
        }
    }

    return ret;
}

int main() {
    return 0;
}
