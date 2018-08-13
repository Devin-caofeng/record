#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include "../tree_node.hpp"
#include "../list_node.hpp"
using namespace std;

class Solution {
public:
    int countNodes(TreeNode* root) {
        int left_height = 0, right_height = 0;
        TreeNode *left = root, *right = root;
        while (left) {
            ++left_height;
            left = left->left;
        }
        while (right) {
            ++right_height;
            right = right->right;
        }

        if (left_height == right_height) return pow(2, left_height) + 1;
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};

int main() {
    return 0;
}
