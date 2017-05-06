//
// Created by Maloney on 17-5-6.
//
#include <iostream>
using namespace std;

#include <vector>

#ifndef LEETCODE_SOLUTION_34_H
#define LEETCODE_SOLUTION_34_H

#endif //LEETCODE_SOLUTION_34_H
/**
 * Given an array of integers sorted in ascending order,
 * find the starting and ending position of a given target value.
 * Your algorithm's runtime complexity must be in the order of O(log n).
 * If the target is not found in the array, return [-1, -1].
 *
 * For example :
 * Given [5, 7, 7, 8, 8, 10] and target value 8,
 * return [3, 4].
 */
class Solution_34 {
public:
    /**
     * Search for a Range
     * @param nums
     * @param target
     * @return
     */
    vector<int> searchRange(vector<int> &nums, int target) {
        int n = nums.size();
        vector<int> rel(2, -1);

        if (n < 1)return rel;

        int l = 0, r = n - 1;
        while (l < r) {
            int mid = (l + r) / 2;
            if (nums[mid] < target)
                l = mid + 1;
            else
                r = mid;
        }
        if (nums[l] != target)
            return rel;
        else
            rel[0] = l;

        r = n - 1;
        while (l < r) {
            int mid = (l + r) / 2 + 1;
            if (nums[mid] > target)
                r = mid - 1;
            else
                l = mid;
        }
        rel[1] = r;
        return rel;
    }
};
