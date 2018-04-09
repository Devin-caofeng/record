#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "tree_node.hpp"
using namespace std;

vector<TreeNode *> generateTree(int from, int to) {
    vector<TreeNode *> ret;
    if (to - from < 0) ret.push_back(0);
    if (to - from == 0) ret.push_back(new TreeNode(from));
    if (to - from > 0) {
        for (int i = from; i <= to; ++i) {
            vector<TreeNode *> left = generateTree(from, i - 1);
            vector<TreeNode *> right = generateTree(i + 1, to);

            for (size_t j = 0; j < left.size(); ++j) {
                for (size_t k = 0; k < right.size(); ++k) {
                    TreeNode *h = new TreeNode(i);
                    h->left = left[j];
                    h->right = right[k];
                    ret.push_back(h);
                }
            }
        }
    }
    return ret;
}

vector<TreeNode *> generateTree(int n) {
    return generateTree(1, n);
}

int main() {
    return 0;
}
