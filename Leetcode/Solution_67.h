//
// Created by Maloney on 17-7-6.

//
#include <iostream>
using namespace std;
#ifndef LEETCODE_SOLUTION_67_H
#define LEETCODE_SOLUTION_67_H

#endif //LEETCODE_SOLUTION_67_H
/**
 *  Add Binary
 *  Given two binary strings, return their sum (also a binary string).
 *  For example,
 *  a = "11"
 *  b = "1"
 *  Return "100".
 */
class Solution {
public:
    string addBinary(string a, string b) {
        string res = "";
        int c = 0, i = a.size() - 1, j = b.size() - 1;
        while (c == 1 || i >= 0 || j >= 0) {
            c += i >= 0 ? a[i--] : 0;
            c += j >= 0 ? b[j--] : 0;
            res = char(c % 2 + '0') + res;
            c /= 2;
        }
        return res;
    }
};