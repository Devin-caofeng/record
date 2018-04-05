#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) { }
};

ListNode* deleteDuplicates(ListNode* head) {
    if (!head || !head->next) return head;

    int val = head->val;
    ListNode* cur = head->next;

    if (cur->val != val) {
        head->next = deleteDuplicates(cur);
        return head;
    }
    else {
        while (cur && cur->val == val) cur = cur->next;
        return deleteDuplicates(cur);
    }
}

ListNode* deleteDuplicates_2(ListNode *head) {
    ListNode **cur = &head;

    if (!head || !head->next) return head;

    while (*cur) {
        if ((*cur)->next && (*cur)->next->val == (*cur)->val) {
            ListNode *temp = *cur;
            while (temp && (*cur)->val == temp->val) temp = temp->next;
            *cur = temp;
        }
        else {
            cur = &((*cur)->next);
        }
    }
    return head;
}

int main() {
    return 0;
}
