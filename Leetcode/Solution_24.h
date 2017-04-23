//
// Created by Maloney on 17-4-23.
//
#include <iostream>
using namespace std;

#ifndef LEETCODE_SOLUTION_24_H
#define LEETCODE_SOLUTION_24_H

#endif //LEETCODE_SOLUTION_24_H

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution_24 {
public:
    /**
     * Given a linked list, swap every two adjacent nodes and return its head.
     * Given 1->2->3->4, you should return the list as 2->1->4->3.
     * @param head:Linked list
     * @return the head of the Linked list
     */
    ListNode *swapPairs(ListNode *head) {
        if (!head)
            return NULL;
        ListNode result(INT32_MIN);
        ListNode *current = &result;
        current->next = head;
        ListNode *p = head;
        ListNode *q = head->next;
        while (p && q) {
            p->next = q->next;
            q->next = p;
            current->next = q;
            p = p->next;
            if (p)
                q = p->next;
            current = current->next->next;
        }
        current->next = p;
        return result.next;
    }
};