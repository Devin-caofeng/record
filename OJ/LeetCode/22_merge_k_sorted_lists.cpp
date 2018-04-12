#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        return mergeKLists(lists.cbegin(), lists.cend());
    }

private:
    ListNode *mergeKLists(vector<ListNode *>::const_iterator begin,
                          vector<ListNode *>::const_iterator end) {
        if (begin == end) {
            return NULL;
        }
        else if (distance(begin, end) == 1) {
            return *begin;
        }
        else if (distance(begin, end) == 2) {
            return mergeTwoLists(*begin, *next(begin));
        }
        else {
            return mergeTwoLists(
                       mergeKLists(begin, begin + distance(begin, end) / 2),
                       mergeKLists(begin + distance(begin, end) / 2, end));
        }
    }

    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *head = NULL, **last_pptr = &head;
        for ( ; l1 && l2; last_pptr = &((*last_pptr)->next)) {
            if (l1->val <= l2->val) {
                *last_pptr = l1;
                l1 = l1->next;
            }
            else {
                *last_pptr = l2;
                l2 = l2->next;
            }
        }
        *last_pptr = l1 ? l1 : l2;
        return head;
    }
};

int main() {
    return 0;
}
