//
// Created by Maloney on 17-6-9.
//
#include <iostream>
using namespace std;

#include <vector>
#ifndef LEETCODE_SOLUTION_53_H
#define LEETCODE_SOLUTION_53_H

#endif //LEETCODE_SOLUTION_53_H
/**
 * Maximum Subarray
 * Find the contiguous subarray within an array /
 * (containing at least one number) which has the largest sum.
 * For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
 * the contiguous subarray [4,-1,2,1] has the largest sum = 6.
 */
class Solution {
public:
    int maxSubArray(vector<int> &nums) {
        int res = nums[0];
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            res = max(res, sum);
            sum = max(sum, 0);
        }
        return res;
    }
};
