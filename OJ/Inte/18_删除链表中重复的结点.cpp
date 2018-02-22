#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using std::vector;
using std::string;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) { }
};

class Solution {
public:
    ListNode *DeleteDuplication(ListNode *head) {
        if (head == NULL) return NULL;
        if (head != NULL && head->next == NULL) return head;

        ListNode *curr;
        if (head->next->val == head->val) {
            curr = head->next->next;
            while (curr != NULL && curr->val == head->val) curr = curr->next;

            return DeleteDuplication(curr);
        }
        else {
            curr = head->next;
            head->next = DeleteDuplication(curr);
            return head;
        }
    }
};

int main() {



    return 0;
}
