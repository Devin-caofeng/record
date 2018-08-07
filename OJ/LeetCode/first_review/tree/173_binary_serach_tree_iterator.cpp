#include <stack>
#include "../tree_node.hpp"

using namespace std;

class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        pushAll(root);
    }

    bool hasNext() {
        return !stk_.empty();
    }

    int next() {
        TreeNode *node = stk_.top();
        stk_.pop();
        pushAll(node->right);
        return node->val;
    }

private:
    void pushAll(TreeNode *node) {
        for (; node != nullptr; node = node->left) {
            stk_.push(node);
        }
    }

    stack<TreeNode *> stk_;
};
