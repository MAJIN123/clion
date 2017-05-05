//
// Created by Maloney on 17-5-5.
//
#include <iostream>
using namespace std;

#include <vector>
#include <algorithm>
#ifndef LEETCODE_SOLUTION_31_H
#define LEETCODE_SOLUTION_31_H

#endif //LEETCODE_SOLUTION_31_H
/**
 *  Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
 *  If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).
 *  The replacement must be in-place, do not allocate extra memory.
 *  Here are some examples.
 *  Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
 *  1,2,3 → 1,3,2
 *  3,2,1 → 1,2,3
 *  1,1,5 → 1,5,1
 */
class Solution_31 {
public:
    /**
     * Next Permutation
     * @param nums
     */
    void nextPermutation(vector<int> &nums) {
        int k = -1;
        //1:find the largest index k such that nums[k]<nums[k+1]
        for (int i = nums.size() - 2; i >= 0; --i)
            if (nums[i] < nums[i + 1]) {
                k = i;
                break;
            }
        if (k < 0) {
            reverse(nums.begin(), nums.end());
            return;
        }
        //2:find the largest index l such that nums[l]>nums[k]
        int l = -1;
        for (int i = nums.size() - 1; i > k; --i)
            if (nums[i] > nums[k]) {
                l = i;
                break;
            }
        swap(nums[k], nums[l]);
        reverse(nums.begin() + k + 1, nums.end());
    }
};