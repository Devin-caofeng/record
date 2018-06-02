#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "list_node.hpp"
using namespace std;

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *fast = head, *slow = head;

        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) return true;
        }

        return false;
    }
};

int main() {
    return 0;
}
