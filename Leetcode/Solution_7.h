//
// Created by Maloney on 17-4-15.
//
#include <iostream>
using namespace std;

#ifndef LEETCODE_SOLUTION_7_H
#define LEETCODE_SOLUTION_7_H

#endif //LEETCODE_SOLUTION_7_H
/**
 * Reverse digits of an integer.
 *
 * Example1: x = 123, return 321
 * Example2: x = -123, return -321
 */
class Solution_7 {
public:
    int reverse(int x) {
        long long result=0;

        while(x){
            result=result*10+x-x/10*10;
            x/=10;
        }
        return (result>INT32_MIN&&result<INT32_MAX)?result:0;
    }
};