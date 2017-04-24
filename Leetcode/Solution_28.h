//
// Created by Maloney on 17-4-24.
//
#include <iostream>
using namespace std;

#include <string>
#ifndef LEETCODE_SOLUTION_28_H
#define LEETCODE_SOLUTION_28_H

#endif //LEETCODE_SOLUTION_28_H
/**
 * Implement strStr()
 */
class Solution_28 {
public:
    /**
     * @param haystack
     * @param needle
     * @return the index of the first occurrence of needle in haystack
     * Returns -1 if needle is not part of haystack.
     */
    int strStr(string haystack, string needle) {
        if (haystack.size() < needle.size())
            return -1;
        bool flag;
        for (int i = 0; i <= haystack.size() - needle.size(); ++i) {
            flag = true;
            for (int j = 0; j < needle.size(); ++j) {
                if (needle[j] != haystack[i + j]) {
                    flag = false;
                    break;
                }
            }
            if (flag)
                return i;
        }
        return -1;
    }
};