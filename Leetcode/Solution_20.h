//
// Created by Maloney on 17-4-21.
//
#include <iostream>
using namespace std;

#include <stack>

#ifndef LEETCODE_SOLUTION_20_H
#define LEETCODE_SOLUTION_20_H

#endif //LEETCODE_SOLUTION_20_H
/**
 * Given a string containing just the characters '(', ')', '{', '}', '[' and ']',
 * determine if the input string is valid.
 * The brackets must close in the correct order, "()" and "()[]{}" are all valid
 * but "(]" and "([)]" are not.
 */

class Solution_20 {
public:
    bool isValid(string s) {
        stack<char> stack_char;
        for(char &ch:s){
            switch(ch){
                case '(':
                case '{':
                case '[': stack_char.push(ch); break;
                case ')': if(stack_char.empty()||stack_char.top()!='(')
                        return false;
                    else
                        stack_char.pop();
                    break;
                case '}': if(stack_char.empty()||stack_char.top()!='{')
                        return false;
                    else
                        stack_char.pop();
                    break;
                case ']': if(stack_char.empty()||stack_char.top()!='[')
                        return false;
                    else
                        stack_char.pop();
                    break;
                default: ;
            }
        }
        return stack_char.empty();
    }
};