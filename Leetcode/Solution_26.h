//
// Created by Maloney on 17-4-24.
//
#include <iostream>
using namespace std;

#include <vector>
#ifndef LEETCODE_SOLUTION_26_H
#define LEETCODE_SOLUTION_26_H

#endif //LEETCODE_SOLUTION_26_H

/**
 * Remove Duplicates from Sorted Array
 */
class Solution_26 {
public:
    int removeDuplicates(vector<int> &nums) {
        if (nums.size() < 2)
            return nums.size();
        int index = 1;
        for (int i = 1; i < nums.size(); ++i)
            if (nums[i] != nums[i - 1])
                nums[index++] = nums[i];
        return index;
    }
};