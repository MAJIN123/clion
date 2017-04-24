//
// Created by Maloney on 17-4-24.
//
#include <iostream>
using namespace std;

#ifndef LEETCODE_SOLUTION_29_H
#define LEETCODE_SOLUTION_29_H

#endif //LEETCODE_SOLUTION_29_H

class Solution {
public:
    /**
     * Divide two integers without using multiplication, division and mod operator.
     * @param dividend
     * @param divisor
     * @return
     */
    int divide(int dividend, int divisor) {
        if (divisor == 0 || dividend == INT32_MIN && divisor == -1)
            return INT32_MAX;
        int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;
        long long a = labs(dividend);
        long long b = labs(divisor);
        int res = 0;
        while (a >= b) {
            long long tmp = b, mul = 1;
            while (a >= (tmp << 1)) {
                tmp <<= 1;
                mul <<= 1;
            }
            a -= tmp;
            res += mul;
        }
        return sign == 1 ? res : -res;
    }
};