#include "../need.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode *RemoveNthFromEndList(ListNode *head, int n) {
        ListNode **dummy = &head;
        ListNode *cur = head;

        for (int i = 1; i < n; ++i) cur = cur->next;
        while (cur->next != NULL) {
            dummy = &((*dummy)->next);
            cur = cur->next;
        }
        *dummy = (*dummy)->next;

        return head;
    }
};

int main() {



    return 0;
}
