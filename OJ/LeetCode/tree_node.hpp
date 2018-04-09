#ifndef TREE_NODE_HPP_
#define TREE_NODE_HPP_

#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) { }
};


#endif  // TREE_NODE_HPP_
