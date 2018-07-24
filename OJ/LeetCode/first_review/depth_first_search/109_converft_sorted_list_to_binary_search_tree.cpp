#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "../../tree_node.hpp"
#include "../../list_node.hpp"
using namespace std;

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        return sortedListToBST(head, nullptr);
    }

private:
    TreeNode* sortedListToBST(ListNode* head, ListNode* tail) {
        if (head == tail) return nullptr;

        if (head->next == tail) {
            TreeNode* node = new TreeNode(head->val);
            return node;
        }

        ListNode* mid = head;
        ListNode* tmp = head;
        while (tmp != tail && tmp->next != tail) {
            mid = mid->next;
            tmp = tmp->next->next;
        }

        TreeNode* node = new TreeNode(mid->val);
        node->left = sortedListToBST(head, mid);
        node->right = sortedListToBST(mid->next, tail);
        return node;
    }
};

int main() {
    return 0;
}
