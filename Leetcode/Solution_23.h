//
// Created by Maloney on 17-4-23.
//
#include <iostream>
using namespace std;

#include <vector>
#ifndef LEETCODE_SOLUTION_23_H
#define LEETCODE_SOLUTION_23_H

#endif //LEETCODE_SOLUTION_23_H

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution_23 {
public:
/**
 * Merge k sorted linked lists and return it as one sorted list.
 * @param lists
 * @return
 */
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if (lists.empty())
            return nullptr;
        while (lists.size() > 1) {
            lists.push_back(mergeTwoLists(lists[0], lists[1]));
            lists.erase(lists.begin());
            lists.erase(lists.begin());
        }
        return lists.front();
    }

    /**
     * Merge Two Sorted Lists
     * @param l1
     * @param l2
     * @return
     */
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *p = l1;
        ListNode *q = l2;
        ListNode *result = new ListNode(INT32_MIN);
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