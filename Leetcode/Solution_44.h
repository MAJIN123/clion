//
// Created by Maloney on 17-5-15.
//
#include <iostream>
using namespace std;

#ifndef LEETCODE_SOLUTION_44_H
#define LEETCODE_SOLUTION_44_H

#endif //LEETCODE_SOLUTION_44_H

/**
 * '?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "*") → true
isMatch("aa", "a*") → true
isMatch("ab", "?*") → true
isMatch("aab", "c*a*b") → false

 */
class Solution_44 {
public:
    /**
     * Wildcard Matching
     * @param s
     * @param p
     * @return
     */
    bool isMatch(string s, string p) {
        int i = 0, j = 0;
        int x = 0, y = -1;
        while (i < s.length()) {
            if (j < p.length() && p[j] == '?' || s[i] == p[j]) {
                ++i;
                ++j;
                continue;
            }
            if (j < p.length() && p[j] == '*') {
                y = j;
                x = i;
                ++j;
                continue;
            }
            if (y != -1) {
                j = y + 1;
                i = x + 1;
                ++x;
                continue;
            }
            return false;
        }
        while (j < p.length() && p[j] == '*')
            ++j;
        return p.length() == j;
    }
};