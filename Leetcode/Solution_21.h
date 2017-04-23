//
// Created by Maloney on 17-4-23.
//
#include <iostream>
using namespace std;

#ifndef LEETCODE_SOLUTION_21_H
#define LEETCODE_SOLUTION_21_H

#endif //LEETCODE_SOLUTION_21_H
/**
 * Merge Two Sorted Lists
 */

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution_21 {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *p = l1;
        ListNode *q = l2;
        ListNode *result = new ListNode(-1);
        ListNode *current = result;

        while (p && q) {
            if (p->val < q->val) {
                current->next = p;
                p = p->next;
            } else {
                current->next = q;
                q = q->next;
            }
            current = current->next;
        }
        current->next = p ? p : q;
        return result->next;
    }
};