//
// Created by Maloney on 17-6-10.

//

#include <iostream>
using namespace std;

#include <vector>

#ifndef LEETCODE_SOLUTION_60_H
#define LEETCODE_SOLUTION_60_H

#endif //LEETCODE_SOLUTION_60_H
/**
 * Permutation Sequence
 * The set [1,2,3,…,n] contains a total of n! unique permutations.
 * By listing and labeling all of the permutations in order,
 * We get the following sequence (ie, for n = 3):
 * Given n and k, return the kth permutation sequence.
 * Note: Given n will be between 1 and 9 inclusive.
    "123"
    "132"
    "213"
    "231"
    "312"
    "321"
 */
class Solution {
public:
    string getPermutation(int n, int k) {
        string res;
        vector<char> num;
        for (int i = 1; i < 10; ++i)
            num.push_back(i + '0');
        int pTable[10] = {1};
        for (int i = 1; i < 10; ++i)
            pTable[i] = pTable[i - 1] * i;
        while (n > 0) {
            int tmp = (k - 1) / pTable[n - 1];
            res += num[tmp];
            num.erase(num.begin() + tmp);
            k = k - tmp * pTable[n - 1];
            n--;
        }
        return res;
    }
};