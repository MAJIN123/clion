//
// Created by Maloney on 17-4-21.
//
#include <iostream>
using namespace std;

#ifndef LEETCODE_SOLUTION_19_H
#define LEETCODE_SOLUTION_19_H

#endif //LEETCODE_SOLUTION_19_H

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution_19 {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
       if(!head)
           return NULL;
        //建立头节点
        ListNode* new_head=new ListNode(-1);
        new_head->next=head;
        ListNode* p=new_head;
        ListNode* q=new_head;
        for(int i=0;i<n;++i)
            p=p->next;
        while(p->next){
            p=p->next;
            q=q->next;
        }
        ListNode* to_be_deleted=q->next;
        q->next=to_be_deleted->next;
        delete to_be_deleted;
        return new_head->next;
    }
};