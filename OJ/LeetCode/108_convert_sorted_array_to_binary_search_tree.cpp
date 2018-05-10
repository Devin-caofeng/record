#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "tree_node.hpp"
using namespace std;

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int> &nums) {
        return sortedArrayToBST(nums, 0, nums.size() - 1);
    }

    TreeNode *sortedArrayToBST(vector<int> &nums, int left, int right) {
        if (left > right) return NULL;

        int mid = left + (right - left) / 2;
        TreeNode *newNode = new TreeNode(nums[mid]);

        newNode->left = sortedArrayToBST(nums, left, mid - 1);
        newNode->right= sortedArrayToBST(nums, mid + 1, right);

        return newNode;
    }
};

int main() {
    return 0;
}
