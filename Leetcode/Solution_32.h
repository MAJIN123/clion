//
// Created by Maloney on 17-5-5.
//
#include <iostream>
using namespace std;

#include <stack>
#ifndef LEETCODE_SOLUTION_32_H
#define LEETCODE_SOLUTION_32_H

#endif //LEETCODE_SOLUTION_32_H

class Solution_32 {
public:
    /**
     * Longest Valid Parentheses
     * @param s
     * @return
     */
    int longestValidParentheses(string s) {
        stack<int> tmp;
        tmp.push(-1);
        int maxL=0;
        for(int i=0;i<s.size();++i){
            int k=tmp.top();
            if(k!=-1&&s[i]==')'&&s[k]=='('){
                tmp.pop();
                maxL=max(maxL,i-tmp.top());
            }
            else
                tmp.push(i);
        }
        return maxL;
    }
};
