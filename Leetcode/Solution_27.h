//
// Created by Maloney on 17-4-24.
//
#include <iostream>
using namespace std;

#include <vector>
#ifndef LEETCODE_SOLUTION_27_H
#define LEETCODE_SOLUTION_27_H

#endif //LEETCODE_SOLUTION_27_H
/**
 * Remove Element
 */
class Solution {
public:
    /**
     * remove all instances of that value in place and return the new length.
     * @param nums
     * @param val
     * @return
     */
    int removeElement(vector<int> &nums, int val) {
        int index = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != val)
                nums[index++] = nums[i];
        }
        return index;
    }
};