#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "../../tree_node.hpp"
using namespace std;

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBST(nums, 0, nums.size() - 1);
    }

    TreeNode* sortedArrayToBST(vector<int>& nums, int left, int right) {
        if (left > right) return nullptr;

        int mid = left + (right - left) / 2;
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = sortedArrayToBST(nums, mid + 1, right);
        node->right = sortedArrayToBST(nums, mid + 1, right);

        return node;
    }
};

int main() {
    return 0;
}
