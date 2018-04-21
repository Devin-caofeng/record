#ifndef LIST_NODE_HPP_
#define LIST_NODE_HPP_

#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) { }
};


#endif  // LIST_NODE_HPP_
