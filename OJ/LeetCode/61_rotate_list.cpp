#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) { }
};

ListNode* ratateRight(ListNode *head, int k) {
    if (!head) return head;

    int len = 1;
    ListNode *new_head, *tail;
    new_head = tail = head;

    while (tail->next) {
        tail = tail->next;
        ++len;
    }
    tail->next = head;  // circle the link

    if (k %= len) {
        for (int i = 0; i < len - k; ++i) tail = tail->next;
    }
    new_head = tail->next;
    tail->next = NULL;
    return new_head;
}

int main() {
    return 0;
}
