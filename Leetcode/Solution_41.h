//
// Created by Maloney on 17-5-9.
//
#include <iostream>
using namespace std;

#include <algorithm>
#include <vector>
#ifndef LEETCODE_SOLUTION_41_H
#define LEETCODE_SOLUTION_41_H

#endif //LEETCODE_SOLUTION_41_H
/**
 *  Given an unsorted integer array, find the first missing positive integer.
 *  For example,
 *  Given [1,2,0] return 3,
 *  and [3,4,-1,1] return 2.
 */
class Solution_41 {
public:
    /**
     * First Missing Positive
     * @param nums
     * @return
     */
    int firstMissingPositive(vector<int> &nums) {
        int n = nums.size();
        for (int i = 0; i < n; ++i)
            while (nums[i] < n && nums[i] > 0 && nums[nums[i] - 1] != nums[i])
                swap(nums[i], nums[nums[i] - 1]);
        for (int i = 0; i < n; ++i)
            if (nums[i] != i + 1)
                return i + 1;
        return n + 1;
    }
};