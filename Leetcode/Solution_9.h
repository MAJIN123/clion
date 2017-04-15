//
// Created by Maloney on 17-4-15.
//
#include <iostream>
using namespace std;

#include <string>

#ifndef LEETCODE_SOLUTION_9_H
#define LEETCODE_SOLUTION_9_H

#endif //LEETCODE_SOLUTION_9_H
/**
 * Determine whether an integer is a palindrome
 * Do this without extra space.
 */

class Solution_9 {
public:
    bool isPalindrome(int x) {
        if(x<0)
            return false;
        int tmp=1;
        while(x/tmp>=10){
            tmp*=10;
        }
        while(x>0){
            int left=x/tmp;
            int right=x%10;
            if(left==right){
                x=(x%tmp)/10;
                tmp/=100;
            }
            else
                return 0;
        }
        return 1;
    }
};