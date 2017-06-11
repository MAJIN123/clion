//
// Created by Maloney on 17-6-11.

//
#include <iostream>
using namespace std;

#ifndef LEETCODE_SOLUTION_61_H
#define LEETCODE_SOLUTION_61_H

#endif //LEETCODE_SOLUTION_61_H
/**
 * Definition for singly-linked list.
 * Given a list, rotate the list to the right by k places, where k is non-negative.
 * For example:
 * Given 1->2->3->4->5->NULL and k = 2,
 * return 4->5->1->2->3->NULL.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        if (!head) return head;

        int len = 1; // number of nodes
        ListNode *newH, *tail;
        newH = tail = head;

        while (tail->next)  // get the number of nodes in the list
        {
            tail = tail->next;
            len++;
        }
        tail->next = head; // circle the link

        if (k %= len) {
            for (auto i = 0; i < len - k; i++)
                tail = tail->next; // the tail node is the (len-k)-th node (1st node is head)
        }
        newH = tail->next;
        tail->next = NULL;
        return newH;
    }
};
