#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) { }
};

class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (!root) return;

        queue<TreeLinkNode *> que;
        que.push(root);

        while (!que.empty()) {
            int n = que.size();
            TreeLinkNode *last = NULL, *cur = NULL;;

            for (int i = 0; i < n; ++i) {
                cur = que.front(); que.pop();
                if (last) last->next = cur;
                last = cur;

                if (cur->left) que.push(cur->left);
                if (cur->right) que.push(cur->right);
            }

            cur->next = NULL;
        }
    }

    void connect2(TreeLinkNode *root) {
        if (!root) return;

        TreeLinkNode *start = root, *cur = root;
        while (start->left) {
            cur = start;

            while (cur) {
                cur->left->next = cur->right;
                if (cur->next) cur->right->next = cur->next->left;
                cur = cur->next;
            }

            start = start->left;
        }
    }
};

int main() {
    return 0;
}
