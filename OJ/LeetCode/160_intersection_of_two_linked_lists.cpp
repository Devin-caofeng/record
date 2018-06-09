#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "list_node.hpp"
using namespace std;

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = getListLength(headA);
        int lenB = getListLength(headB);
        int dist = abs(lenA - lenB);

        ListNode *curA = headA, *curB = headB;
        if (lenA < lenB) swap(curA, curB);

        for (int i = 0; i < dist; ++i) {
            curA = curA->next;
        }

        do {
            if (curA == curB) return curA;
            if (!curA || !curB) return NULL;
            curA = curA->next;
            curB = curB->next;
        } while (curA && curB);

        return NULL;
    }

    int getListLength(ListNode *head) {
        int cnt = 0;
        while (head) {
            head = head->next;
            ++cnt;
        }
        return cnt;
    }
};

int main() {

    ListNode *node_1 = new ListNode(1);
    ListNode *node_2 = new ListNode(3);
    node_1->next = node_2;
    ListNode *node_3 = new ListNode(5);
    node_2->next = node_3;
    ListNode *node_4 = new ListNode(6);
    node_3->next = node_4;

    ListNode *nodeB_1 = new ListNode(2);
    ListNode *nodeB_2 = new ListNode(4);
    nodeB_1->next = nodeB_2;
    nodeB_2->next = node_4;

    Solution s;
    ListNode *node = s.getIntersectionNode(node_1, nodeB_1);
    if (node) cout << node->val << endl;

    return 0;
}
