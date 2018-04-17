#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "list_node.hpp"
using namespace std;

ListNode *reverseKGroup(ListNode *head, int k) {
    if (!head || !head->next || k < 2) return head;
    ListNode pre(0);
    pre.next = head;

    for (ListNode *begin = &pre, *end = &pre; true; begin = head, end = head) {
        for (int cnt = k; cnt > 0; --cnt) {
            if (!(end = end->next)) return pre.next;
        }

        for (head = begin->next; begin->next != end; ) {
            ListNode *next = begin->next;
            begin->next = next->next;
            next->next = end->next;
            end->next = next;
        }
    }
    return pre.next;
}

ListNode *reverseKGroup_2(ListNode *head, int k) {
    if (head == NULL || k <= 1) return head;
    int num = 0;
    ListNode *pre_head = new ListNode(0);
    pre_head->next = head;
    ListNode *cur = pre_head, *next, *pre = pre_head;

    while ((cur = cur->next)) ++num;

    while (num >= k) {
        cur = pre->next;
        next = cur->next;
        for (int i = 1; i < k; ++i) {
            cur->next = next->next;
            next->next = pre->next;
            pre->next = next;
            next = cur->next;
        }
        pre = cur;
        num -= k;
    }
    return pre_head->next;
}

int main() {
    return 0;
}
