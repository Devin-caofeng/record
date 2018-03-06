#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using std::vector;
using std::string;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) { }
};

ListNode* swapPairs(ListNode *head) {
    if (head == nullptr) return nullptr;
    if (head->next == nullptr) return head;

    ListNode *temp = head->next;
    head->next = swapPairs(temp->next);
    temp->next = head;

    return temp;
}

int main() {



    return 0;
}
