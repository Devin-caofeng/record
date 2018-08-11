#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "../tree_node.hpp"
#include "../list_node.hpp"
using namespace std;

class Solution {
public:
    vector<int> rightSideView(TreeNode *root) {
        vector<int> res;
        recursion(root, 1, res);
        return res;
    }

private:
    void recursion(TreeNode *root, size_t level, vector<int> &res) {
        if (root == nullptr) return;
        if (res.size() < level) res.emplace_back(root->val);
        recursion(root->right, level + 1, res);
        recursion(root->left, level + 1, res);
    }
};

int main() {
    return 0;
}
