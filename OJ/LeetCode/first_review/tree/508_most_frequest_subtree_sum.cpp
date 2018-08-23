#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include "../tree_node.hpp"
#include "../list_node.hpp"
using namespace std;

class Solution {
public:
    vector<int> findFrequestTreeSum(TreeNode* root) {
        vector<int> res;
        unordered_map<int, int> mp;
        int cnt = 0;
        postorder(root, mp, cnt, res);
        return res;
    }

    int postorder(TreeNode* node, unordered_map<int, int>& mp,
                  int& cnt, vector<int>& res) {
        if (!node) return 0;
        int left = postorder(node->left, mp, cnt, res);
        int right = postorder(node->right, mp, cnt, res);
        int sum = left + right + node->val;
        ++mp[sum];

        if (mp[sum] >= cnt) {
            if (mp[sum] > cnt) res.clear();
            res.emplace_back(sum);
            cnt = mp[sum];
        }
        return sum;
    }
};

int main() {
    return 0;
}
