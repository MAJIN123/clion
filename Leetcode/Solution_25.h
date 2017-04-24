//
// Created by Maloney on 17-4-24.
//
#include <iostream>
using namespace std;

#include <stack>

#ifndef LEETCODE_SOLUTION_25_H
#define LEETCODE_SOLUTION_25_H

#endif //LEETCODE_SOLUTION_25_H

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution_25 {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        if (!head)
            return head;
        ListNode *p = head;
        ListNode *q;
        ListNode result(INT32_MIN);
        ListNode *current = &result;
        stack<ListNode *> stack_of_ListNode;
        bool flag = false;
        while (true) {
            q = p;
            for (int i = 0; i < k; ++i) {
                if (!p) {
                    flag = true;
                    break;
                }
                stack_of_ListNode.push(p);
                p = p->next;
            }
            if (flag)
                break;
            while (!stack_of_ListNode.empty()) {
                current->next = stack_of_ListNode.top();
                stack_of_ListNode.pop();
                current = current->next;
            }
        }
        if (flag)
            current->next = q;
        return result.next;
    }
};