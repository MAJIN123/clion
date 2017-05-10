//
// Created by Maloney on 17-5-10.
//
#include <iostream>
using namespace std;

#include <algorithm>
#include <vector>
#ifndef LEETCODE_SOLUTION_42_H
#define LEETCODE_SOLUTION_42_H

#endif //LEETCODE_SOLUTION_42_H
/**
 * Given n non-negative integers representing an elevation map where the width of each bar is 1,
 * compute how much water it is able to trap after raining.
 */
class Solution_42 {
public:
    /**
     * Trapping Rain Water
     * @param height
     * @return
     */
    int trap(vector<int> &height) {
        int l = 0, r = height.size() - 1;
        int res = 0;
        int maxl = 0, maxr = 0;
        while (l <= r) {
            if (height[l] <= height[r]) {
                if (height[l] >= maxl)maxl = height[l];
                else res += maxl - height[l];
                ++l;
            } else {
                if (height[r] >= maxr)maxr = height[r];
                else res += maxr - height[r];
                --r;
            }
        }
        return res;
    }
};