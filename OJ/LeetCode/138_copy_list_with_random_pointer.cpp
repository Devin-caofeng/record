#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) { }
};

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (!head) return NULL;

        RandomListNode *cur = head;
        while (cur) {
            RandomListNode *node = new RandomListNode(cur->label);
            node->next = cur->next;
            cur->next = node;
            cur = node->next;
        }

        cur = head;
        while (cur) {
            if (cur->random) cur->next->random = cur->random->next;
            cur = cur->next->next;
        }

        cur = head;
        RandomListNode *res = head->next;
        while (cur) {
            RandomListNode *tmp = cur->next;
            cur->next = tmp->next;
            if (tmp->next) tmp->next = tmp->next->next;
            cur = cur->next;
        }

        return res;
    }

    RandomListNode *copyRandomList2(RandomListNode *head) {
        if (!head) return NULL;

        RandomListNode *res = new RandomListNode(head->label);
        RandomListNode *node = res;
        RandomListNode *cur = head->next;
        map<RandomListNode *, RandomListNode *> mp;
        mp[head] = res;

        while (cur) {
            RandomListNode *tmp = new RandomListNode(cur->label);
            node->next = tmp;
            mp[cur] = tmp;
            node = node->next;
            cur = cur->next;
        }

        node = res;
        cur = head;
        while (node) {
            node->random = mp[cur->random];
            node = node->next;
            cur = cur->next;
        }

        return res;
    }
};

int main() {
    return 0;
}
