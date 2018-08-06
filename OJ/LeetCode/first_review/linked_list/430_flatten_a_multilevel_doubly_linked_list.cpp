class Node {
public:
    int val = 0;
    Node* prev = nullptr;
    Node* next = nullptr;
    Node* child = nullptr;

    Node() = default;

    Node(int val, Node* prev, Node* next, Node* child)
        : val(val), prev(prev), next(next), child(child)
    {
    }
};

class Solution {
public:
    Node* flatten(Node* head) {
        for (Node* h = head; h != nullptr; h = h->next) {
            if (h->child) {
                Node* next = h->next;
                h->next = h->child;
                h->next->prev = h;
                h->child = nullptr;
                Node* p = h->next;
                while (p->next) p = p->next;
                p->next = next;
                if (next) next->prev = p;
            }
        }
        return head;
    }
};
