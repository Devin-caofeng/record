#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "../tree_node.hpp"
#include "../list_node.hpp"
using namespace std;

class Solution {
public:
    int wightOfBinaryTree(TreeNode* root) {
        int res = 0;
        vector<int> start;
        helper(root, 0, 0, start, res);
        return res;
    }

    void helper(TreeNode* node, size_t height, int index,
                vector<int>& start, int& res) {
        if (!node) return;
        if (height >= start.size()) start.emplace_back(index);
        res = max(res, index - start[height] + 1);
        helper(node->left, height + 1, index * 2, start, res);
        helper(node->right, height + 1, index * 2 + 1, start, res);
    }
};

int main() {
    return 0;
}
