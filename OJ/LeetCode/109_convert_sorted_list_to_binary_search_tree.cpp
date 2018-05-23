#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "list_node.hpp"
#include "tree_node.hpp"
using namespace std;

class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        return sortedListToBST(head, NULL);
    }

private:
    TreeNode *sortedListToBST(ListNode *head, ListNode *tail) {
        if (head == tail) return NULL;

        if (head->next == tail) {
            TreeNode *root = new TreeNode(head->val);
            return root;
        }

        ListNode *mid = head, *tmp = head;
        while (tmp != tail && tmp->next != tail) {
            mid = mid->next;
            tmp = tmp->next->next;
        }

        TreeNode *root = new TreeNode(mid->val);
        root->left = sortedListToBST(head, mid);
        root->right = sortedListToBST(mid->next, tail);

        return root;
    }
};

int main() {
    return 0;
}
