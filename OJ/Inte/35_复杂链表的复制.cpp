#include <iostream>
#include <string>

struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) { }
};

class Solution {
public:
    RandomListNode *Clone(RandomListNode *head) {
        if (!head) return NULL;

        RandomListNode *curr = head;
        while (curr) {
            RandomListNode *node = new RandomListNode(curr->label);
            node->next = curr->next;
            curr->next = node;
            curr = node->next;
        }

        curr = head;
        while (curr) {
            RandomListNode *node = curr->next;
            if (curr->random) {
                node->random = curr->random->next;
            }
            curr = node->next;
        }

        // 拆分
        RandomListNode *clone_head = head->next;
        RandomListNode *temp;
        curr = head;
        while (curr->next) {
            temp = curr->next;
            curr->next = temp->next;
            curr = temp;
        }
        return clone_head;
    }
};

int main() {



    return 0;
}
