//
// Created by Maloney on 17-4-12.
//
#include <iostream>
using namespace std;
#ifndef LEETCODE_SOLUTION_2_H
#define LEETCODE_SOLUTION_2_H

#endif //LEETCODE_SOLUTION_2_H

/**
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 * 342+465=807
 */
struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution_2 {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* p=l1;
        ListNode* q=l2;
        ListNode* result=new ListNode(0);
        ListNode* last=result;
        int x;
        while(p||q){
            if(p){
                x+=p->val;
                p=p->next;
            }
            if(q){
                x+=q->val;
                q=q->next;
            }
            last->next=new ListNode(x%10);
            last=last->next;
            x/=10;
        }//end for while
        if(x==1){
            last->next=new ListNode(1);
        }
        return result->next;
    }
};
